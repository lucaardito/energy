/*
 * Source inspired by: http://xmailserver.org/epoll_pwait_test.c
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include "energy-utils.h"

int main(int argc, char *argv[]) {
	long len;
	int fd[2], error, epfd, j;
	struct epoll_event evt;
	struct timeval end, start, time_len, total_time;

	if(argc != 2){
		printf("Please specify busy lenght\n");
		exit(1);
	}
	if ((epfd = epoll_create(1)) == -1) {
		perror("epoll_create(1)");
		return 1;
	}
	if (pipe(fd) < 0) {
		printf("pipe() error\n");
		exit(1);
	}

	len=atoi(argv[1]);
	total_time.tv_sec = 0;
	total_time.tv_usec = 0;
	// Creating the event
	memset(&evt, 0, sizeof(evt));
	evt.events = EPOLLIN;
	// Binding the event with the pipe
	if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd[0], &evt) < 0) {
		perror("epoll_ctl(EPOLL_CTL_ADD)");
		return 1;
	}

	for(j=0; j<30; j++){
		marker(len);
		gettimeofday(&start,NULL);	// Execution time begin
		error = epoll_wait(epfd, &evt, 1, 10000); // Waiting 1 event for 10 seconds
		/*
		if (error != -1)
			fprintf(stdout, "FAIL (%d returned instead of -1)\n", error);
		else if (errno != EINVAL)
			fprintf(stdout, "FAIL (errno is %d instead of EINVAL)\n", errno);
		else
			fprintf(stdout, "OK\n");
		*/
		gettimeofday(&end,NULL);	// Execution time end
		timersub(&end,&start,&time_len);	// Execution time
		printf("Run %2d - %d:%06d\n", j, time_len.tv_sec, time_len.tv_usec);
		timeradd(&total_time,&time_len,&total_time);
	}
	printf("Total: %d:%06d\n", total_time.tv_sec, total_time.tv_usec);
	marker(len);
	return(0);
}
