#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
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
	int len;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len = atoi(argv[1]);
	busy(len);
	return 0;
}
