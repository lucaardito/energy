base.folder = "./git/energy/android/data/"
data.sources <- list.files(base.folder,pattern = "syscall_.*\\.txt",full.names = F)
syscall = sub("syscall_", "",sub("\\.txt$","",data.sources))

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
out.filename = paste0(base.folder,"/power_values.txt")
file.create(file = out.filename)
for(i in 1:length(data.sources)){
  data <- read.delim2(paste0(base.folder,data.sources[i]), header = FALSE, skip = 7)
  data$V1 <- data$V1*5.03
  dens = density(data$V1,adjust=.2)
  dens$peaks = peaks(dens$y,9) & dens$y > mean(dens$y)
  
  dens.gap = subset(data.frame(dens[c("x","y")]),y==min(dens$y))
  gap.min = min(dens.gap$x)
  gap.max = max(dens.gap$x)
  idle.power = dens$x[dens$y==max(dens$y)]
  discr.power = mean(dens.gap$x)
  dens$peaks = which(peaks(dens$y) & dens$y>mean(dens$y))
  between.peaks = seq(dens$peaks[1],dens$peaks[2])
  gap = intersect(which(dens$y==min(dens$y[between.peaks])),between.peaks)

  gap.min = min(dens$x[gap])
  gap.max = max(dens$x[gap])
  
  idle.power = dens$x[dens$peaks[1]]
  discr.power = mean(dens$x[gap])
  #work.power = dens$x[dens$peaks[length(dens$peaks)]]
  
  write(paste0(syscall[i],": ",dens$x[dens$peaks[1:length(dens$peaks)]]),
        file = out.filename,
        append = TRUE)
  
  dens.gap = data.frame(dens[c("x","y")])[gap,]
  
  p <- ggplot(data,aes(x=V1))
  p <- p + geom_line(stat="density",adjust=.2) + expand_limits(y=0)
  p <- p + geom_line(data=dens.gap,aes(x=x,y=y),color="red")
  p <- p + geom_point(data=data.frame(x=dens$x,y=dens$y)[dens$peaks,],aes(x=x,y=y),col="red",size=5, pch=1)
  #p <- p + annotate("rect", xmin=min(dens$x), xmax=gap.min, ymin=0, ymax=max(dens$y), alpha=.1,
  #                  fill="blue")
  #p <- p + annotate("rect", xmax=max(dens$x), xmin=gap.max, ymin=0, ymax=max(dens$y), alpha=.1,
  #                  fill="green")
  p <- p + annotate("segment", x=discr.power,xend=discr.power,y=0,yend=max(dens$y), color="red",linewidth=2)
  
  p <- p + xlab("Power [w]")
  p <- p + ggtitle(syscall[i])
  
  p
  ggsave(paste0(base.folder,"plot/density_",syscall[i],".png"))
}