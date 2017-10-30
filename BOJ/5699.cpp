//category : string, AC

#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int cnt;
int s_ix[(int)1e4];
string pic[(int)1e4];
struct Node{
	int pi;
	int combo;
	int tail;
	int edge[26];
	bool valid;
	
	void init(){
		pi = 0;
		valid = false;
		combo = 0;
		tail=0;
		for (int i = 0; i < 26; i++) edge[i] = 0;
	}
}node[(int)1e6+2];
void make_trie(int ix, string &s, int curr, int e){
	if (curr == e){
		node[ix].valid = true;
		node[ix].combo = 1;
		return;
	}
	if (node[ix].edge[s[curr] - 'a'] == 0)
		node[ix].edge[s[curr] - 'a'] = ++cnt;
	make_trie(node[ix].edge[s[curr]-'a'],s,curr+1,e);
}
void set_pi(int s){
	queue<int> q;
	q.push(s);
	int curr, nxt;
	int i;
	int p;
	while (!q.empty()){
		curr = q.front();
		q.pop();
		for (i = 0; i < 26; i++){
			if (node[curr].edge[i] != 0){
				nxt = node[curr].edge[i];
				p = node[curr].pi;
				while (p > 0 && node[p].edge[i] == 0)
					p = node[p].pi;
				if (nxt != node[p].edge[i]){
					node[nxt].pi = node[p].edge[i];
				}
				q.push(nxt);
			}
		}
	}
}
int trace(int p){
	if (p == 0) return 0;
	if (node[p].tail != 0) return node[p].combo;
	node[p].tail = 1;
	node[p].combo = node[p].valid + trace(node[p].pi);
	return node[p].combo;
}
int trace(int ix,string &s,int curr,int e){
	int res = 0;
	while (curr <= e){

		if (node[ix].tail == 0){
			trace(ix);
		}
		if (curr == e){
			node[ix].tail = 1;
			if (node[ix].combo <res+1)
				node[ix].combo = res + 1;
			res = node[ix].combo;
		}
		else{
			if (res < node[ix].combo) res = node[ix].combo;
		}
		ix = node[ix].edge[s[curr] - 'a'];
		curr++;
		
	}
	return res;
}
int main(){
	int i;
	int N;
	int ans;
	int tr;
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true){
		cin >> N;
		if (N == 0) break;
		for (i = 0; i <= cnt; i++) node[i].init();
		ans = 0;
		cnt = 0;
		
		for(i = 0; i < N; i++){
			cin >> pic[i];
			make_trie(0,pic[i],0,pic[i].size());
			s_ix[i] = i;
		}
		set_pi(0);
		sort(s_ix, s_ix + N, [](int a, int b){
			return pic[a].size() < pic[b].size();
		});
		for (i = 0; i < N; i++){
			tr = trace(0,pic[s_ix[i]],0,pic[s_ix[i]].size());
			if (ans < tr) ans = tr;
		}
		cout << ans << endl;
	}

	return 0;
}