library("ggplot2")

# CONFIG
base.folder = "./data/"
noise = 25
save.density = FALSE
save.power = TRUE
save.peaks = FALSE
#

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

data.sources <- list.files(base.folder,pattern = "syscall_.*\\.txt",full.names = F)
syscall <- sub("syscall_", "",sub("\\.txt$","",data.sources))

if(save.peaks){
  out.filename = paste0(base.folder,"power_density_peaks_values.txt")
  file.create(file = out.filename)
}

for(i in 1:length(data.sources)){
  data <- read.delim2(paste0(base.folder,data.sources[i]), header = FALSE, skip = 7)
  data$P <- data$V1*5.03
  dens <- density(data$P,adjust=2)
  dens$peaks <- peaks(dens$y,9) & dens$y > mean(dens$y)

  dens$peaks <- which(peaks(dens$y) & dens$y>mean(dens$y))
  between.peaks <- seq(dens$peaks[2],dens$peaks[3])
  gap <- intersect(which(dens$y==min(dens$y[between.peaks])),between.peaks)
  
  idle.power <- dens$x[dens$peaks[1]]
  #discr.power = mean(dens$x[gap])
  discr.power <- dens$x[gap] # + (dens$x[dens$peaks[3]]-dens$x[dens$peaks[2]])/5
  dens.gap <- data.frame(dens[c("x","y")])[gap,]
  
  ## tag as IDLE or WORK based on discr.power threshold
  tag.levels <- c("IDLE","WORK","PAUSE","NOISE","DATA","MARKER")
  data$tag <- factor(tag.levels[findInterval(data$P,c(0,discr.power))],tag.levels)
  
  ## assign unique id to runs
  data$runid <- cumsum(c(1,abs(diff(as.numeric(data$tag))) ) )
  
  ## mark runs with few (<=noise) samples as NOISE
  id.noise <- unique(data$runid)[table(data$runid)<=noise]
  data$tag[data$runid%in%id.noise] = "NOISE"
  
  ## merge consecutive noise runs into one
  data$runid <- cumsum(c(1,abs(diff(as.numeric(data$tag))) ) )
  
  ## assign consecutive runids
  data$runid <- cumsum(c(1,abs(diff(data$runid)) )!=0 )
  
  ## update noise id
  id.noise <- unique(data$runid[data$tag=="NOISE"])
  
  ## first runid always marked as IDLE, not NOISE
  data$tag[data$runid==1] = "IDLE"
  if(id.noise[1]==1){
    id.noise <- subset(id.noise!=1)
  }
  
  ## mark NOISE runid with preceding runid tag
  for(j in id.noise){
    data$tag[data$runid==j] = unique(data$tag[data$runid==j-1])
  }
  
  ## merge consecutive runs into one
  data$runid = cumsum(c(1,abs(diff(as.numeric(data$tag))) ) )
  data$runid = cumsum(c(1,abs(diff(data$runid)) )!=0 )
  
  ## find energy markers
  id.markers <- unique(data$runid)[table(data$runid)>=4900 & table(data$runid)<=5100] # ~ length of the marker
  data$tag[(data$runid %in% id.markers) & (data$tag=="WORK")] = "MARKER"
  id.markers <- unique(data$runid[data$tag=="MARKER"])
  
  ## check consistency of markers
  print(paste(syscall[i], as.character(length(id.markers))))
  # TODO: exclude data if lenght between markers is significantly different
  
  ## mark data between two valid markers
  for(j in 1:(length(id.markers)-1)){
    for(k in (id.markers[j]+1):(id.markers[j+1]-1)){
      # TODO: do not mark if data should be excluded
      data$tag[data$runid==k] = "DATA"
    }
  }
  
  ## reassign consecutive runids based on new tag
  data$runid = cumsum(c(1,abs(diff(as.numeric(data$tag))) ) )
  data$runid = cumsum(c(1,abs(diff(data$runid)) )!=0 )
  
  # set DATA runid
  id.data <- unique(data$runid[data$tag=="DATA"])
  
  # tag first and last 5000 samples fo each DATA as IDLE
  #for(j in id.data){
  #  data$tag[data$runid==j & ]
  #}
  
  # update id
  id.markers <- unique(data$runid[data$tag=="MARKER"])
  id.noise <- unique(data$runid[data$tag=="NOISE"])
  id.data <- unique(data$runid[data$tag=="DATA"])
  
  # Take sets between two consecutive marker and extract data
  if(save.peaks){
    write(paste0(syscall[i], ": ", dens$x[dens$peaks]), file = out.filename, append = TRUE)
  }
  
  if(save.density){
    p <- ggplot(data,aes(x=P))
    p <- p + geom_line(stat="density",adjust=2) + expand_limits(y=0)
    p <- p + geom_line(data=dens.gap,aes(x=x,y=y),color="red")
    p <- p + geom_point(data=data.frame(x=dens$x,y=dens$y)[dens$peaks,],aes(x=x,y=y),col="red",size=5, pch=1)
    #p <- p + annotate("rect", xmin=min(dens$x), xmax=gap.min, ymin=0, ymax=max(dens$y), alpha=.1,
    #                  fill="blue")
    #p <- p + annotate("rect", xmax=max(dens$x), xmin=gap.max, ymin=0, ymax=max(dens$y), alpha=.1,
    #                  fill="green")
    p <- p + annotate("segment", x=discr.power,xend=discr.power,y=0,yend=max(dens$y), color="red",linewidth=2)
    
    p <- p + xlab("Power [w]")
    p <- p + ggtitle(syscall[i])
    
    ggsave(paste0(base.folder,"plot/density_",syscall[i],".png"), plot = p)
  }
  
  if(save.power){
    rp <- ggplot(data,aes(x=seq_along(data$P),y=P))
    #rp <- rp + geom_line(size=.5)
    rp <- rp + geom_point(size=.5)
    for(j in 1:length(dens$peaks)){
      rp <- rp + annotate("segment", x=0,xend=length(data$P),y=dens$x[dens$peaks[j]],yend=dens$x[dens$peaks[j]], color="green",linewidth=2)
    }
    rp <- rp + annotate("segment", x=0,xend=length(data$P),y=discr.power,yend=discr.power, color="red",linewidth=2)
    rp <- rp + xlab("Sample")
    rp <- rp + ggtitle(syscall[i])
    for(j in id.markers){
      rp <- rp + annotate("rect", xmin=min(which(data$runid==j)), xmax=max(which(data$runid==j)),
                          ymin=0, ymax=max(data$P), alpha=.1, fill="red")
    }
    for(j in id.data){
      rp <- rp + annotate("rect", xmin=min(which(data$runid==j)), xmax=max(which(data$runid==j)),
                          ymin=0, ymax=max(data$P), alpha=.1, fill="green")
    }
  
    ggsave(paste0(base.folder,"plot/power_",syscall[i],".png"), plot = rp, limitsize = FALSE)
  }
}