#include <stdlib.h>

#define N 10000000

int main(){
	int i;
	void * mem[N];

	for(i=0;i<N;i++){
		mem[i]=malloc(2048);
		free(mem[i]);
	}

	return 0;
}
