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

int main(int argc, char * argv[]){
	int i, len;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);

	busy(len);
	sleep(len);
	for(i=0; i<12800; i++)
		getuid();
	sleep(len);
	busy(len);
	return 0;
}
