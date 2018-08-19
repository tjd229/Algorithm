//math

#include <stdio.h>
#include <math.h>
int p[501];
int s[501];
int main(){
	int i,j,k;
	int N, K;
	double ans = -1.0;
	for (scanf("%d%d", &N, &K), i = 1; i <= N; i++){
		scanf("%d", p + i);
		s[i] = s[i - 1] + p[i];
	}
	for (k = K; k <= N; k++){
		for (i = 1; i + k-1 <= N; i++){
			//printf("%d,%d:%d\n",i,k,s[i+k-1]-s[i-1]);
			double m = (s[i + k-1] - s[i - 1]) / (double)k;
			double var = 0;
			for (j = 0; j < k;j++){
				double sq = p[i+j] - m;
				var += sq*sq;
			}
			var /= k;
			if (ans<0 || ans>var) ans = var;
		}
	}
	printf("%.10f",sqrt(ans));

	return 0;
}
