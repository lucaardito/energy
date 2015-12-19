library("ggplot2")

# CONFIG
base.folder = "./data/"
#noise = 25
voltage = 5.03
save.power = TRUE
source.type = 1
#

if(source.type == 0){ # SYSCALL
  data.sources <- list.files(base.folder,pattern = "syscall_.*\\.txt",full.names = F)
  syscall <- sub("syscall_", "",sub("\\.txt$","",data.sources))
}else if(source.type==1){ # APPLICATIONS
  data.sources <- list.files(base.folder,pattern = "current_.*\\.txt",full.names = F)
  syscall <- sub("current_", "",sub("\\.txt$","",data.sources))
}

#data.sources <- list.files(base.folder,pattern = "apk_.*\\.txt",full.names = F)
#syscall <- sub("apk_", "",sub("\\.txt$","",data.sources))

dp <- list()
for(i in 1:length(data.sources)){
  noise = -1
  data <- read.delim2(paste0(base.folder,data.sources[i]), header = FALSE, skip = 7)
  names(data)="I"
  
  ## compute the power
  data$P <- with(data, I*voltage )
  
  # custom noise for webimage_2, automatic detection is insufficient
  if(source.type==1 && i==6)
    noise=50
  
  ## extract the power
  adj = 1.5
  #print(syscall[[i]])
  for(j in 1:16){
    dp[[i]] <- extract.power(data, adjust = adj, marker.tolerance = 0.02, intermediate = FALSE, noise.force = noise)
    dp[[i]]$name <- syscall[[i]]
    dp[[i]]$adjust <- adj
    # check output parameters
    if(is.null(dp[[i]]$work) || length(dp[[i]]$work$length) != 30){
      adj <- adj + 0.5
      next
    }else{
      break
    }
  }
  if(is.null(dp[[i]]$work) || length(dp[[i]]$work$length) != 30){
    warning("Error in processing ", syscall[[i]], "(). Please review the data manually.
            This can be caused by an incorrent energy level for the marker or a wrong noise length")
    #next
  }
  
  if(save.power){
    rp <- ggplot(data,aes(x=seq_along(data$P),y=P))
    #rp <- rp + geom_line(size=.5)
    rp <- rp + geom_point(size=.5)
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