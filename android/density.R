library("ggplot2")

# CONFIG
base.folder = "./data/"
#noise = 25
voltage = 5.03
save.density = FALSE
save.power = FALSE
save.peaks = FALSE
#

data.sources <- list.files(base.folder,pattern = "current_.*\\.txt",full.names = F)
syscall <- sub("current_", "",sub("\\.txt$","",data.sources))

#data.sources <- list.files(base.folder,pattern = "apk_.*\\.txt",full.names = F)
#syscall <- sub("apk_", "",sub("\\.txt$","",data.sources))

if(save.peaks){
  out.filename = paste0(base.folder,"power_density_peaks_values.txt")
  file.create(file = out.filename)
}

dp = list()
for(i in 1:length(data.sources)){
  print(syscall[[i]])
  #if(i==7)
  #  next
  data <- read.delim2(paste0(base.folder,data.sources[i]), header = FALSE, skip = 7)
  names(data)="I"
  
  ## compute the power
  data$P <- with(data, I*voltage )
  
  ## extract the power
  dp[[i]] <- extract.power(data, adjust = 5.5, marker.tolerance = 0.02, intermediate = FALSE)
  #print(dp[[i]]$peaks)
  
  
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
    #for(j in 1:length(dens$peaks)){
    #  rp <- rp + annotate("segment", x=0,xend=length(data$P),y=dens$x[dens$peaks[j]],yend=dens$x[dens$peaks[j]], color="green",linewidth=2)
    #}
    #rp <- rp + annotate("segment", x=0,xend=length(data$P),y=discr.power,yend=discr.power, color="red",linewidth=2)
    rp <- rp + xlab("Sample")
    rp <- rp + ggtitle(syscall[i])
    for(j in 1:length(dp[[i]]$markers$start)){
      rp <- rp + annotate("rect", xmin=dp[[i]]$markers$start[j], xmax=dp[[i]]$markers$end[j],
                          ymin=0, ymax=max(data$P), alpha=.1, fill="red")
    }
    for(j in 1:length(dp[[i]]$work$start)){
      rp <- rp + annotate("rect", xmin=dp[[i]]$work$start[j], xmax=dp[[i]]$work$end[j],
                          ymin=0, ymax=max(data$P), alpha=.1, fill="green")
    }
  
    ggsave(paste0(base.folder,"plot/power_",syscall[i],".png"), width = 25, plot = rp, limitsize = FALSE)
  }
}