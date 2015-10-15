#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
//#include <time.h>

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

int main(int argc, char * argv[]){
	long len, i;
	struct timeval dummy;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}

	len=atoi(argv[1]);
	busy(len);
	sleep(len);

	for(i=0;i<30000;i++)
		gettimeofday(&dummy, NULL);

	sleep(len);
	busy(len);
	return 0;
}
