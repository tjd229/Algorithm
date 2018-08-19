//string, AC
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
string m[(int)1e5 + 1];
int k[(int)1e5 + 1];
int nxt[(int)1e5 + 1][26];
int pi[(int)1e5 + 1];
int mix[(int)1e5 + 1];
int tail[(int)1e5 + 1];
int cnt;
vector<int> pos[(int)1e5 + 1];
int make_trie(string &s){
	int curr = 0;
	int ix = 0;
	while (curr<s.size()){
		int ac = s[curr] - 'a';
		if (nxt[ix][ac] == 0){
			nxt[ix][ac] = ++cnt;
		}
		ix = nxt[ix][ac];
		curr++;
	}
	return ix;
}
void set_pi(){
	queue<int> q;
	q.push(0);
	while (q.size()){
		int curr = q.front();
		q.pop();
		for (int i = 0; i<26; i++){
			if (nxt[curr][i]){
				int p = pi[curr];
				while (p>0 && nxt[p][i] == 0) p = pi[p];
				if (nxt[curr][i] != nxt[p][i]){
					int plink = pi[nxt[curr][i]] = nxt[p][i];
					tail[nxt[curr][i]] = tail[plink];
					if (mix[plink]) tail[nxt[curr][i]] = plink;
				}
				q.push(nxt[curr][i]);
			}
		}
	}
	for (int i = 0; i <= cnt; i++){
		for (int j = 0; j<26; j++){
			if (nxt[i][j] == 0) nxt[i][j] = nxt[pi[i]][j];
		}
	}
}
void update(string &s){
	int i;
	int curr = 0;
	for (i = 0; i<s.size(); i++){
		int ac = s[i] - 'a';
		
		while (nxt[curr][ac] == 0){
			if (curr == 0) break;
			curr = pi[curr];
		}
		curr = nxt[curr][ac];
		//cout << curr << endl;
		//if (curr == 13) cout << i << "," << curr << endl;
		int ix = mix[curr];
		if (ix) pos[ix].push_back(i);
		for (int pt = tail[curr]; pt; pt = tail[pt]){
			int ix = mix[pt];
			pos[ix].push_back(i);
		}
	}

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	int n;
	string s;
	cin >> s >> n;
	for (i = 1; i <= n; i++){
		cin >> k[i] >> m[i];
		mix[make_trie(m[i])] = i;
		
	}
	set_pi();
	update(s);
	for (i = 1; i <= n; i++){
		int ans;
		if (k[i]>pos[i].size()) ans = -1;
		else{
			ans = 1e9;
			for (j = 0; j + k[i] - 1<pos[i].size(); j++){
				int len = pos[i][j + k[i] - 1] - pos[i][j] + m[i].size();
				if (ans>len) ans = len;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
