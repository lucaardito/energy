#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
#include "energy-utils.h"

int main(int argc, char * argv[]){
	long len, i, j;
	const char * fn = "/sdcard/test/hello.txt";
	void *map;
	int fd;
	struct timeval end, start, time_len, total_time;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}

	len=atoi(argv[1]);
	fd = open(fn, O_RDONLY);
	total_time.tv_sec = 0;
	total_time.tv_usec = 0;
	for(j=0; j<30; j++){
		marker(len);
		gettimeofday(&start,NULL);	// Execution time begin
		for(i=0;i<1500000;i++){
			map = mmap(NULL, 1, PROT_READ, MAP_PRIVATE, fd, 0);
			munmap(map, 1);
		}
		gettimeofday(&end,NULL);	// Execution time end
		timersub(&end,&start,&time_len);	// Execution time
		printf("Run %2d - %d:%06d\n", j, time_len.tv_sec, time_len.tv_usec);
		timeradd(&total_time,&time_len,&total_time);
	}
	printf("Total: %d:%06d\n", total_time.tv_sec, total_time.tv_usec);
	marker(len);
	return 0;
}
