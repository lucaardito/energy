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

int main(int argc, char * argv[]){
  int i, len;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);

	busy(len);
	sleep(len);

  if (prctl(PR_GET_TIMING, NULL, NULL, NULL, NULL) == -1)
    printf("TIOCGETD failed: %s\n", strerror(errno));
  else {
		for(i=0; i<12999; i++)
		 	prctl(PR_GET_TIMING, NULL, NULL, NULL, NULL);
  }

	sleep(len);
	busy(len);
	return(0);
}
