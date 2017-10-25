//category : string, SA

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int s_ix[500000];
int g[500001];
int lcp[500000];
int tmp[500000];
int d;
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a+d] < g[b+d];
}
int main(){
	int i,j;
	string S;
	cin >> S;
	for (i = 0; i < S.size(); i++){
		s_ix[i] = i;
		g[i] = S[i];
	}
	g[S.size()] = -1;
	d = 1;
	//sa
	do{
		sort(s_ix, s_ix + S.size(), cmp);
		tmp[s_ix[0]] = 0;
		for (i = 1; i < S.size(); i++)
			tmp[s_ix[i]] = tmp[s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
		for (i = 0; i < S.size(); i++)
			g[i] = tmp[i];
		d <<= 1;
	} while (g[s_ix[S.size() - 1]] != S.size()-1 );
	d = 0;
	//lcp
	for (i = 0; i < S.size(); i++){
		if (g[i] == 0) continue;
		j = s_ix[g[i] - 1];
		d = max(0, d - 1);
		while(i+d<S.size()&&j+d<S.size()&&S[i+d]==S[j+d]){
			lcp[g[i]] = ++d;
		}
		d = lcp[g[i]]-1;
		
		//if (i == 1) cout << d << ","<<i<<","<<j<<endl;
	}
	for (i = 0; i < S.size(); i++)
		cout << s_ix[i]+1 << " ";
	cout << "\nx ";
	for (i = 1; i < S.size(); i++)
		cout << lcp[i] << " ";
	


	return 0;
}
