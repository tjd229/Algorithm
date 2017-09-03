//category : line sweeping

#include <stdio.h>
#include <vector>
#include <algorithm>
#define MIN(a,b) a<b? a:b
using namespace std;
const int max_cost = 2000000001;
struct Vacation{
	int l, r, cost;
};
Vacation v[200001];
pair<int, int> table[400003];
int check[200001];
int ans = max_cost;
int main(){
	int n, x;
	int ix;
	int d;
	int i;
	scanf("%d%d",&n,&x);
	for (i = 1; i <= n; i++){
		scanf("%d%d%d", &v[i].l, &v[i].r, &v[i].cost);
		table[i<<1] = make_pair(v[i].l, -i);
		table[(i<<1)+1] = make_pair(v[i].r, i);
	}
	sort(table+2, table+2 + n + n);
	n += n;
	for (i = 2; i < n+2; i++){
		if (table[i].second < 0){
			ix = -table[i].second;
			d = v[ix].r - v[ix].l + 1;
			if (x - d >= 0 && check[x - d]){
				ans = MIN(ans, v[ix].cost + v[check[x - d]].cost);
			}
		}
		else{
			ix = table[i].second;
			d = v[ix].r - v[ix].l + 1;
			if (check[d] == 0 || v[check[d]].cost>v[ix].cost)
				check[d] = ix;
		}
	}
	if (ans == max_cost) ans = -1;
	printf("%d",ans);


	return 0;
}