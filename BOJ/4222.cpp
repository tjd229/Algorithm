//category : graph, BCC
//idea reference : http://koosaga.com/76
#include <stdio.h>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;
const int BOUND = 1e4*5 + 2;
vector<int> edge[BOUND];
vector<int> bcc[BOUND];
int low[BOUND], num[BOUND];
int clr[BOUND],ap[BOUND],deg[BOUND];
int visit[BOUND];
int cnt;
int min(int a, int b){ return a < b ? a : b; }
int dfs(int ix,int from){
	num[ix] = low[ix] = ++cnt;
	
	for (int i = 0; i < edge[ix].size(); i++){
		if (num[edge[ix][i]] == 0){
			low[ix] = min(low[ix], dfs(edge[ix][i], ix));
			
		}
		else if (from != edge[ix][i]) low[ix] = min(low[ix], num[edge[ix][i]]);
	}
	return low[ix];
}
void color(int ix,int c,int stamp){
	if (c > 0) clr[c]++;
	visit[ix] = stamp;
	bcc[ix].clear();
	bcc[ix].pb(c);
	bool flag = false;
	int path=0;
	for (int i = 0; i < edge[ix].size(); i++){
		if (visit[edge[ix][i]] == stamp) continue;
		path++;
		if (num[ix] <= low[edge[ix][i]]){
			cnt++;
			clr[cnt]++;			
			bcc[ix].pb(cnt);
			color(edge[ix][i], cnt, stamp);
			flag = true;
		}
		else{
			color(edge[ix][i], c, stamp);
		}
	}
	if (c == 0 && path > 1) ap[ix] = stamp;
	if (c != 0 && flag) ap[ix] = stamp;
}
int main(){
	int i,j;
	int tc=1;
	int N;
	int s, t;
	int junction;
	int ans1;
	ll ans2;
	
	while (scanf("%d", &N)){
		if (N == 0) break;
		junction = 0;
		cnt = 0;
		ans1 = 0;
		ans2 = 1;
		while (N--){
			scanf("%d%d",&s,&t);
			edge[s].pb(t);
			edge[t].pb(s);
			low[s] = low[t] = 0;
			num[s] = num[t] = 0;
			clr[s] = clr[t] = 0;
			deg[s] = deg[t] = 0;
			if (junction < s) junction = s;
			if (junction < t) junction = t;
		}
		low[0] = num[0] = 0;
		dfs(1, 0);
		cnt = 0;
		color(1, cnt, tc);
		for (i = 1; i <= junction; i++){
			if (ap[i] == tc){
				for (j = 0; j < bcc[i].size(); j++)
					deg[bcc[i][j]]++;
			}
		}
		for (i = 1; i <= cnt; i++){
			if (deg[i] == 1){
				ans1++;
				ans2 *= clr[i] - 1;
				
			}
		}
		if (ans1 == 0){
			ans1 = 2;
			ans2 *= junction;
			ans2 *= junction-1;
			ans2 >>= 1;
		}


		printf("Case %d: %d %lld\n",tc++,ans1,ans2);


		for (i = 0; i <= junction; i++) edge[i].clear();
	}

	return 0;
}