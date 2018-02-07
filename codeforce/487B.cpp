//category : dp, st

#include <stdio.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 17;
int a[100001];
int d[100001];
int jump[100001];
int st[LEAF + LEAF];
int min(int a, int b){ 
	if (a < 0) return b;
	if (b < 0) return a;
	return a > b ? b : a; 
}
int max(int a, int b){ return a < b ? b : a; }
void update(int ix, int val){
	st[ix] = val;
	ix >>= 1;
	while (ix != 0){
		st[ix] = min(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
int get_min(int ix, int s, int e, int from, int to){
	if (s > e) return -1;
	if (e < from || to < s) return -1;
	if (from <= s&&e <= to) return st[ix];
	return min(get_min(ix + ix, s, (s + e) >> 1, from, to), get_min(ix + ix+1, 1+((s + e) >> 1),e, from, to));
}
int main(){
	int i;
	int n, s, l;
	int lb = 0;
	deque<pii > minima, maxima;
	for (scanf("%d%d%d", &n, &s, &l), i = 1; i <= n; i++)
		scanf("%d", a + i);
	
	for (i = 1; i <= n; i++){
		while (minima.size() && minima.back().first > a[i]) minima.pop_back();
		while (maxima.size() && maxima.back().first < a[i]) maxima.pop_back();
		minima.push_back({ a[i], i });
		maxima.push_back({ a[i], i });
		//while (i - minima.front().second + 1 > l) minima.pop_front();
		//while (i - maxima.front().second + 1 > l) maxima.pop_front();
		while (maxima.front().first - minima.front().first > s){			
			if (maxima.front().second > minima.front().second){
				lb = minima.front().second;
				minima.pop_front();
			}
			else{
				lb = maxima.front().second;
				maxima.pop_front();
			}
			
		}
		d[i] = get_min(1, 0, LEAF - 1, lb, i-l);
		if (d[i] >= 0) d[i]++;
		update(LEAF+i,d[i]);
	}
	printf("%d",d[n]);
	
	

	return 0;
}
