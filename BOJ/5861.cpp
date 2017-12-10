//category : string, trie, graph, tp sort
//idea reference : http://www.usaco.org/current/data/sol_first.html

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;
vector<int> ans;
string s[30001];
struct Node{
	int stat;
	int valid;
	int nxt[26];
}node[300001];
void make_trie(int ix,int curr,int num,string &s){
	if (curr == s.size()){
		node[ix].valid = num;
		return;
	}
	if (node[ix].nxt[s[curr] - 'a'] == 0) node[ix].nxt[s[curr] - 'a'] = ++cnt;
	make_trie(node[ix].nxt[s[curr] - 'a'],curr+1,num,s);
}
bool check(vector<int> &v){
	int ind[26] = { 0 };
	int i,j;
	int curr;
	vector<int> q;
	for (i = 0; i < 26; i++){
		for (j = 0; j < 26; j++){
			if (v[i] & (1 << j)) ind[j]++;
		}
	}
	for (i = 0; i < 26; i++){
		if (ind[i] == 0) q.push_back(i);
	}
	for (i = 0; i < q.size(); i++){
		curr = q[i];
		for (j = 0; j < 26; j++){
			if (v[curr] & (1 << j)){
				ind[j]--;
				if (ind[j] == 0) q.push_back(j);
			}
		}
	}
	return q.size() == 26;
}
void dfs(int ix, vector<int> &hist){
	if (node[ix].valid){
		if (check(hist)) ans.push_back(node[ix].valid);
		return;
	}
	int nxt;
	int i;
	int stat = 0;
	int backup;
	for (i = 0; i < 26; i++){
		nxt = node[ix].nxt[i];
		if (nxt){
			stat |=(1<<i);
		}
	}
	for (i = 0; i < 26; i++){
		nxt = node[ix].nxt[i];
		if (nxt){
			backup = hist[i];
			hist[i] |= stat & (~(1<<i));
			//hist[i] |= stat^(1 << i);
			dfs(nxt, hist);
			hist[i] = backup;
		}
	}


}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	int N;
	cin >> N;
	for (i = 1; i <= N; i++){
		cin >> s[i];
		make_trie(0,0,i,s[i]);
	}
	vector<int> v(26);
	dfs(0, v);
	sort(ans.begin(), ans.end());
	//cout << cnt << endl;
	cout << ans.size();
	for (i = 0; i < ans.size(); i++)
		cout << "\n" << s[ans[i]];
	return 0;
}
