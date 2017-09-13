//Underwater snipers
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3407
//category : bs, geometry

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<pair<ll, ll> > enemy;
ll k, N, S, D;
bool dispatch(ll M){
	ll last = -1;
	ll s = 0;
	ll last_range, curr_range,new_range;
	for (int i = 0; i < enemy.size(); i++){
		if (-enemy[i].second + M>D) return false;
		if (last >= 0){
			curr_range = enemy[i].first - (ll)sqrt(D*D - (-enemy[i].second + M)*(-enemy[i].second + M));
			if (last_range < curr_range)
				last = -1;
			else{
				new_range = enemy[i].first + (ll)sqrt(D*D - (-enemy[i].second + M)*(-enemy[i].second + M));
				if (new_range < last_range) last_range = new_range;
			}
		}
		if (last < 0){
			last = i;
			last_range = enemy[last].first + (ll)sqrt(D*D - (-enemy[last].second + M)*(-enemy[last].second + M));
			s++;
		}
		if (s > S) return false;
	}
	return true;
}
int main(){
	int T;
	ll M;
	ll x, y;
	ll l, m, r;
	int tc = 1;
	int i;
	for (scanf("%d", &T); T--; tc++){
		scanf("%lld%lld%lld%lld", &k, &N, &S, &D);
		enemy.clear();
		for (i = 0; i < N; i++){
			scanf("%lld%lld", &x, &y);
			y -= k;
			enemy.push_back(make_pair(x, -y));
		}
		sort(enemy.begin(), enemy.end());
		l = 1;
		r = D;
		M = -1;
		while (l <= r){
			m = (l + r) / 2;
			if (dispatch(m)){
				l = m + 1;
				M = m;
			}
			else{
				r = m - 1;
			}
		}
		printf("Case %d: ", tc);
		if (M < 0) printf("IMPOSSIBLE\n");
		else printf("%lld\n", M);
	}
	return 0;
}