//category : graph

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, m;
int L[1<<21];
ll dist[1<<21];
vector<ll> v[1 << 21];
vector<ll> sum[1 << 21];
void dfs(int ix, ll d){
	if (ix > n) return;
	dfs(ix + ix,d+L[ix+ix-1]);
	dfs(ix + ix + 1, d + L[ix + ix]);
	int i;
	v[ix].push_back(d);
	dist[ix] = d;
	for (i = 0; i < v[ix + ix].size(); i++)
		v[ix].push_back(v[ix + ix][i]);
	for (i = 0; i < v[ix + ix+1].size(); i++)
		v[ix].push_back(v[ix + ix+1][i]);
	sort(v[ix].begin(), v[ix].end());
	sum[ix].push_back(v[ix][0]);
	for (i = 1; i < v[ix].size(); i++)
		sum[ix].push_back(v[ix][i]+sum[ix].back());
}
ll tot(int r,ll d){
	if (r > n) return 0;
	int ix = upper_bound(v[r].begin(),v[r].end(),d)-v[r].begin()-1;
	//printf("%d\n",ix);
	if (ix < 0) return 0;
	return ((ix + 1)*d) - sum[r][ix];
}
int main(){
	int i, j;
	int A, H;

	for (scanf("%d%d", &n, &m), i = 1; i < n; i++){
		scanf("%d",L+i);
	}
	dfs(1, 0);
	while (m--){
		scanf("%d%d",&A,&H);
		ll ans = tot(A, H+dist[A]);
		ll d = H;
		//printf("%d's:%I64d\n",A, ans);
		while (A>1){
			if (d < L[A - 1]) break;
			
			d -= L[A - 1];
			ans += d;
			//printf("%d->%d,%I64d\n",A,A/2, ans);
			ans += tot(A ^ 1, d - L[(A ^ 1) - 1] + dist[A ^ 1]);
		
			A >>= 1;
		}
		printf("%I64d\n",ans);


	}
	return 0;
}
