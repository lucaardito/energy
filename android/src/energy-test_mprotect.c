#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
#include "energy-utils.h"

#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

char *buffer;

static void handler(int sig, siginfo_t *si, void *unused){
	printf("Got SIGSEGV at address: 0x%lx\n", (long) si->si_addr);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
	int pagesize, j;
	long i, len;
	struct sigaction sa;
	struct timeval end, start, time_len, total_time;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);
	//total_time.tv_sec = 0;
	//total_time.tv_usec = 0;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	if (sigaction(SIGSEGV, &sa, NULL) == -1)
		handle_error("sigaction");

	pagesize = sysconf(_SC_PAGE_SIZE);
	if (pagesize == -1)
		handle_error("sysconf");

	/* Allocate a buffer aligned on a page boundary;
	initial protection is PROT_READ | PROT_WRITE */

	buffer = memalign(pagesize, 4 * pagesize);
	if (buffer == NULL)
		handle_error("memalign");

	if (mprotect(buffer + pagesize * 2, pagesize, PROT_READ) == -1)
		handle_error("mprotect");

	for(j=0; j<30; j++){
		marker(len);
		//gettimeofday(&start,NULL);	// Execution time begin
		for(i=0; i<3000000; i++)
			mprotect(buffer + pagesize * 2, pagesize, PROT_READ);
		//gettimeofday(&end,NULL);	// Execution time end
		//timersub(&end,&start,&time_len);	// Execution time
		//printf("Run %2d - %d:%06d\n", j, time_len.tv_sec, time_len.tv_usec);
		//timeradd(&total_time,&time_len,&total_time);
	}
	//printf("Total: %d:%06d\n", total_time.tv_sec, total_time.tv_usec);
	marker(len);
	exit(EXIT_SUCCESS);
}
