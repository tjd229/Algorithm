//Recycling
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=90
//category : dp

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
string s[101];
int num[101];
int d[101][101];
int visit[101][101];
int t;
int min(int a, int b){ return a < b ? a : b; }
int recycle(int l,int r){
	if (l > r) return 0;
	if (num[l] < 0) return 0;
	if (l == r) return 1;
	if (visit[l][r] == t) return d[l][r];
	visit[l][r] = t;
	d[l][r] = recycle(l + 1, r) + 1;
	for (int i = l; i <= r; i++){
		if (num[l] != num[i]) continue;
		d[l][r] = min(d[l][r], recycle(l + 1, i - 1) + recycle(i, r));
	}
	return d[l][r];
}
int main(){
	int T;
	int N;
	int i,j;
	int ans;
	cin >> T;
	for (t = 1; t <= T; t++){
		map<string, int> m;
		vector<int> v;
		ans = 0;
		cin >> N;
		for (i = 1,j=0; i <= N; i++){
			cin >> s[i];
			if (s[i][0] >= 'a'){
				if (m.find(s[i]) == m.end()) m.insert(make_pair(s[i], j++));
				num[i] = m[s[i]];
			}
			else{
				num[i] = -1;
				v.push_back(i);
			}

		}
		v.push_back(N+1);
		for (i = 0, j = 1; i < v.size(); i++){
			
			ans += recycle(j,v[i]-1);
			j = v[i] + 1;
		}
		cout << "Case "<<t<<": "<<ans << "\n";
	}

	return 0;
}


