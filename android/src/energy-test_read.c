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

#define SIZE 4096

void busy(int dur){
	struct timeval end, now;

	gettimeofday(&end,NULL);
	end.tv_sec += dur;
	do{
		gettimeofday(&now,NULL);
	}while(timercmp(&now, &end, <));
}

int main(int argc, char * argv[]){
	const char * fn = "/sdcard/test/hello.txt";
	char content[SIZE]; // 4KB content line
	int fd, i, len;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);

	// Open file
	fd = open(fn, O_RDONLY);

	if(fd >= 0){
		busy(len);
		sleep(len);
		for(i=0; i<12800; i++)	// 50MB file size
			read(fd, content, SIZE);
		// Close file
		sleep(len);
		busy(len);
		close(fd);
	}else{
		printf("fopen() FAILED");
		return 1;
	}
	return 0;
}
