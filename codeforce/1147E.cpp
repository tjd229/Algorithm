//djs
#include <iostream>
#include <vector>
#include <string>
#define pii pair<int,int>
using namespace std;

int p[100001];
int clr[100001];
string coin = "RRRGGGRRBRRBRGGBRBRRRRGGRBRRGBRRRGGRRRRBGGRGGBGGRR";
//RGRBRBRGBR...
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
}
void ask(vector<pii > &v,string &s) {
	if (v.empty()) return;
	cout << "Q " << v.size()<<" ";
	for (auto p : v) cout << p.first << " " << p.second << " ";
	cout << endl;
	cin >> s;
	return;
	s = "";
	for (auto p : v) {
		int a = p.first - 1;
		int b = p.second - 1;
		char c = coin[a] == coin[b];
		c += '0';
		s += c;
	}
}
int main() {
	int i, t, n; cin >> t;
	while (t--) {
		cin >> n;
		//n=coin.size();
		if (n < 0) return 0;
		for (i = 1; i <= n; ++i) p[i]= i,clr[i]=-1;
		vector<int> ans[4];
		vector<pii > v;
		string s;
		for (i = 1; i+1 <= n; i += 2) v.push_back({i,i+1});
		for (ask(v,s),i = 0; i < v.size(); ++i) {
			if (s[i] == '1') un(v[i].first, v[i].second);
		}
		for (v.clear(), i = 2; i + 1 <= n; i += 2) v.push_back({i,i+1});
		for (ask(v, s), i = 0; i < v.size(); ++i) {
			if (s[i] == '1') un(v[i].first, v[i].second);
		}
		for (i = 1; i <= n; ++i) if (i == p[i]) ans[0].push_back(i);

		for (v.clear(), i = 0; i + 2 < ans[0].size(); i += 4)
			v.push_back({ans[0][i],ans[0][i+2]});
		for (ask(v, s), i = 0; i < v.size(); ++i) {
			if (s[i] == '1') un(v[i].first, v[i].second);
		}
		for (v.clear(), i = 2; i + 2 < ans[0].size(); i += 4)
			v.push_back({ ans[0][i],ans[0][i + 2] });
		for (ask(v, s), i = 0; i < v.size(); ++i) {
			if (s[i] == '1') un(v[i].first, v[i].second);
		}

		for (v.clear(), i = 1; i + 2 < ans[0].size(); i += 4)
			v.push_back({ ans[0][i],ans[0][i + 2] });
		for (ask(v, s), i = 0; i < v.size(); ++i) {
			if (s[i] == '1') un(v[i].first, v[i].second);
		}
		for (v.clear(), i = 3; i + 2 < ans[0].size(); i += 4)
			v.push_back({ ans[0][i],ans[0][i + 2] });
		for (ask(v, s), i = 0; i < v.size(); ++i) {
			if (s[i] == '1') un(v[i].first, v[i].second);
		}
		int c = 1;
		for (i = 0; i < ans[0].size(); ++i) {
			int x = ans[0][i];
			if (x == p[x]) {
				if (c < 4) clr[x] = c++;
				else {
					clr[x] = 6 - clr[find(ans[0][i - 1])] -clr[find(ans[0][i - 2])];					
				}
			}
		}
		
		for (i = 1; i <= n; ++i) {
			ans[clr[find(i)]].push_back(i);
		}
		
		cout << "A ";
		for (i = 1; i < 4; ++i) cout << ans[i].size() << " ";
		cout << endl;
		for (i = 1; i < 4; ++i) {
			for (auto c : ans[i]) cout << c << " ";
			cout << endl;
		}
	}
	return 0;
}