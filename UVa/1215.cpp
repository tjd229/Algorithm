//String cutting
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3656
//category : string


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int sum[26][10001];
int cost(int l, int m, int r){
	int res = 0;
	for (int i = 0; i < 26; i++){
		if (sum[i][m] - sum[i][l - 1]>0 && sum[i][r] - sum[i][m] > 0) continue;
		if (sum[i][m] - sum[i][l - 1]==0 && sum[i][r] - sum[i][m] == 0) continue;
		res++;
	}
	return res;
}
int main(){
	int i,j;
	int l, r;
	int t;
	int k;
	int cut;
	int ans;
	cin >> t;
	while (t--){
		cin >> k;
		vector<int> ks;
		string s;
		set<int> st;
		ans = 0;
		for (i = 0; i < k; i++){
			cin >> cut;
			ks.push_back(cut);
		}
		cin >> s;
		for (i = 0; i < s.size(); i++){
			for (j = 0; j < 26; j++){
				sum[j][i + 1] = sum[j][i];
			}
			sum[s[i] - 'a'][i + 1] += 1;
		}

		st.insert(1);
		st.insert(s.size()+1);
		for (i = 0; i < k; i++){
			auto ptr = upper_bound(st.begin(), st.end(), ks[i]);
			r = *ptr;
			l = *(--ptr);
			ans += cost(l,ks[i],r-1);
			st.insert(ks[i]+1);
		}
		cout << ans << "\n";
	}

	return 0;
}