//category : string, trie, game

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//string word[100000];
struct Trie{
	struct Node{
		int edge[26];
		Node(){
			for (int i = 0; i < 26; i++) edge[i] = 0;
		}
	};
	vector<Node> node;
	void init(){
		Node n;
		node.push_back(n);
	}
	void insert(int ix, string s, int pt){
		
		if (pt == s.size()) return;
		if (node[ix].edge[s[pt]-'a']==0){
			node[ix].edge[s[pt] - 'a'] = node.size();
			Node n;
			node.push_back(n);
			//cout << "tet" << s[pt] - 'a' << endl;
		}
		insert(node[ix].edge[s[pt] - 'a'], s, pt+1);
	}
	//turn: 0(1st), 1(2nd)
	//res : 1(1st=win), 0(1st=lose)
	bool search(int ix,int turn,int res){
		int next = -1;
		bool flag=false;
		for (int i = 0; i < 26; i++){
			if (node[ix].edge[i] == 0) continue;
			flag = true;
			next = search(node[ix].edge[i], turn ^ 1, res);
			if ((next == turn) == res)
				return next;
			/*if ((search(node[ix].edge[i], turn ^ 1, res) == turn)==res)
				return turn^(1^res);*/
		}
		if (flag) return turn ^ res;
		return turn^1;
	}
};
int main(){
	int i;
	int n, k;
	string word;
	Trie t;
	t.init();
	cin >> n >> k;
	for (i = 0; i < n; i++){
		cin >> word;
		t.insert(0,word,0);
	}
	bool win = t.search(0, 0, 1)==0;
	bool lose = t.search(0, 0, 0)==1;
	//cout << win << endl << lose;
	if (!win) cout << "Second";
	else if (lose) cout << "First";
	else if (k & 1) cout << "First";
	else cout << "Second";
	return 0;
}