#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
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

void head(int len){
	sleep(len);
	busy(len);
	sleep(len);
}

void tail(int len){
	return;
}

int main(int argc, char * argv[]){
	long len, i;
	const char * fn = "/sdcard/test/hello.txt";
	void *map;
	int fd;
	struct timeval dummy;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}

	len=atoi(argv[1]);
	fd = open(fn, O_RDONLY);

	head(len);

	for(i=0;i<150000;i++){
		map = mmap(NULL, 1, PROT_READ, MAP_PRIVATE, fd, 0);
		munmap(map, 1);
	}

	tail(len);
	return 0;
}
