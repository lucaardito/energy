#define N 100000

int main(){
	int i;
	double * mem[N];

	for(i=0;i<N;i++){
		mem[i]=new double [25];
		delete[] mem[i];
	}

	return 0;
}
