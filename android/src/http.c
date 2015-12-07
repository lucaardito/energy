#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 2048

int socket_connect(char *host, int port){
	struct hostent *hp;
	struct sockaddr_in addr;
	int on = 1, sock;

	if((hp = gethostbyname(host)) == NULL){
		herror("gethostbyname");
		exit(1);
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));

	if(sock == -1){
		perror("setsockopt");
		exit(1);
	}

	if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("connect");
		exit(1);

	}
	return sock;
}

int main(int argc, char *argv[]){
	int fd;//, fp;
	char buffer[BUFFER_SIZE + 1];
	size_t n;

	if(argc < 4){
		fprintf(stderr, "Usage: %s <hostname> <port> <resource>\n", argv[0]);
		exit(1);
	}

	fd = socket_connect(argv[1], atoi(argv[2]));
	//fp = open("http.png", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);

	/// Form request
	snprintf(buffer, BUFFER_SIZE,
		"GET %s HTTP/1.0\r\n"	// POST or GET, both tested and works. Both HTTP 1.0 HTTP 1.1 works, but sometimes
		"Host: %s\r\n"				// but sometimes HTTP 1.0 works better in localhost type
		//"Content-type: application/x-www-form-urlencoded\r\n"
		"Content-length: 0\r\n\r\n", argv[3], argv[1]
	);

	/// Write the request
	if (write(fd, buffer, strlen(buffer))>= 0){
		bzero(buffer, BUFFER_SIZE);

		// Reading headers
		read(fd, buffer, BUFFER_SIZE - 1);
		//printf("%s", buffer);
		// Reading image
		while((n = read(fd, buffer, BUFFER_SIZE - 1)) != 0){
			//write(fp, buffer, n);
			//bzero(buffer, BUFFER_SIZE);
		}
	}
	shutdown(fd, SHUT_RDWR);
	close(fd);
	//close(fp);
	return 0;
}
