#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/prctl.h>
#include <sys/time.h>
#include "energy-utils.h"

int main(int argc, char * argv[]){
	long i, len, j;
	struct timeval end, start, time_len, total_time;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);
	//total_time.tv_sec = 0;
	//total_time.tv_usec = 0;
	if (prctl(PR_GET_TIMING, NULL, NULL, NULL, NULL) == -1)
		printf("TIOCGETD failed: %s\n", strerror(errno));
	else {
		for(j=0; j<30; j++){
			marker(len);
			//gettimeofday(&start,NULL);	// Execution time begin
			for(i=0; i<3000000; i++)
				prctl(PR_GET_TIMING, NULL, NULL, NULL, NULL);
			//gettimeofday(&end,NULL);	// Execution time end
			//timersub(&end,&start,&time_len);	// Execution time
			//printf("Run %2d - %d:%06d\n", j, time_len.tv_sec, time_len.tv_usec);
			//timeradd(&total_time,&time_len,&total_time);
		}
		//printf("Total: %d:%06d\n", total_time.tv_sec, total_time.tv_usec);
		marker(len);
	}

	return(0);
}
