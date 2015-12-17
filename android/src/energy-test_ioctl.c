#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include "energy-utils.h"

int main(int argc, char * argv[]){
	int fd, status;
	long i, len, j;
	struct timeval end, start, time_len, total_time;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);
	//total_time.tv_sec = 0;
	//total_time.tv_usec = 0;
	fd = open("/dev/tty", O_RDONLY);

	for(j=0; j<30; j++){
		marker(len);
		//gettimeofday(&start,NULL);	// Execution time begin
		if (ioctl(fd, TIOCGETD, &status) == -1)
			printf("TIOCGETD failed: %s\n", strerror(errno));
		else {
			for(i=1; i<3000000; i++)
				ioctl(fd, TIOCGETD, &status);
		}
		//gettimeofday(&end,NULL);	// Execution time end
		//timersub(&end,&start,&time_len);	// Execution time
		//printf("Run %2d - %d:%06d\n", j, time_len.tv_sec, time_len.tv_usec);
		//timeradd(&total_time,&time_len,&total_time);
	}
	//printf("Total: %d:%06d\n", total_time.tv_sec, total_time.tv_usec);
	marker(len);
	close(fd);
	return(0);
}
