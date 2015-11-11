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

void marker(int len){
	sleep(len);
	busy(len);
	sleep(len);
}
