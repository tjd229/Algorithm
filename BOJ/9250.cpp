//category : AC, string



#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool judge;
struct AC{
	struct Node{
		int pi;
		int edges[26];
		bool valid;
		vector<int> ixes;
		Node(){
			pi = 0;
			valid = false;
			for (int i = 0; i < 26; i++) edges[i] = 0;
		}
	};
	vector<Node> nodes;
	int ix;
	void init(){
		Node n;
		nodes.push_back(n);
		ix = 1;
	}
	void insert(int root, string s, int curr,int e){
		if (curr == e){
			nodes[root].valid = true;
			return;
		}
		if (nodes[root].edges[s[curr]-'a'] == 0){
			nodes[root].edges[s[curr] - 'a'] = ix;
			Node n;
			nodes.push_back(n);
			ix++;
		}
		insert(nodes[root].edges[s[curr] - 'a'], s, curr + 1, e);
	}
	void set_pi(int s){
		queue<int> q;
		int i,j,k,p;
		q.push(s);
		while (!q.empty()){
			i = q.front();
			q.pop();
			for (j = 0; j < 26; j++){
				if (nodes[i].edges[j] != 0){
					k = nodes[i].edges[j];
					p = nodes[i].pi;
					while (p>0 && nodes[p].edges[j] == 0) p = nodes[p].pi;
					if (k != nodes[p].edges[j]){
						nodes[k].pi = nodes[p].edges[j];
						nodes[k].ixes = nodes[nodes[k].pi].ixes;
						if (nodes[nodes[k].pi].valid) nodes[k].ixes.push_back(nodes[k].pi);
					}
					q.push(k);
				}
			}			
		}
	}
	void search(int root, string s, int curr, int e){
		while (curr != e){
			
			if (nodes[root].edges[s[curr] - 'a'] != 0){
				if (nodes[root].ixes.size() != 0){
					judge = true;
					return;
				}
				root = nodes[root].edges[s[curr] - 'a'];
				curr++;
			}
			else{
				if (root == 0) curr++;
				root = nodes[root].pi;
			}
			if (nodes[root].valid || nodes[root].ixes.size() != 0){
				judge = true;
				return;
			}
		}
		
	}
	
};
int main(){
	int N,Q;
	string s;
	AC ac;
	scanf("%d", &N);
	ac.init();
	do{
		cin >> s;
		ac.insert(0,s,0,s.size());
	} while (--N);
	ac.set_pi(0);

	for (scanf("%d", &Q); Q--;){
		cin >> s;
		judge = false;
		ac.search(0,s,0,s.size());
		printf("%s\n",judge? "YES":"NO");
	}
	
	return 0;
}