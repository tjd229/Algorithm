//greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[100001];
int to[100001];
int mat[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	vector<int> v[4];
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	bool flag = 1;
	int j = 0;
	int last = -1;
	if (v[3].size()) last = v[3].back();
	if (last != -1) {
		while (j<v[2].size() && last>v[2][j]) ++j;
		if (j < v[2].size()) {
			to[last] = v[2][j];
			mat[v[2][j]] = 1;
		}
		if (to[last] == 0) {
			j = 0;
			while (j<v[1].size() &&last>v[1][j]) ++j;
			if (j < v[1].size()) {
				to[last] = v[1][j];
				mat[v[1][j]] = 1;
			}
		}
		if (to[last] == 0) flag = 0;
	}
	/*for (i = 0; i < 4; ++i) {
		cout <<endl<< "!" << i << endl;
		for (auto x : v[i]) cout << x << " ";
	}
	return 0;*/
	j = 0;
	for (i = 0; i < v[2].size() && j < v[1].size(); ++i) {		
		while (j<v[1].size() && v[2][i]>v[1][j]) ++j;
		while (j<v[1].size() && mat[v[1][j]]==1) ++j;
		if (j < v[1].size()) {
			to[v[2][i]] = v[1][j];
			mat[v[1][j]] = 1;
		}
	}
	for (i = 1; i <= n && flag; ++i) {
		if (a[i] == 2 && to[i] == 0) flag = 0;
		//cout << to[i] << " ";
	}
	if (0==flag) cout << -1;
	else {
		int y = 1;
		vector<pii > ans;
		//cout << v[3].size()-1;
		for (i = 1; i <= n; ++i) {
			if (mat[i] == 1) continue;
			if (a[i] == 1) ans.push_back({y++,i});
			else if (a[i] == 2) {
				ans.push_back({ y,i });
				ans.push_back({ y,to[i] });
				++y;
			}
			/*else if(a[i]==3){
				ans.push_back({y,i});
				ans.push_back({y,to[i]});
				++y;
				ans.push_back({ y,to[i] });
				if (a[to[i]] == 2) {
					ans.push_back({ y,to[to[i]] });
				}
				++y;
			}*/
		}
		//vector<int> &seq = v[3];
		
		for (i = 0; i+1 < v[3].size(); ++i) {
			
			ans.push_back({y,v[3][i]});
			ans.push_back({ y, v[3][i + 1] });
			++y;
		}
		
		if (last != -1) {
			ans.push_back({ y,last }); ans.push_back({ y,to[last] });
			ans.push_back({ ++y,to[last] });
			if (a[to[last]] == 2)
				ans.push_back({ y,to[to[last]] });
		}
		cout << ans.size() << "\n";
		for (auto p : ans) {
			cout << p.first << " " << p.second << "\n";
		}
	}
 
	return 0;
}