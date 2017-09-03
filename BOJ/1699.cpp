//category : dp


#include <stdio.h>



int d[100001];
int min(int a, int b){ return a > b ? b : a; }
int sqsum(int n){
	if (n == 0) return 1;
	if (d[n] > 0) return d[n];
	int ans = 10000000;
	int i;
	for (i = 1; i*i < n; i++) ans = min(sqsum(i*i) + sqsum(n - i*i), ans);
	if (i*i == n) ans = min(ans, 1);
	d[n] = ans;
	return d[n];
}
int main(){

	
	int n;
	int i;
	scanf("%d",&n);
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;
	printf("%d",sqsum(n));
	
	return 0;
}