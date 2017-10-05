//category : greedy

#include <stdio.h>
#define ll long long
ll station[(int)1e4+1];
int main(){
	int i;
	int a, b, f, k;
	int af,ff;
	int ans = 0;
	int r;
	scanf("%d%d%d%d",&a,&b,&f,&k);
	if (a < f){  //?????
		printf("-1");
		return 0;
	}
	af = (a - f) << 1;
	ff = f + f;
	r = b;
	station[0] = f;
	for (i = 1; i < k; i++){
		if (i & 1) station[i] = af;
		else station[i] = ff;
	}
	if (i&1)
		station[i] = af>>1;
	else station[i] = f;
	for (i = 0; i <= k; i++){
		if (r < station[i]){
			r = b;
			ans++;
		}
		r -= station[i];		
		if (r < 0){
			printf("-1");
			return 0;
		}
	}
	printf("%d",ans);
	return 0;
}