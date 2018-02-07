//category : graph, SCC

#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
class Autogame{
public:
	vector<int> edge;
	vector<int> back[50];
	int K;
	int visit[50];
	int from[50];
	int back_dfs(int ix,int src,int sz,int depth,int *seat){
		ll res = 1;
		visit[ix] = 2;
		seat[sz-1+depth] = 1;
		for (int i = 0; i < back[ix].size(); i++){
			//if (visit[back[ix][i]] == 2) continue;
			res *= back_dfs(back[ix][i], src, sz, depth+1,seat);
		}
		if (depth > K) seat[sz-1 + depth - K]++;
		else seat[(src+K-depth)%sz]++;
		return res*seat[sz-1+depth]%mod;
	}
	int dfs(int ix){
		if (visit[ix]) return 1;
		visit[ix] = 1;
		ll res = 1;
		if (visit[edge[ix]] == 1){
			int stk = ix;
			vector<int> scc;
			scc.push_back(ix);
			visit[ix] = 2;
			while (stk != edge[ix]){
				stk = from[stk];
				visit[stk] = 2;
				scc.push_back(stk);
			}
			reverse(scc.begin(), scc.end());
			int seat[50] = { 0 };
			int i, j;
			for (i = 0; i < scc.size(); i++){
				for (j = 0; j < back[scc[i]].size(); j++){
					int to = back[scc[i]][j];
					if (visit[to] == 2) continue;
					res = res*back_dfs(to,i,scc.size(),1,seat);
				}
				seat[i]+=2;
			}
			for (i = 0; i < scc.size(); i++) res = res*seat[i] % mod;
			return res;
		}
		else{
			from[edge[ix]] = ix;
			return dfs(edge[ix]);
		}		
	}
	int wayscnt(vector<int> a, int K){

		int i;
		for (i = 0; i < a.size(); i++){
			visit[i] = 0;
			a[i]--;
			back[a[i]].push_back(i);
		}
		this->edge = a;
		this->K = K;
		ll res = 1;
		for (i = 0; i < a.size(); i++){
			//from[i] = -1;
			res = res*dfs(i) % mod;
		}
		
		return res;
	}

};
