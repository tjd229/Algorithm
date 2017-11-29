//category : string, SA, djs


#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int g[1001];
int lcp[1002];
int tmp[1001];
int s_ix[1001];
int p[1001];
int sz[1001];
int d;
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
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
	//freopen("i.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i, j;
	string S;
	int T, N;
	while (getline(cin, S)){
		vector<pii > v;
		for (i = 0; i <S.size(); i++){
			if (S[i] >= 'A'&&S[i] <= 'Z'){
				S[i] = S[i] - 'A' + 'a';
			}
			s_ix[i] = i;
			g[i] = S[i];
		}
		g[i] = -1;
		d = 1;
		do{
			sort(s_ix, s_ix + S.size(), cmp);
			tmp[s_ix[0]] = 0;
			for (i = 1; i < S.size(); i++)
				tmp[s_ix[i]] = tmp[s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
			for (i = 0; i < S.size(); i++)
				g[i] = tmp[i];
			d <<= 1;
		} while (S.size() - 1 != g[s_ix[S.size() - 1]]);
		d = 0;
		for (i = 0; i < S.size(); i++){
			lcp[g[i]] = 0;
			if (g[i] == 0) continue;
			j = s_ix[g[i] - 1];
			d = max(0, d - 1);
			while (i + d < S.size() && j + d < S.size() && S[i + d] == S[j + d])
				lcp[g[i]] = ++d;
			d = lcp[g[i]] - 1;
			if (lcp[g[i]] > 0) v.push_back({ lcp[g[i]], g[i] });
		}
		lcp[i] = 0;
		sort(v.begin(), v.end());
		for (scanf("%d", &T); T--;){
			scanf("%d", &N);

			pii ans = { 1, -2000 };
			for (i = 0; i < S.size(); i++){
				p[i] = i;
				sz[i] = (lcp[i]>0);
				if (S.size() - i >= N){
					pii candi = { 1, -g[i] };
					if (ans < candi) ans = candi;
				}
			}
			for (i = v.size() - 1; i >= 0; i--){
				if (v[i].first < N) break;
				if (v[i].first <= lcp[v[i].second - 1])
					join(v[i].second - 1, v[i].second);
				if (v[i].first <= lcp[v[i].second + 1])
					join(v[i].second, v[i].second + 1);
				pii candi = { sz[find(v[i].second)] + 1, -v[i].second };
				if (ans < candi) ans = candi;
			}
			printf("%d ", ans.first);
			for (i = 0; i < N; i++)
				printf("%c", S[s_ix[-ans.second] + i]);
			printf("\n");
		}
		while (getchar() != '\n');//OTL
	}
	return 0;
}
