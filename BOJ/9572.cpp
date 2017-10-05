//category : dp
//reference : http://www.usaco.org/current/data/sol_pogocow.html

#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define MAX(a,b) a<b? b:a
using namespace std;
int d[1001][1001];
vector<pii > target;
int main(){
	//freopen("11.in","rt",stdin);
	int i, j, k;
	int N;
	int x, p;
	int ans = 0;
	for (scanf("%d", &N), i = 0; i < N; i++){
		scanf("%d%d", &x, &p);
		target.pb(mp(x, p));
	}
	sort(target.begin(), target.end());

	for (int dir = 0; dir<2; dir++){
		memset(d, 0, sizeof(0));
		for (i = N - 1; i >= 0; i--){
			p = 0;
			k = N - 1;
			ans = max(ans, target[i].second);
			for (j = 0; j < i;j++){
				while (k > i&&
					target[i].first - target[j].first <= target[k].first - target[i].first){
					p = MAX(p, d[i][k]);
					k--;
				}
				d[j][i] = p + target[i].second;
				ans = max(ans, d[j][i] + target[j].second);
			}

		}
		for (i = 0; i < N; i++) target[i].first = -target[i].first;
		reverse(target.begin(), target.end());
	}

	printf("%d", ans);
	return 0;
}
