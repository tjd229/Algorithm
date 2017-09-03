//category : graph, hashing, string

#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;
vector<int> edge[200001];
vector<string> s[200001];
string t;
char hist[300001];
int e;
ll e_pow1, e_pow2;
ll p1, p2;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
ll roll(ll h, int e, int val, int mod){
	h *= e;
	if (h >= mod) h %= mod;
	h += val;
	if (h >= mod) h %= mod;
	return h;
}
ll subtract(ll a, ll b, int mod){
	if (b >= mod) b %= mod;
	if (a < b) a += mod;
	a -= b;
	if (a >= mod) a %= mod;
	return a;
}
ll dfs(int node_ix,int s_ix, ll h1, ll h2){
	int i, j;
	int stem;
	ll res = 0;
	ll tree_h1, tree_h2;
	for (i = 0; i < edge[node_ix].size(); i++){
		tree_h1 = h1;
		tree_h2 = h2;
		stem = s_ix;
		for (j = 0; j < s[node_ix][i].size(); j++,stem++){
			hist[stem] = s[node_ix][i][j];
			if (stem >= t.size()){
				tree_h1 = subtract(tree_h1, e_pow1*(hist[stem - t.size()] - 'a' + 1), mod1);
				tree_h2 = subtract(tree_h2, e_pow2*(hist[stem - t.size()] - 'a' + 1), mod2);
			}

			tree_h1 = roll(tree_h1, e, hist[stem] - 'a' + 1, mod1);
			tree_h2 = roll(tree_h2, e, hist[stem] - 'a' + 1, mod2);
			
			res += (tree_h1 == p1)&&(tree_h2 == p2);

		}
		res += dfs(edge[node_ix][i], stem, tree_h1, tree_h2);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	int p;
	e = 27;
	e_pow1=e_pow2= 1;
	string si;
	cin >> n;
	for (i = 2; i <= n; i++){
		cin >> p >> si;
		edge[p].push_back(i);
		s[p].push_back(si);
	}
	cin >> t;
	for (i = 0; i < t.size(); i++){
		if (i > 0){
			e_pow1 = roll(e_pow1, e, 0, mod1);
			e_pow2 = roll(e_pow2, e, 0, mod2);
		}
		p1 = roll(p1, e, t[i] - 'a' + 1, mod1);
		p2 = roll(p2, e, t[i] - 'a' + 1, mod2);
	}
	cout << dfs(1, 0, 0, 0);
	
	return 0;
}