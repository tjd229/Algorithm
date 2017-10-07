//category : math
#include <stdio.h>
int num[262145];
int d[262145];
int cover[262145][249];
int main(){
	int i;
	int N;
	int ans = 0;
	for (scanf("%d", &N), i = 1; i <= N; i++){
		scanf("%d",num+i);
		d[i] = num[i];
		cover[i][d[i]] = i;
	}
	for (i = 2; i <= N; i++){
		int p = i-1;
		while (p>=1&&num[p] <= d[i] && d[i] <= d[p]){
			d[i]++;
			cover[i][d[i]] = cover[p][d[i]-1];
			p =cover[p][d[i]-1]-1;
		}
		if (ans < d[i]) ans = d[i];
	}
	printf("%d",ans);


}