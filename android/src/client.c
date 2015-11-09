#include "recvfrom.h"

int main(int argc, char *argv[]){
  struct sockaddr_in si_other;
  int s, i, slen=sizeof(si_other), len, j;
  const char * buf = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum non odio justo. Donec pharetra velit vel tempus vestibulum. Fusce pulvinar quis nunc id rhoncus. Ut sollicitudin bibendum nunc, non facilisis purus tempor at. Sed condimentum quis ante et pharetra. Quisque convallis tristique nisl, eget sollicitudin odio tristique et. In hac habitasse platea dictumst. Aliquam erat volutpat. Donec mattis enim vel neque volutpat, id posuere libero facilisis. Duis rutrum pellentesque pharetra. Suspendisse non tortor quis diam ultricies fringilla. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Fusce nulla quam, elementum sit amet turpis vel, tempus gravida tellus. Sed ac felis vitae felis aliquet vestibulum finibus sit amet est. Donec nec mollis sapien.Fusce aliquet congue risus in commodo. Duis in dapibus justo, in cursus ante. Morbi semper imperdiet varius. Curabitur fringilla rutrum bibendum. Fusce a lectus eleifend, scelerisque sapien at, suscipit ligula. Nullam diam leo, cursus non tincidunt vitae, elementum gravida felis. Quisque placerat, arcu eget egestas malesuada, ex nunc maximus purus, ac commodo dui nisl sit amet nisi.Quisque ornare imperdiet mi sed laoreet. Nulla eget diam vel sapien pulvinar vestibulum id quis elit. Mauris egestas finibus neque, ut luctus enim bibendum a. Phasellus mauris risus, condimentum ac commodo quis, mollis interdum lorem. Mauris hendrerit sem vel egestas maximus. Maecenas lorem quam, pulvinar at ante non, venenatis laoreet augue. Mauris interdum suscipit pulvinar. Nulla lobortis, felis eu lobortis sagittis, leo orci pretium metus, sit amet condimentum orci leo et velit. In dignissim, nibh quis mattis pharetra, erat mauris convallis mauris, eget venenatis erat lacus nec ex. Etiam eu sagittis felis, nec porttitor eros. Pellentesque ut nisl eget nibh dictum eleifend eu id nisl. Phasellus egestas imperdiet justo, nec molestie urna imperdiet vitae. Curabitur mauris dolor, posuere sit amet fringilla fringilla, aliquet eu purus. Donec erat enim, placerat et arcu quis, vehicula luctus felis. Morbi vestibulum facilisis elit in tempor. In ornare maximus facilisis.Quisque tincidunt nisl in ex auctor, non viverra quam maximus. Aliquam vel tellus ligula. Nunc ornare, enim nec hendrerit euismod, ipsum purus scelerisque nulla, non interdum erat elit sit amet massa. Integer luctus in metus in vulputate. Maecenas pulvinar tellus massa, in tempor sapien dapibus et. Maecenas sit amet elementum eros. Mauris in sapien congue, venenatis tortor eu, porta erat. Fusce at laoreet purus. Mauris a massa elementum, finibus risus sit amet, fermentum risus.Quisque commodo, diam ut rhoncus malesuada, massa est consequat odio, et aliquet ante nisl quis felis. Donec blandit nulla non nisl porttitor tincidunt quis et ligula. Nunc sodales turpis id mi aliquam ultricies. Ut enim purus, pellentesque vitae pharetra at, congue sed ipsum. Maecenas varius interdum enim, id varius tortor. Sed sagittis nunc eu massa condimentum posuere. Duis sit amet magna ut orci dictum fermentum. Aliquam eget sollicitudin diam, a faucibus tellus. Praesent in viverra neque. Nam mattis blandit leo at varius. Donec nibh nunc, consectetur eu massa ac, volutpat rutrum risus.Aenean rhoncus ex at suscipit consequat. Fusce viverra mi nec quam commodo rutrum. Aenean faucibus nunc vitae nunc venenatis iaculis. Nam sollicitudin tempor arcu, ac finibus sapien auctor quis. Suspendisse at augue porttitor, lobortis diam vitae, faucibus dui. Proin varius lacus quis eros semper, facilisis blandit orci euismod. Sed tincidunt ornare nulla eu consequat.Pellentesque nec erat vel libero ullamcorper dictum. Donec turpis tortor, porta nec malesuada rutrum, viverra lacinia lectus. Pellentesque consequat egestas magna, ut pretium lectus laoreet vitae. Nullam aliquet ac nisl sed eleifend. Fusce mattis orci in odio molestie, ac molestie diam convallis. In venenatis diam eu mauris porttitor pulvinar. Aliquam sollicitudin dapibus sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia posuere.\0";
  //char buf[BUFLEN];

  if(argc != 3){
		printf("Usage: %s <sleep-busy-sleep_len> <IP>\n", argv[0]);
		exit(1);
	}

	len=atoi(argv[1]);

  if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    diep("socket");

  memset((char *) &si_other, 0, sizeof(si_other));
  si_other.sin_family = AF_INET;
  si_other.sin_port = htons(PORT);
  if (inet_aton(argv[2], &si_other.sin_addr)==0) {
    fprintf(stderr, "inet_aton() failed\n");
    exit(1);
  }

  //printf("strlen(buf) = %s\n", argv[2]);

  for(j=0; j<31; j++){
		head(len);
    for (i=0; i<NPACK; i++) {
      //printf("Sending packet %d\n", i);
      //sprintf(buf, "This is packet %d", i);
      if (sendto(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, slen)==-1)
        diep("sendto()");
    }
    tail(len);
  }

  close(s);
  return 0;
}
