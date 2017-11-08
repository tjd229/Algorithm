//category : bs

#include <stdio.h>
int n, s1, s2;
int x[100000];
int max(int a, int b){ return a < b ? b : a; }
int min(int a, int b){ return -max(-a, -b); }
bool delivery(int d){
	int i=n-1;
	
	int l, r;
	l = x[i] - d;
	r = x[i] + d;
	for (--i; i >= 0; i--){
		if (l <= x[i] && x[i] <= r){
			l = x[i] - d;
			r = x[i] + d;
		}
		else{
			l = max(l, x[i] - d);
			r = min(r, x[i] + d);
		}
			
	}
	return (l <= s1&&s1 <= r) || (l <= s2&&s2 <= r);
}
int main(){
	int i;
	int l, r, m;
	for (scanf("%d%d%d", &n, &s1, &s2),i=0; i < n; i++)
		scanf("%d",x+i);
	r = 1e9;
	l = s1 < s2 ? s2 - s1 : s1 - s2;
	while (l <= r){
		m = (l + r) >> 1;
		if (delivery(m)) r = m - 1;// , printf("r:%d\n", r);
		else l = m + 1;// , printf("l:%d\n", l);
	}
	printf("%d",r+1);

	return 0;
}