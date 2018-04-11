//category : math

#include "treasure.h"
int s[101][101];
void findTreasure(int N) {
 
	int i, j;
	int half = N >> 1;
	for (i = N; i>0;--i){
		for (j = N; j > 0;--j){
			if (i > half){
				if (j > half){
					s[i][j] = countTreasure(1,1,i,j);
				}
				else s[i][j] = s[i][N] - countTreasure(1,j+1,i,N);
			}
			else{
				if (j > half)
					s[i][j] = s[N][j] - countTreasure(i + 1, 1, N, j);
				else
					s[i][j] = s[i][N] + s[N][j] + countTreasure(i + 1, j + 1, N, N)-s[N][N];
			}
		}
	}
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			if (s[i][j] - s[i - 1][j] - s[i][j - 1] + s[i - 1][j - 1] == 1)
				Report(i,j);
		}
			
	}
}
