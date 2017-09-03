//category : line sweeping



#include <stdio.h>
#define MIN(a,b) a<b? a:b
int a[300001];
int s[2][300001];
int main(){
	int i;
	int n, k;
	int l, r;
	int z = 0;
	int t;
	scanf("%d%d",&n,&k);
	for (i = 1; i <= n; i++){
		scanf("%d",a+i);
		s[0][i] = s[0][i - 1];
		s[1][i] = s[1][i - 1];
		s[a[i]][i] += 1;
	}
	l = r = 1;
	//r = l+k;
	while (r <= n&&l <= r){
		//printf("%d~%d\n", l, r);
		if (k < s[0][r] - s[0][l - 1]){
			l++;
			if (l>r) r++;
		}
		else{
			t = MIN(k, s[0][r] - s[0][l - 1]);
			if (t + s[1][r] - s[1][l - 1]>z){
				z = t + s[1][r] - s[1][l - 1];
				i = l;
			}
			r++;
		}
	}
	//printf("%d~%d\n", l, r);
	printf("%d\n",z);
	for (l = 1; l <= n; l++){
		if (k > 0 && l >= i&&a[l]==0){
			a[l] = 1;
			k--;
		}
		printf("%d ",a[l]);
	}
	return 0;
}