//category : string, AC


#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
string S;
string str;
int cnt;
vector<pii > pos;
int st[(int)1e6 + 1];
int top;
struct Node{
	int pi;
	int depth;
	int edge[26];
	bool valid;
}node[(int)1e5 + 1];

void make_tree(int ix, int curr, int e){
	while (curr != e){
		if (node[ix].edge[str[curr] - 'a'] == 0){
			node[ix].edge[str[curr] - 'a'] = ++cnt;
			node[cnt].depth = node[ix].depth + 1;
		}
		ix = node[ix].edge[str[curr] - 'a'];
		curr++;
	}
	node[ix].valid = true;
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
void fast_link(){
	int i, j;
	int nxt;
	for (i = 0; i <= cnt; i++){
		for (j = 0; j < 26; j++){
			if (node[i].edge[j] == 0){
				
				node[i].edge[j] = node[node[i].pi].edge[j];
			}
		}
	}
}
void search(int ix, int curr){
	int i;
	while (curr != S.size()){
		if (node[ix].edge[S[curr] - 'a'] != 0){
			ix = node[ix].edge[S[curr] - 'a'];
			st[top++] = ix;
			curr++;
		}
		else{
			if (ix == 0) curr++, st[top++] = -1;
			ix = node[ix].pi;
		}
		if (node[ix].valid){
			pos.push_back(mp(curr - 1, node[ix].depth));
			top -= node[ix].depth;

			ix = 0;
			if (top != 0 && st[top - 1] >= 0)
				ix = st[top - 1];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int i, j, k;

	cin >> S;
	cin >> N;
	while (N--){
		cin >> str;
		make_tree(0, 0, str.size());
	}
	set_pi(0);
	fast_link();
	search(0, 0);
	k = 0;
	j = pos.size() - 1;
	for (i = S.size() - 1; i >= 0; i--){
		if (j >= 0 && pos[j].first == i) k += pos[j].second, j--;
		if (k > 0){
			S[i] = ' ';
			k--;
		}

	}
	for (i = 0; i < S.size(); i++){
		if (S[i] != ' ') cout << S[i];
	}
	return 0;
}