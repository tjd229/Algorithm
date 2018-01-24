//category : graph, SCC, 2-SAT

#include <vector>
#include <string>
#define NEG 50
#define ll long long
using namespace std;

class OddEvenTreeHard{
public:
	
	int n;
	int visit[101];
	ll stat1,stat2;
	vector<int> edge[101];
	vector<int> back[101];
	void addEdge(int u,int v){
		if (u < 0) u = NEG - u-1;
		if (v < 0) v = NEG - v-1;
		edge[u].push_back(v);
		back[v].push_back(u);
	}
	void dfs(int ix,int stamp,vector<int> *edge){
		if (visit[ix] == stamp) return;
		visit[ix] = stamp;
		for (int i = 0; i < edge[ix].size(); i++)
			dfs(edge[ix][i], stamp, edge);
		edge[100].push_back(ix);
	}
	bool check(const vector<int> &v){
		if (v.size() <2) return true;
		int check[NEG] = { 0 };
		int ix;
		for (int i = 0; i < v.size(); i++){
			ix = v[i] % NEG;
			//printf("%d\n",v[i]);
			if (check[ix] != 0) return false;
			check[ix]++;
			if (0 == (stat1&(1LL << ix)) && 0 == (stat2&(1LL << ix)))
				v[i] < NEG ? (stat1 |= 1LL << ix) : (stat2 |= 1LL << ix);
		}
		return true;
	}
	vector<int> getTree(vector<string> s){
		vector<int> ans,r;
		int i, j;
		int stamp = 1;
		stat1 = stat2 = 0;
		n = s[0].size();
		ans.push_back(-1);
		for (i = 0; i < n; i++){
			if (s[i][i] == 'O') return ans;
			visit[i] = 0;
		}
		for (i = 0; i < n; i++){
			for (j = i + 1; j < n; j++){
				if (s[i][j] + s[j][i] == 'E' + 'O') return ans;
				if (s[i][j] == 'E' || s[j][i] == 'E'){
					addEdge(i, j);
					addEdge(~i, ~j);
					addEdge(j, i);
					addEdge(~j, ~i);
				}
				if (s[i][j] == 'O' || s[j][i] == 'O'){
					addEdge(i, ~j);
					addEdge(~i, j);
					addEdge(j, ~i);
					addEdge(~j, i);
				}
			}
		}
		for (i = 0; i < n; i++){
			if (edge[i].size() == 0) r.push_back(i);
			dfs(i, stamp, edge);			
		}
		for (i = 0; i < n; i++) dfs(i+NEG, stamp, edge);
		for (i = edge[100].size() - 1,stamp++; i >= 0; i--){
			dfs(edge[100][i], stamp, back);
			if (!check(back[100])) return ans;
			back[100].clear();
		}
		vector<int> p1, p2;
		
		if (stat1 == 0){
			if (r.empty()) return ans;
			p1.push_back(r.back());
			r.pop_back();
		}
		if (stat2 == 0){
			if (r.empty()) return ans;
			p2.push_back(r.back());
			r.pop_back();
		}
		for (i = 0; i < n; i++){
			if (stat1 & (1LL << i))
				p1.push_back(i);
			if (stat2 & (1LL << i))
				p2.push_back(i);
		}
		ans.pop_back();
		for (i = 0; i < p2.size(); i++){
			ans.push_back(p1[0]);
			ans.push_back(p2[i]);
		}
		for (i = 1; i < p1.size(); i++){
			ans.push_back(p2[0]);
			ans.push_back(p1[i]);
		}
		for (i = 0; i < r.size(); i++){
			ans.push_back(p1[0]);
			ans.push_back(r[i]);
		}		
		return ans;
	}
};
