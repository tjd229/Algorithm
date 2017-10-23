//category : string, lcp

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int d;
int g[100001];
int lcp[100000];
int s_ix[100000];
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
int main(){
	int i, j;
	int T;
	int L;
	int a, b;
	string S;
	cin >> T;
	while (T--){
		cin >> L >> S;
		for (i = 0; i < L; i++){
			s_ix[i] = i;
			g[i] = S[i];
		}
		g[i] = -1;
		d = 1;
		do{
			sort(s_ix, s_ix + L, cmp);
			lcp[s_ix[0]] = 0;
			for (i = 1; i < L; i++)
				lcp[s_ix[i]] = lcp[s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
			for (i = 0; i < L; i++)
				g[i] = lcp[i];
			d <<= 1;
		} while (g[s_ix[L - 1]] != L - 1);
		d = 0;
		for (i = 0; i < L; i++){
			if (g[i] == 0) continue;
			j = s_ix[g[i] - 1];
			d = max(0, d - 1);
			lcp[g[i]] = 0;
			while (i + d < L&&j + d < L&&S[i + d] == S[j + d])
				lcp[g[i]] = ++d;
			d = lcp[g[i]] - 1;

		}
		//cout << lcp[0] << endl;
		lcp[0] = 0;
		i = 1;
		j = 0;
		while (i < L&&lcp[i - 1] < lcp[i]){
			a = s_ix[j] + lcp[i];
			b = s_ix[i] + lcp[i];
			if (a >= L){
				a %= L;
				if (g[a] > g[b]) j = i;
			}
			i++;
		}
		cout << s_ix[j] << "\n";
	}

	return 0;
}