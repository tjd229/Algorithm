//category : greedy
#include <stdio.h>
int a[200000];
int cnt1, cnt2;
int main(){
	int n;
	int i;
	int ans = 0;
	
	for (scanf("%d", &n), i = 0; i < n; i++){
		scanf("%d",&a[i]);
		if (a[i] == 1) cnt1++;
		else cnt2++;
	}
	if (cnt2 <= cnt1){
		ans += cnt2, cnt1 -= cnt2;
		ans += cnt1/3;
	}
	else ans += cnt1;
	printf("%d",ans);
	return 0;
}
