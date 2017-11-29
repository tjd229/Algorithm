//category : string, SA, djs

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int g[4001];
int lcp[4001];
int tmp[4001];
int s_ix[4001];
int p[4001];
int sz[4001];
bool cover[4001];
int d;
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
int find(int a){
	if (a != p[a]) p[a] = find(p[a]);
	return p[a];
}
void join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	sz[a] += sz[b];
}
int main(){
	int i, j;
	int C;
	int K;
	int ans;
	string s;
	cin >> C;
	while (C--){
		cin >> K >> s;
		if (K == 1){
			cout << s.size() << "\n";
			continue;
		}
		for (i = 0; i < s.size(); i++){
			s_ix[i] = i;
			g[i] = s[i];
			cover[i] = false;
			p[i] = i;
			sz[i] = 0;
		}
		ans = 0;
		g[i] = -1;
		cover[i] = false;
		d = 1;
		do{
			sort(s_ix, s_ix + s.size(), cmp);
			tmp[s_ix[0]] = 0;
			for (i = 1; i < s.size(); i++)
				tmp[s_ix[i]] = tmp[s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
			for (i = 0; i < s.size(); i++)
				g[i] = tmp[i];
			d <<= 1;
		} while (s.size() - 1 != g[s_ix[s.size() - 1]]);
		d = 0;
		vector<pii > v;
		for (i = 0; i < s.size(); i++){
			if (g[i] == 0) continue;
			j = s_ix[g[i] - 1];
			d = max(d - 1, 0);
			lcp[g[i]] = 0;
			while (i + d < s.size() && j + d < s.size() && s[j + d] == s[i + d])
				lcp[g[i]] = ++d;
			d = lcp[g[i]] - 1;
			//cout << lcp[g[i]] << "," << i << endl;
			if (lcp[g[i]] > 0){
				sz[g[i]] = 1;
				v.push_back({lcp[g[i]],g[i]});
			}
		}
		sort(v.begin(), v.end());
		while (!v.empty()){
			i = v.back().second;
			if (cover[i - 1]) join(i - 1, i);
			if (cover[i + 1]) join(i, i+1);
			//cout << sz[find(i)] << ","<<v.back().first << endl;
			if (sz[find(i)] + 1 >= K){
				ans = v.back().first;
				break;
			}
			cover[i] = true;
			v.pop_back();
		}
		cout << ans << "\n";
	}

	return 0;
}
