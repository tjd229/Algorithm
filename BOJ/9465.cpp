//category : dp



#include <stdio.h>


int s[2][100001];
int d[100001][3];

int max(int a, int b){ return a > b ? a : b; }
int main(){

	
	int i;
	int T;
	int n;
	for (scanf("%d", &T); T--;){
		scanf("%d",&n);
		for (i = 1; i <= n; i++)
			scanf("%d", &s[0][i]);
		for (i = 1; i <= n; i++)
			scanf("%d", &s[1][i]);

		for (i = 1; i <= n; i++){
			d[i][0] = max(d[i - 1][2], d[i - 1][1]);
			d[i][1] = max(d[i - 1][0] + s[0][i], d[i - 1][2] + s[0][i]);
			d[i][2] = max(d[i - 1][0] + s[1][i], d[i - 1][1] + s[1][i]);
		}
		printf("%d\n", max(max(d[n][0], d[n][1]), d[n][2]));
	}
		
	
	
	return 0;
}