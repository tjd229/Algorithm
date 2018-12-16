//line sweeping

#include <stdio.h>
#define ll long long
int x1[200001], x2[200001];
int main(){
	int i;
	int n, h;
	int l, r;
	ll ans = 0;
	ll len = 0;
	ll last = 0;
	int cur = 0;
	for (scanf("%d%d", &n, &h), i = 1; i <= n; i++) scanf("%d%d",x1+i,x2+i);

	l = r = 1;
	cur = h;
	for (r = 1; r <= n; r++){
		ans += x2[r] - x1[r];
		if (r==n || x1[r + 1] - x2[r] >= cur){
			ans += cur;
			break;
		}
		ans += x1[r + 1] - x2[r];
		cur -= x1[r + 1] - x2[r];
	}

	//cur = h;
	last = ans-cur;
	for (; r < n; r++){
		len = last;
		while (x1[r + 1] - x2[r] >= cur){
			if (l == r){
				len = x2[r+1]-x1[r+1];
				cur = h;
				++l;
				break;
			}
			len -= x1[l+1]-x1[l];
			cur += x1[l + 1] - x2[l];
			++l;
		}
		if (l <= r && cur>x1[r + 1] - x2[r]){
			len += x1[r + 1] - x2[r];
			len += x2[r + 1] - x1[r+1];
			cur -= x1[r + 1] - x2[r];
		}
		last = len;
		if (ans < len+cur) ans = len+cur;
		
	}
	printf("%I64d",ans);

	return 0;
}
