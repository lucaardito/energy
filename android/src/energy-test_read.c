#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include "energy-utils.h"

#define SIZE 4096

int main(int argc, char * argv[]){
	const char * fn = "/sdcard/test/hello.txt";
	char content[SIZE]; // 4KB content line
	int fd, i, len, j;
	struct timeval end, start, time_len, total_time;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);
	//total_time.tv_sec = 0;
	//total_time.tv_usec = 0;
	for(j=0; j<30; j++){
		// Open file
		fd = open(fn, O_RDONLY);

		if(fd >= 0){
			marker(len);
			//gettimeofday(&start,NULL);	// Execution time begin
			for(i=0; i<12800; i++)	// 50MB file size
				read(fd, content, SIZE);
			// Close file
			//gettimeofday(&end,NULL);	// Execution time end
			//timersub(&end,&start,&time_len);	// Execution time
			//printf("Run %2d - %d:%06d\n", j, time_len.tv_sec, time_len.tv_usec);
			//timeradd(&total_time,&time_len,&total_time);
			close(fd);
		}else{
			printf("fopen() FAILED");
			return 1;
		}
	}
	//printf("Total: %d:%06d\n", total_time.tv_sec, total_time.tv_usec);
	marker(len);
	return 0;
}
