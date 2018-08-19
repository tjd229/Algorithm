//pbs, ft

#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
struct Qry{
	int T, P, S;
	bool operator< (Qry q) const{
		return T < q.T;
	}
}qry[100000];
const int BI = 1 << 17;
vector<int> edge[100001];
vector<int> song[100001];
int artist[100001];
int l[100001], r[100001];
int pre[100001], post[100001];
int decomp[100001];
int ans[100001];
ll ft[BI + 1];
int cnt;
ll sum(int ix){
	ll s = 0;
	while (ix){
		s += ft[ix];
		ix -= (ix&-ix);
	}
	return s;
}
void update(int ix, ll val){
	while (ix <= BI){
		ft[ix] += val;
		ix += (ix&-ix);
	}
}
void dfs(int ix){
	pre[ix] = ++cnt;
	for (auto nxt : edge[ix]) dfs(nxt);
	post[ix] = cnt;
}
int main(){
	int i;
	int N, K, J;
	for (scanf("%d%d%d", &N, &K, &J), i = 2; i <= N; i++){
		int p;
		scanf("%d",&p);
		edge[p].push_back(i);
	}
	dfs(1);
	for (i = 1; i <= N; i++){
		scanf("%d",artist+i);
		song[artist[i]].push_back(i);
		ans[i] = K;
	}
	for (i = 0; i < K; i++)scanf("%d%d%d", &qry[i].T, &qry[i].P, &qry[i].S);
	sort(qry, qry + K);
	for (i = 0; i < K; i++){
		decomp[i] = qry[i].T;
	}
	decomp[K] = -1;
	for (i = 1; i <= N; i++){
		l[i] = 0;
		r[i] = K-1;
	}
	while (1){
		bool end = true;
		vector<vector<int> > q(K);
		memset(ft, 0, sizeof(ft));
		for (i = 1; i <= N; i++){
			if (song[i].size()&&l[i] <= r[i]){
				int m = (l[i] + r[i])>>1;
				q[m].push_back(i);
				end = false;
			}
		}
		if (end) break;
		for (i = 0; i < K; i++){
			int root = qry[i].P;
			int len = post[root] - pre[root]+1;
			int pt = qry[i].S / len;
			update(pre[root], pt);
			update(post[root]+1, -pt);
			//printf("t:%d,%lld\n",i,sum(2));
			for (auto a : q[i]){
				ll tot = 0;
				for (auto s : song[a]) tot += sum(pre[s]);
				double m = tot / (double)song[a].size();
				if (m > J) r[a] = i - 1,ans[a]=i;
				else l[a] = i + 1;
			}
		}
		
	}
	//for (i = 1; i <= N; i++) printf("%d\n", ans[artist[i]]);
	for (i = 1; i <= N; i++) printf("%d\n",decomp[ans[artist[i]]]);
	return 0;
}
