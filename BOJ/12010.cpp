//dp

#include <stdio.h>
#include <vector>
#define pii pair<int,int>
#define ll long long
using namespace std;
vector<int> clan[(int)3e6];
ll min(ll a, ll b){ return a < b ? a : b; }
ll dp(vector<int> &v,int X,int Y,int Z){
	int i;
	ll **d = new ll*[v.size()+1];
	for (i = 0; i <= v.size(); i++){
		d[i] = new ll[2];
		d[i][0] = d[i][1] = 1e12;
	}
	d[0][0] = 0;
	for (i = 1; i <= v.size(); i++){
		d[i][0] = min(d[i-1][0],d[i-1][1])+(i&1? X:Y);
		if (i > 1){
			ll move = (ll)Z*(v[i-1] - v[i - 2]);
			d[i][1] = min(d[i-2][0],d[i-2][1]) + move;
		}
	}
	//printf("%lld,%lld\n\n", d[v.size()][0], d[v.size()][1]);
	ll res = min(d[v.size()][0], d[v.size()][1]);
	for (i = 0; i <= v.size(); i++) delete[] d[i];
	delete[] d;
	return res;
}
int main(){
	int i;
	int N, X, Y, Z;
	int A, B;
	int g = int(3e6) >> 1;
	ll ans = 0;
	for (scanf("%d%d%d%d", &N, &X, &Y, &Z), i = 0; i<N; i++){
		scanf("%d%d", &A, &B);
		while (A--) clan[g++].push_back(i);
		while (B--) clan[--g].push_back(i);
	}
	g = int(3e6) >> 1;
	for (; clan[g].size(); g++){
		ans += dp(clan[g],Y,X,Z);
	}

	g = int(3e6) >> 1;
	--g;
	for (; clan[g].size(); g--){
		ans += dp(clan[g], X,Y, Z);
	}

	printf("%lld", ans);

	return 0;
}
