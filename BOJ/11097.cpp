//category : graph, SCC
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string mat[301];
int visit[301];
int n;
bool dfs(int x,int stamp,vector<int> &v){
	if (visit[x] == stamp) return false;
	visit[x] = stamp;
	int i;
	if (stamp > 0){
		for (i = 1; i <= n; i++){
			if (i == x) continue;
			if (mat[x][i] == '1') dfs(i, stamp, v);
		}
	}
	else{
		for (i = 1; i <= n; i++){
			if (i == x) continue;
			if (mat[i][x] == '1') dfs(i, stamp, v);
		}
	}
	v.push_back(x);
	return true;
}
int main(){
	int i, j,k;
	string s;
	vector<int> vec;
	vector<int> scc_buff;
	vector<vector<int> > scc;
	vector<pair<int,int> > ans;
	int T;
	cin >> T;
	while (T--){
		
		cin >> n;
		for (i =1; i <= n; i++){
			cin >> s;
			mat[i] = '0' + s;
		}
		for (i = 1; i <= n; i++) dfs(i, T + 1, vec);

		for (i = vec.size() - 1;i>=0; i--){
			scc_buff.clear();
			if (dfs(vec[i], -T - 1, scc_buff)){
				scc.push_back(scc_buff);
			}
			for (j = 1; j < scc_buff.size(); j++) ans.push_back(make_pair(scc_buff[j - 1], scc_buff[j]));
			if(j!=1) ans.push_back(make_pair(scc_buff[j - 1], scc_buff[0]));
		}
		vector<vector<int> > res(scc.size());
		for (i = 0; i < scc.size(); i++){
			for (j = 0; j < scc.size(); j++){
				if (i == j) continue;
				if (mat[scc[i][0]][scc[j][0]] == '1'){
					for (k = 0; k < scc.size(); k++){
						if (i == k || j == k) continue;
						if (mat[scc[i][0]][scc[k][0]] == '1'&&mat[scc[k][0]][scc[j][0]] == '1') break;
					}
					if (k == scc.size()) ans.push_back(make_pair(scc[i][0],scc[j][0]));
				}
			}
		}
		cout << ans.size() << "\n";
		for (i = 0; i < ans.size(); i++){
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
		
		vec.clear();
		ans.clear();
		scc.clear();
	}

	return 0;
}

