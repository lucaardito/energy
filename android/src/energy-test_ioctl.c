#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/time.h>


void busy(int dur){
	struct timeval end, now;

	gettimeofday(&end,NULL);
	end.tv_sec += dur;
	do{
		gettimeofday(&now,NULL);
	}while(timercmp(&now, &end, <));
}

void head(int len){
	sleep(len);
	busy(len);
	sleep(len);
}

void tail(int len){
	return;
}

int main(int argc, char * argv[]){
	int fd, status, i, len;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);

	fd = open("/dev/tty", O_RDONLY);

	head(len);

	if (ioctl(fd, TIOCGETD, &status) == -1)
		printf("TIOCGETD failed: %s\n", strerror(errno));
	else {
		for(i=0; i<12999; i++)
		 	ioctl(fd, TIOCGETD, &status);
	}

	tail(len);

	close(fd);
	return(0);
}
