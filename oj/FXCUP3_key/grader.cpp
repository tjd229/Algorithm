#include <stdio.h>
#include <stdlib.h>
#include "key.h"

static int N, in[1010];

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(1); }
}

static int call_cnt = 0, chk[1010];
void TakeKey(int K){
	my_assert(1 <= K && K <= N, "Wrong : Invalid K");
	my_assert(!chk[K], "Wrong : K Already Exists");
	chk[K] = 1;
}

static int go[1010];

int Explore(){
	call_cnt++;
	my_assert(call_cnt <= 10000, "Wrong : Too Much Calls");

	int gcn = 0;
	for(int i=1; i<=N; i++) go[i] = 0;
	for(int i=1; i<=N; i++){
		if(!chk[i]) continue;
		for(int j=i; !go[j]; j=in[j]) go[j] = 1, gcn++;
		chk[i] = 0;
	}
	return gcn;
}

static int can_go[1010][1010], pair_cnt;
void Report(int Key, int Room){
	my_assert(1 <= Key && Key <= N && 1 <= Room && Room <= N, "Wrong : Invalid Key, Room");
	my_assert(can_go[Key][Room], "Wrong : Cannot Go Key->Room");
	my_assert(can_go[Key][Room]!=2, "Wrong : Duplicate Argument");

	can_go[Key][Room] = 2;
	pair_cnt--;
}

int main(){
	my_assert(scanf("%d", &N) == 1, "Error: Invalid Input");
	my_assert(1 <= N && N <= 1000, "Error: Invalid Input");
	for(int i=1; i<=N; i++){
		my_assert(scanf("%d", &in[i]), "Error: Invalid Input");
		my_assert(1 <= in[i] && in[i] <= N, "Error: Invalid Input");
	}
	for(int i=1; i<=N; i++){
		for(int j=i; !go[j]; j=in[j]) go[j] = can_go[i][j] = 1, pair_cnt++;
		for(int j=i; go[j]; j=in[j]) go[j] = 0;
	}

	EnsureKeyInfo(N);
	my_assert(pair_cnt == 0, "Wrong : Did Not Call All Pairs");
	printf("Correct\n%d\n", call_cnt);
	return 0;
}
