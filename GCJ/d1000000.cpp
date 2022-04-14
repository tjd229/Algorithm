//greedy
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a46471
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int S[1000000];
int main() {
	int T,tc;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		int i,N;
		for (scanf("%d", &N), i = 0; i < N; ++i) scanf("%d",S+i);
		sort(S, S + N);
		int front = 0;
		int x = 0;
		while (front < N) {
			if (x+1<= S[front]) ++x;
			++front;
		}
		

		printf("Case #%d: %d\n", tc,x);
	}

	return 0;
}
	