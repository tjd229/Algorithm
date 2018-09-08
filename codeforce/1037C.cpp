//dp

#include <stdio.h>
int a[(int)1e6+1], b[1+(int)1e6];
int d[(int)1e6 + 1][2];
int min(int a, int b){ return a < b ? a : b; }
int main(){
	int i;
	int n;
	for (scanf("%d", &n), i = 1; i <= n; i++) scanf("%1d",a+i);
	for (i = 1; i <= n; i++) scanf("%1d", b + i), d[i][0] = d[i][1] = 1e9;
	d[0][0] = 1e9;
	for (i = 1; i <= n; i++){
		if (a[i] == b[i]){
			d[i][1] = min(d[i - 1][1],d[i-1][0]);
		}
		else{
			d[i][1] = min(d[i - 1][0], d[i - 1][1]) + 1;
			if (i > 1 && a[i-1]==b[i] && b[i-1]==a[i]){
				d[i][0] = min(d[i - 2][0], d[i - 2][1]) + 1;
			}
		}
		//printf("%d,%d\n",d[i][0],d[i][1]);
	}
	printf("%d",min(d[n][0],d[n][1]));

	return 0;
}
