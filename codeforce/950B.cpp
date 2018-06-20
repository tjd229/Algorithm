//category : greedy

#include <stdio.h>
#define ll long long
int x[1000001];
int y[1000001];
int main(){
	int n, m;
	int i;
	for (scanf("%d%d", &n, &m), i = 0; i < n; i++) scanf("%d",x+i);
	for (i = 0; i < m; i++) scanf("%d",y+i);
	int p1 = 0;
	int p2 = 0;
	ll X = x[0];
	ll Y = y[0];
	int cnt = 0;
	while (X + Y != 0){
		while (X > Y) Y += y[++p2];
		while (X < Y) X += x[++p1];
		if (X == Y){
			cnt++;
			X = x[++p1];
			Y = y[++p2];
		}
	}
	printf("%d", cnt);
	return 0;
}
