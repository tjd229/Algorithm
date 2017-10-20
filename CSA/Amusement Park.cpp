//category : math
#include <stdio.h>
int T, A;
double p[1002][1002];
double e[1002][1002];

int main(){
	int i,j;
	int pij;
	double st = 1.f;
	for (scanf("%d%d", &T, &A), i = 1; i <= T; i++){
		for (j = 1; j <= A; j++){
			scanf("%d", &pij);
			p[i][j] = pij / 100.f;
		}
	}
	for (i = 1; i <= T; i++){
		st = 1.f;
		for (j = 1; j <= A; j++){
			e[i][1] += st*(1.f - p[i][j])*(e[i - 1][j + 1]);
			e[i][1] += st;
			st *= p[i][j];
		}
		if (st == 1.f) printf("\n!\n");
		e[i][1] /= (1.f - st);
		e[i][A+1] = e[i][1];
		for (j = A; j >1; j--){
			e[i][j] = 1.f + p[i][j] * e[i][j + 1] + (1 - p[i][j])*e[i - 1][j + 1];
		}
	}
	printf("%f\n", e[T][1]);



	return 0;
}
