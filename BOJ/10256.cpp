//category : string, AC


#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int cnt;
int char_ix[(int)'T' + 1];
struct Node{
	int pi;
	int edge[4];
	bool valid;
	void init(){
		pi = 0;
		valid = 0;
		for (int i = 0; i < 4; i++) edge[i] = 0;
	}
}node[(int)1e6 + 2];
void make_trie(int ix, string &s, int curr, int e){
	if (curr == e){
		node[ix].valid = true;
		return;
	}
	if (node[ix].edge[char_ix[s[curr]]] == 0){
		node[ix].edge[char_ix[s[curr]]] = ++cnt;
		node[cnt].init();
	}
	make_trie(node[ix].edge[char_ix[s[curr]]], s, curr + 1, e);
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
		for (i = 0; i < 4; i++){
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
void fast_link(){
	int i, j;
	int nxt;
	for (i = 0; i <= cnt; i++){
		for (j = 0; j < 4; j++){
			if (node[i].edge[j] == 0){

				node[i].edge[j] = node[node[i].pi].edge[j];
			}
		}
	}
}
int infected(int ix, string &s, int curr, int e){
	int res = 0;
	while (curr != e){
		if (node[ix].edge[char_ix[s[curr]]] != 0){

			ix = node[ix].edge[char_ix[s[curr]]];
			curr++;
		}
		else{
			if (ix == 0) curr++;
			ix = node[ix].pi;
		}
		if (node[ix].valid){
			res++;
			ix = node[ix].pi;
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	int T;
	int n, m;
	string dna, marker, mut;
	char_ix[(int)'A'] = 0;
	char_ix[(int)'C'] = 1;
	char_ix[(int)'G'] = 2;
	char_ix[(int)'T'] = 3;
	cin >> T;
	while (T--){
		node[0].init();
		cnt = 0;
		cin >> n >> m;
		cin >> dna >> marker;
		for (i = 0; i <= m - 2; i++){
			for (j = i + 2; j <= m; j++){
				mut = marker;
				reverse(mut.begin() + i, mut.begin() + j);
				
				make_trie(0, mut, 0, m);
			}
		}
		make_trie(0, marker, 0, m);
		set_pi(0);
		fast_link();
		cout << infected(0, dna, 0, n) << "\n";
	}

	return 0;
}