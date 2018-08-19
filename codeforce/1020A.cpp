//math

#include <stdio.h>
int main(){
	int n, h, a, b, k;
	int i;
	for (scanf("%d%d%d%d%d", &n, &h, &a, &b, &k); k--;){
		int ta, fa, tb, fb;
		scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
		int tc = ta;
		int fc = fa;
		int ans=0;
		if (tc == tb){
			ans = fc - fb;
			if (ans < 0) ans = -ans;
			printf("%d\n",ans);
		}
		else{
			if (fc > b){
				ans = fc - b;
				fc = b;				
			}
			else if (fc < a){
				ans = a - fc;
				fc = a;
			}
			int d = tc - tb;
			if (d < 0) d = -d;
			ans += d;
			d = fc - fb;
			if (d < 0) d = -d;
			ans += d;
			printf("%d\n",ans);
		}
	}

	return 0;
}
