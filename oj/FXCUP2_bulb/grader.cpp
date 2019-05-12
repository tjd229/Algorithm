#include <stdio.h>
#include <stdlib.h>
#include "bulb.h"

static int N;
static int sw[1010], bulb[1010], on, off;

static void my_assert(bool TF, const char* message){
	if(!TF){ puts(message); exit(1); }
}

int main(){
	my_assert(scanf("%d", &N) == 1, "Error: Invalid N");
	my_assert(2 <= N && N <= 1000 && N%2 == 0, "Error: Invalid N");
	Init(N);
	for(int i=0; i<N/2; i++){
		int mh, sy;
		my_assert(scanf("%d", &mh) == 1, "Error: Invalid Minhyung's Turn");
		my_assert(1 <= mh && mh <= N && sw[mh]==0, "Error: Invalid Minhyung's Turn");
		sw[mh] = 1;
		sy = MakeTurn(mh);
		printf("%d\n", sy);
		my_assert(1 <= sy && sy <= N && sw[sy]==0, "Wrong[2]");
		sw[sy] = 1;
		if(mh <= sy) for(int x=mh; x<sy; x++) bulb[x] = 1-bulb[x];
		else for(int x=sy; x<mh; x++) bulb[x] = 1-bulb[x];
	}
	for(int x=1; x<N; x++){
		if(bulb[x] == 1) on++;
		else off++;
	}
	my_assert(on>off, "Wrong[1]");
	puts("Correct");
	return 0;
}
