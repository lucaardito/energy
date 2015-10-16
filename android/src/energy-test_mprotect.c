#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

char *buffer;

static void handler(int sig, siginfo_t *si, void *unused){
	printf("Got SIGSEGV at address: 0x%lx\n", (long) si->si_addr);
  exit(EXIT_FAILURE);
}

void busy(int dur){
	struct timeval end, now;

	gettimeofday(&end,NULL);
	end.tv_sec += dur;
	do{
		gettimeofday(&now,NULL);
	}while(timercmp(&now, &end, <));
}

int main(int argc, char *argv[]) {
  int pagesize, i, len;
  struct sigaction sa;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	len=atoi(argv[1]);

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

	busy(len);
	sleep(len);

  if (mprotect(buffer + pagesize * 2, pagesize, PROT_READ) == -1)
    handle_error("mprotect");

	for(i=0; i<12999; i++)
		mprotect(buffer + pagesize * 2, pagesize, PROT_READ);

	sleep(len);
	busy(len);

  exit(EXIT_SUCCESS);
}
