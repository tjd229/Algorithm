//category : graph

#include <stdio.h>
#include <vector>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
vector<int> edge[200001];
vector<int> desk_list;
int from[200001];
bool desk[200001];
const int mod = 1e9 + 7;
pii dfs(int ix){
	if (!desk[ix]) return mp(0,0);
	desk[ix] = false;
	pii res = mp(1, 0);
	pii p;
	for (int i = 0; i < edge[ix].size(); i++){
		if (edge[ix][i] == from[ix]) continue;
		from[edge[ix][i]] = ix;
		desk[0] |= (ix == edge[ix][i]);
		p = dfs(edge[ix][i]);
		res.first += p.first;
		res.second+= p.second+ 1;		
	}
	return res;
}
int main(){
	int i;
	int N;
	int u, v;
	pii p;
	scanf("%d",&N);
	for (i = 0; i < N; i++){
		scanf("%d%d",&u,&v);
		if (!desk[u]){
			desk_list.push_back(u);
			desk[u]=true;
		}
		if (!desk[v]){
			desk_list.push_back(v);
			desk[v]=true;
		}
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	long long ans = 1;
	for (i = 0; i < desk_list.size(); i++){
		desk[0] = false;
		p = dfs(desk_list[i]);
		if (p.first == 0) continue;
		if (desk[0]) continue; //*1
		if (p.first == p.second) ans *= 2;
		else ans *= p.first;
		if (ans >= mod) ans %= mod;
	}
	printf("%I64d",ans);

	return 0;
}