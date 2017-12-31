//category : math
//ref : http://codeforces.com/contest/894/submission/32485307

#include <stdio.h>
int s[1000];
int main(){
	int i, j;
	int n;
	int m;
	for (scanf("%d", &m), i = 0; i < m; i++){
		scanf("%d", s + i);
	}
	for (i = 1; i < m; i++){
		if (s[i] % s[0] != 0){
			printf("-1");
			return 0;
		}
	}
	printf("%d\n", ((m-1)<<1)+1);
	printf("%d ",s[0]);
	for (i = 1; i < m; i++) printf("%d %d ",s[0], s[i]);
	return 0;
}
