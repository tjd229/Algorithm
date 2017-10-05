//category : AC, string



#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define pb push_back
using namespace std;
bool judge;
int cnt;
struct Node{
	int pi;
	int edge[26];
	bool valid;
	vector<int> tail;
}node[(int)1e5+1];
void make_tree(int ix,string &s,int curr,int e){
	if (curr == e){
		node[ix].valid = true;
		return;
	}
	if (node[ix].edge[s[curr] - 'a'] == 0){
		node[ix].edge[s[curr] - 'a'] = ++cnt;
	}
	make_tree(node[ix].edge[s[curr] - 'a'], s, curr + 1, e);
}
void set_pi(int s){
	queue<int> q;
	q.push(s);
	int curr,nxt;
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
					node[nxt].tail = node[node[nxt].pi].tail;
					if (node[node[nxt].pi].valid)
						node[nxt].tail.pb(node[nxt].pi);
				}
				q.push(nxt);
			}
		}
	}
	
}
void search(int ix, string &s, int curr, int e){
	while (curr != e){
		if (node[ix].edge[s[curr] - 'a'] != 0){
			if (node[ix].tail.size() != 0){
				judge = true;
				return;
			}
			ix = node[ix].edge[s[curr] - 'a'];
			curr++;
		}
		else{
			if (ix == 0) curr++;
			ix = node[ix].pi;
		}
		if (node[ix].valid || node[ix].tail.size() != 0){
			judge = true;
			return;
		}
	}
}
int main(){
	int N, Q;
	string s;
	cin >> N;
	while (N--){
		cin >> s;
		make_tree(0,s,0,s.size());
	}
	set_pi(0);
	cin >> Q;
	
	while (Q--){
		cin >> s;
		judge = false;
		search(0, s, 0, s.size());
		cout << (judge ? "YES\n" : "NO\n");
	}
	return 0;
}
