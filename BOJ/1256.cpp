//math
#include <stdio.h>
#define ll long long
ll nCk[201][201];
int str[201];
int main() {
	int i, j;
	int N, M, K;
	int NM;
	for (scanf("%d%d%d", &N, &M, &K), NM = N + M, i = 1; i <= NM; ++i) {
		for (j = 1, nCk[i][0] = nCk[i][i] = 1; j < i; ++j){
			nCk[i][j] = nCk[i - 1][j] + nCk[i - 1][j - 1];
            if(nCk[i][j]>2e9) nCk[i][j]=2e9;
        }
		//nCk[0][i] = 1;
	}
	nCk[0][0] = 1;
	if (nCk[NM][N] < K) printf("-1");
	else {
		for (i = 0; i < NM; ++i) {
			if (nCk[N + M - 1][M] < K) {
				printf("z");
				K -= nCk[N + M - 1][M];
				--M;
			}
			else {
				printf("a"); --N;
			}
		}
	}

	return 0;
}