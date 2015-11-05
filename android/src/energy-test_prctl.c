#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/prctl.h>
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
	long i, len, j;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);

	if (prctl(PR_GET_TIMING, NULL, NULL, NULL, NULL) == -1)
		printf("TIOCGETD failed: %s\n", strerror(errno));
	else {
		for(j=0; j<31; j++){
			head(len);
	
			for(i=0; i<3000000; i++)
			 	prctl(PR_GET_TIMING, NULL, NULL, NULL, NULL);
			tail(len);
		}
	}

	return(0);
}
