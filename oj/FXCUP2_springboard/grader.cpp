#include <stdio.h>
#include <stdlib.h>
#include "springboard.h"

static int N;
static char spr[12356];

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(1); }
}

static int calls;
int PutBall(int K){
	calls++;
	my_assert(calls <= 16, "Wrong[3]");
	my_assert(1 <= K && K <= N, "Wrong[2]");

	while(1 <= K && K <= N){
		if(spr[K] == 'L') spr[K]='R', K--;
		else spr[K]='L', K++;
	}
	if(K == 0) return -1;
	return 1;
}

int main(){
	my_assert(scanf("%d\n", &N) == 1, "Error: Invalid N");
	my_assert(1 <= N && N <= 12345, "Error: Invalid N");
	fgets(spr+1, 12346, stdin);
	my_assert(spr[N+1] == 0 || spr[N+1] == 10, "Error: Invalid Springboard");
	for(int i=1; i<=N; i++) my_assert(spr[i] == 'L' || spr[i] == 'R', "Error: Invalid Springboard");

	Reorder(N);
	for(int i=1; i<=N; i++) my_assert(spr[i] == 'L', "Wrong[1]");
	puts("Correct");
	return 0;
}
