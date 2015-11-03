#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include <time.h>
#include <sys/time.h>

/*void busy(int dur){
	int end = time(NULL) + dur;
	while(end > time(NULL));
}*/

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
	long i, len;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);

	head(len);
	for(i=0; i<300000; i++)
		getuid();
	tail(len);
	return 0;
}
