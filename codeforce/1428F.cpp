//line sweeping
#include <stdio.h>
#define ll long long
int s[500001];
int len[500001];
int pos[500001];
int main() {
	int i, n;
	ll stk = 0,ans=0;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%1d", s + i);
		if (s[i]) {
			len[i] = len[i - 1] + 1;
			stk += i - pos[len[i]];
			//printf("%d:%d-%d=%d||len:%d\n",i,i,pos[len[i]],i-pos[len[i]],len[i]);
		}
		else if(len[i-1]>0){
			for (int j = 0; j < len[i - 1] ; ++j) {
				pos[j+1] = i - 1 - j;
			}
		}
		//for (int j = 0; j < 2; ++j) printf("%d,", pos[j]);
		//printf("\nstk:%lld\n",stk);
		ans += stk;
	}
	printf("%I64d",ans);
	return 0;
}