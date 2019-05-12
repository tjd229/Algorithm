#include <stdio.h>
#include <stdlib.h>
#include "dowsing.h"

static int N, rX, rY;

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(1); }
}

static int call_cnt = 0, reported = 0;
int Detect(int R, int C){
	call_cnt++;
	my_assert(call_cnt <= 10000, "Wrong : Too Much Calls");
	my_assert(R >= 1 && R <= N && C >= 1 && C <= N, "Wrong : Invalid R, C");
	my_assert(!reported, "Wrong : Called After Report");

	int res = 0;
	if(rX == R) res ^= 1;
	if(rY == C) res ^= 1;
	return res;
}

void Report(int X, int Y){
	my_assert(X >= 1 && X <= N && Y >= 1 && Y <= N, "Wrong : Invalid X, Y");
	my_assert(!reported, "Wrong : Called After Report");
	if(X == rX && Y == rY) reported = 1;
	else reported = -1;
}

int main(){
	my_assert(scanf("%d%d%d", &N, &rX, &rY) == 3, "Error: Invalid Input");
	my_assert(3 <= N && N <= 100, "Error: Invalid Input");
	my_assert(1 <= rX && 1 <= rY && rX <= N && rY <= N, "Error: Invalid Input");

	FindTreasure(N);
	my_assert(reported == 1, "Wrong : Wrong Answer");
	printf("Correct\n%d\n", call_cnt);
	return 0;
}
