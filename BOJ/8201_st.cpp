//category : st

#include <stdio.h>
const int LEAF = 1 << 22;
int maxima[LEAF + LEAF], minima[LEAF + LEAF];
int max(int a, int b){ return a < b ? b : a; }
int min(int a, int b){
	if (a == -1) return b;
	if (b == -1) return a;
	return a < b ? a : b;
}
void update(int ix, int val){
	maxima[ix] = minima[ix] = val;
	ix >>= 1;
	while (ix != 0){
		maxima[ix] = max(maxima[ix + ix], maxima[ix + ix + 1]);
		minima[ix] = min(minima[ix + ix], minima[ix + ix + 1]);
		ix >>= 1;
	}
}
int main(){
	int t, n;
	int a;
	int l = 0;
	int ans = 0;
	int i;
	for (i = 0; i < LEAF; i++) minima[i] = minima[i + LEAF] = -1;
	for (scanf("%d%d", &t, &n), i = 0; i < n; i++){
		scanf("%d",&a);
		update(LEAF + i, a);
		while (maxima[1] - minima[1]>t){
			update(LEAF + l, -1);
			l++;
		}
		if (ans < i - l + 1) ans = i-l + 1;
	}
	printf("%d",ans);

	return 0;
}
