//category : graph, djs, MST

#include <string>
#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
vector<int > edge[26];
vector<pii > ans;
pii edge_list[100000];
int p[26];
int visit[26];
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool join(int a, int b){
	a=find(a);
	b = find(b);
	if (a == b) return false;
	p[b] = a;
	return true;
}
void dfs(int ix,int from){
	if (visit[ix]) return;
	visit[ix] = 1;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i], ix);
	if (from >= 0)
		ans.push_back({ ix, from });
}
int main(){
	int n;
	int i;
	string a, b;
	cin >> n >> a >> b;
	for (i = 0; i < 26; i++) p[i] = i;
	for (i = 0; i < n; i++){		
		edge_list[i] = { a[i] - 'a', b[i] - 'a' };
	}
	for (i = 0; i < n; i++){
		if (join(edge_list[i].first, edge_list[i].second)){
			edge[edge_list[i].first].push_back(edge_list[i].second);
			edge[edge_list[i].second].push_back(edge_list[i].first);
		}
	}
	for (i = 0; i < 26; i++) dfs(i, -1);
	cout << ans.size();
	for (i = 0; i < ans.size(); i++){
		cout << "\n" << (char)('a'+ans[i].first) << " " << (char)('a'+ans[i].second);
	}
	return 0;
}
