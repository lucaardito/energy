## Utility functions
library("reshape2")
library("plyr")

##########################################################################
## code by Martin Maechler <maechler at stat.math.ethz.ch>
## found on https://stat.ethz.ch/pipermail/r-help/2005-November/083376.html
peaks <- function(series, span = 3, do.pad = TRUE) {
  if((span <- as.integer(span)) %% 2 != 1) stop("'span' must be odd")
  s1 <- 1:1 + (s <- span %/% 2)
  if(span == 1) return(rep.int(TRUE, length(series)))
  z <- embed(series, span)
  v <- apply(z[,s1] > z[, -s1, drop=FALSE], 1, all)
  if(do.pad) {
    pad <- rep.int(FALSE, s)
    c(pad, v, pad)
  } else v
}
##########################################################################

##################################################################
outliers <- function(x,iqm=4,index=F,logic=F){
  qs = quantile(x,c(.25,.5,.75))
  iqr = abs(qs[1]-qs[3])
  
  l = x < qs[2]-iqm*iqr | x > qs[2]+iqm*iqr
  if(logic){
    return( l )
  }
  if(index){
    return(which(l))
  }
  x[l]
}

######################################################################################
#
# Computes the average power for the working tasks in a series of measures.
#
# The computation assumes the execution follows a well defined protocol
# to mark tasks begin and end. A typical profile is:
#
#       --------      --v-^v^--
#       |      |      |       |
#       |      |      |       |
# -------      --------       -....
#  SLEEP: WAIT :SLEEP : WORK  :   
#
#  SLEEP : is a period of sleep for a given (marker.length) time
#  WAIT  : is a period of busy waiting for a given (marker.length) time
#  WORK : is a period of actual work (the one we aim to measure the energy consumption of)
#
# Parameters:
# ----------
# data: time series with power measures in the variable "P"
# adjust: parameter to identify levels in the input
# N: expected number of task repetition
# marker.length : length of task begin marker in samples
# marker.tolerance : percentage of tolerance for markers, used to match the markers
#
# Return:
# ------
# A list containing the following elements:
#
# - work: a dataset, rows represent the work periods, for each period we report 
#   start, end, lenght and P
#
# - baseline : the baseline power considered the idle level
#
# - nois: the estimated length of noise runs
#
extract.power <- function(data, adjust=1.5, N=30, marker.length=5000, marker.tolerance=0.1, intermediate=FALSE){
  if(! "P" %in% names(data)){
     stop("data must have a 'P' column" )
  }
  result = list()
  # Density analysis
  # ----------------
  ## Distribution density of values
  dens <- density(data$P,adjust=adjust)
  
  ## Find peaks in the distribution (the most common power levels)
  dens$peaks <- which(peaks(dens$y) & dens$y>mean(dens$y))
  
  ## Identify thresholds between peaks as the points of minimum density between peaks
  thresholds = dens$x[apply(cbind(head(dens$peaks,-1),tail(dens$peaks,-1)),1,function(x){
    ss = dens$y[x[1]:x[2]]
    x[1] + which(ss == min(ss))
  })]
  
  baseline=dens$x[dens$peaks[1]]
  result$baseline = dens$x[dens$peaks[1]]
  
  #if(intermediate){
    result$peaks = dens$x[dens$peaks]
    result$thresholds = thresholds
  #}
  
  # Tagging
  #---------
  ## tag levels are those corresponding to peaks plus a special NOISE tag
  tag.levels <- paste0("L",seq(dens$peaks))
  data$tag <- factor(tag.levels[findInterval(data$P,c(0,thresholds))],c(tag.levels,"NOISE"))
  
  ## assign unique id to runs
  data$runid <- cumsum(c(1,abs(diff(as.numeric(data$tag))!=0) ) )
  
  ## build run summary table
  id.tab = subset(melt(with(data,table(tag,runid)),id.vars="runid",value.name="length"),length!=0)
  id.tab$start=cumsum(c(1,head(id.tab$length,-1)))
  id.tab$end=cumsum(id.tab$length)
  
  # Remove noise
  #--------------
  dens.noise = density(id.tab$length)
  dens.noise$peaks <- which(peaks(dens.noise$y) & dens.noise$y>mean(dens.noise$y))
  
  ## Identify thresholds between peaks as the points of minimum density between peaks
  thresholds = dens.noise$x[apply(cbind(head(dens.noise$peaks,-1),tail(dens.noise$peaks,-1)),1,function(x){
    ss = dens$y[x[1]:x[2]]
    x[1] + which(ss == min(ss))
  })]
  noise=thresholds[1]
  #if(noise<70)
  noise=70
  result$noise = noise
  ## identify noise runs by means of a run length threshold
  id.tab$tag[id.tab$length<noise] = "NOISE"
  
  ## Remove noise
  if(id.tab$tag[1]=="NOISE"){
    id.tab$tag[1] = id.tab$tag[min(id.tab$runid[id.tab$tag!="NOISE"])]
  }
  id.noise = which(id.tab$tag=="NOISE")
  while(length(id.noise)>0){
    ##  assign the noise run the same level as the  the preceding run
    id.tab$tag[id.noise] = id.tab$tag[id.noise-1]
    id.noise = which(id.tab$tag=="NOISE")
  }
  
  ## Merge consecutive runs havin the same tag
  ## a) recompute the run id
  id.tab$runid = cumsum(c(1,abs(diff(as.numeric(id.tab$tag))!=0) ) )
  ## b) merge all the fragments with the same runid
  id.tab = ddply(id.tab,.(runid,tag),summarize,
                 length = sum(length),
                 start = min(start),
                 end = max(end)
  )
  if(intermediate){
    result$id.tab = id.tab
  }
  
  # Identify markers
  #------------------
  l.min = marker.length*(1-marker.tolerance)
  l.max = marker.length*(1+marker.tolerance)
  markers = subset(id.tab,length>=l.min & length<=l.max)
  mark.sum = ddply(markers,.(tag),summarize,
                   n=length(tag),
                   length = median(length),
                   t= median(diff(start)),
                   #        tv = sd(diff(start))
                   #        tv = 2*diff(quantile(diff(start),c(.25,.75)))
                   tv = median(diff(start))*.02#.1
  )
  mark.sum$score = dim(mark.sum)[1]*(rank(abs(mark.sum$n-N))-1)+rank(mark.sum$tv)-1
  marker = subset(mark.sum,(tag==max(tag.levels))) # score==min(score))
  marker.tag = marker$tag
  
  potential.markers = subset(id.tab,tag==marker$tag)
  
  selected.markers = c()
  initial.markers = subset(markers,tag==marker$tag)
  #print(initial.markers$runid)
  generation = 0
  while(!is.null(initial.markers)){
    generation <- generation + 1
    if(generation > 2) break
    new.markers=c()
    for(id in initial.markers$runid){
      #cat(id,"\n")
      current.marker = subset(potential.markers,runid==id)
      t.expected = current.marker$start + marker$t
      t.lower = t.expected - marker$tv
      t.upper = t.expected + marker$tv
      
      successor = subset(potential.markers,start>=t.lower & start<=t.upper & length>marker.length/2)
      if(dim(successor)[1]>0){
        if(dim(successor)[1]>1){
          successor <- subset(successor,abs(length-marker.length)==min(abs(length-marker.length)))
          #stop("No strategy to prioritize defined yet!!")
        }
        if(! successor$runid%in%selected.markers$runid){
          new.markers <- rbind(new.markers,successor)
        }
      }
      
      t.expected = current.marker$start - marker$t
      t.lower = t.expected - marker$tv
      t.upper = t.expected + marker$tv
      predecessor = subset(potential.markers,start>=t.lower & start<=t.upper& length>marker.length/2)
      if(dim(predecessor)[1]>0){
        if(dim(predecessor)[1]>1){
          predecessor <- subset(predecessor,abs(length-marker.length)==min(abs(length-marker.length)))
        }
        if(! predecessor$runid%in%selected.markers$runid){
          new.markers <- rbind(new.markers,predecessor)
        }
      }
    }
    new.markers = unique(new.markers)
    initial.markers=new.markers
    if(!is.null(new.markers)){
      #print(new.markers$runid)
      
      new.markers$Gen = generation
      selected.markers=rbind(selected.markers,new.markers)
    }
  }
  selected.markers <- unique(selected.markers)
  selected.markers <- selected.markers[order(selected.markers$runid),]
  
  #if(intermediate){
    result$markers = selected.markers
  #}
  
  # Identify work
  #---------------
  work.run = data.frame(
    start = head(selected.markers,-1)$start+2*marker.length,
    end = tail(selected.markers,-1)$start-marker.length
  )
  work.run <- within(work.run,
                     length <- end-start+1
  )
  #work.run = ddply(work.run,.(start),transform,P = mean(data[start:end,]$P)-result$baseline)
  work.run$P <- apply(work.run,1,function(x) 
                      mean(data[x["start"]:x["end"],]$P)-baseline)
  result$work = work.run
  
  return( result )
}
