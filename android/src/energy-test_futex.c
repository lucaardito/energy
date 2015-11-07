/*
 * Source inspired by: http://www.programminglogic.com/basic-multithread-programming-and-synchronization-futex-semaphores-mutex-etc/
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <linux/futex.h>
#include <sys/syscall.h>
#include <sys/linux-syscalls.h>

//#define NUM 5
#define TIMEOUT 10

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

int futex_wait(void* addr, int val1, struct timespec *tout){
	return syscall(__NR_futex, addr, 0, val1, tout, NULL, 0);
}

int futex_wake(void* addr, int n){
	return syscall(__NR_futex, addr, 0, FUTEX_WAKE, n, NULL, NULL, 0);
}

/*
void* thread_f(void* par){
	int* futex_addr = (int *) par;
	struct timespec tout;
	futex_wait(&futex_addr, 0, TIMEOUT);
	printf("Thread %d starting to work!\n", id);
	return NULL;
}
*/

int main(int argc, char *argv[]){
	//pthread_t threads[NUM];
	int i;
	int futex_addr, len;
	struct timespec tout;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}

	len=atoi(argv[1]);

	futex_addr = 0;
	tout.tv_sec=TIMEOUT;
	tout.tv_nsec=0;

	/*
	for (i=0;i<NUM;i++)
		pthread_create(&threads[i], NULL, thread_f, (void *)&futex_addr);
	*/

	for(i=0; i<31; i++){
		head(len);

		futex_wait(&futex_addr, 0, &tout);

		tail(len);
	}
	/*wake threads
	futex_wake(&futex_addr, NUM);
	*/
	return 0;
}
