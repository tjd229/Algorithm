#include <stdio.h>
#include <stdlib.h>
#include "ant.h"

static int realK;

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(1); }
}

static int call_cnt = 0;
int DeliverCount(int T){
	call_cnt++;
	my_assert(call_cnt < 70, "Wrong : Too Much Calls");
	my_assert(T >= 1 && T < 100000000, "Wrong : Invalid T");
	return T / realK;
}

int main(){
	my_assert(scanf("%d", &realK) == 1, "Error: Invalid K");
	my_assert(1 <= realK && realK < 100000000, "Error: Invalid K");

	int myK = FindK();
	my_assert(realK == myK, "Wrong : Wrong Answer");
	printf("Correct\n%d\n", call_cnt);
	return 0;
}

