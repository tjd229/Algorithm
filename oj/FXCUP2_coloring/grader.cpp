#include <stdio.h>
#include <stdlib.h>
#include "coloring.h"

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(1); }
}

static int N, ba[111], nxt[111], col[111];

static int col_cnt = 0;
void Color(int A){
	col_cnt++;
	my_assert(col_cnt <= 7300, "Wrong[3]");
	my_assert(1 <= A && A <= N, "Wrong[2]");
	col[nxt[A]] = col[A];
}

static int get_cnt = 0;
int GetColor(int C){
	get_cnt++;
	my_assert(get_cnt <= 200, "Wrong[3]");
	my_assert(1 <= C && C <= N, "Wrong[2]");

	int flag = 0;
	for(int i=1; i<=N; i++){
		if(col[i] == C) flag = 1;
	}
	for(int i=1; i<=N; i++) col[i] = i;
	return flag;
}

int main(){
	my_assert(scanf("%d", &N) == 1, "Error: Invalid N");
	my_assert(3 <= N && N <= 100, "Error: Invalid N");
	for(int i=1; i<=N; i++){
		my_assert(scanf("%d", &ba[i]) == 1, "Error : Invalid nxts");
		my_assert(1 <= ba[i] && ba[i] <= N, "Error : Invalid nxts");
		for(int j=1; j<i; j++){
			my_assert(ba[i] != ba[j], "Error : Invalid nxts");
		}
	}
	for(int i=1; i<=N; i++) nxt[ba[i]] = ba[i%N+1];

	for(int i=1; i<=N; i++) col[i] = i;
	ColoringSame(N);

	for(int i=1; i<=N; i++) my_assert(col[i] == 1, "Wrong[1]");
	puts("Correct");
	return 0;
}
