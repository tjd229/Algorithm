//category : math
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Plan{
	int ix;
	int new_t;
	long long c;
	bool operator<(Plan plan){
		return ix < plan.ix;
	}
}p[300001];
bool check[600001];
int main(){
	int i;
	int n, k;
	int min_ix;
	long long ans = 0;
	long long cost;
	scanf("%d%d",&n,&k);
	for (i = 1; i <= n; i++){
		scanf("%I64d",&p[i].c);
		p[i].ix = i;
	}
	sort(p + 1, p + n+1, [](Plan p1, Plan p2){
		if (p1.c == p2.c) return p2<p1;
		return p1.c > p2.c;
	});
	min_ix = k+1;
	for (i = 1; i <= n; i++){
		if (p[i].ix >= k + 1 && p[i].ix <= n + k){
			if (!check[p[i].ix]){
				check[p[i].ix] = true;
				p[i].new_t = p[i].ix;
			}
			else{
				ans += (long long)(min_ix - p[i].ix)*p[i].c;
				p[i].new_t = min_ix;
				check[min_ix] = true;
			}
		}
		else{
			ans += (long long)(min_ix - p[i].ix)*p[i].c;
			p[i].new_t = min_ix;
			check[min_ix] = true;
		}
		while (min_ix<600001&&check[min_ix] ) min_ix++;

	}
	sort(p + 1, p + 1 + n);
	printf("%I64d\n",ans);

	for (i = 1; i <= n; i++){
		printf("%d ", p[i].new_t);
	}

	return 0;
}