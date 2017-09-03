//category : implementation

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int p[26];
int main(){
	int i;
	string s, t;
	cin >> s >> t;
	for (i = 0; i < s.size(); i++){
		if (p[s[i] - 'a'] == 0 && p[t[i] - 'a'] == 0){
			p[s[i] - 'a'] = (t[i] - 'a') + 1;
			p[t[i] - 'a'] = (s[i] - 'a') + 1;
		}
		else if (p[s[i] - 'a'] != (t[i] - 'a') + 1
			|| p[t[i] - 'a'] != (s[i] - 'a') + 1){
			cout << -1;
			return 0;
		}
	}
	vector<pair<char, char> > ans;
	for (i = 0; i < 26; i++){
		if (p[i] != 0&&p[i]!=i+1){
			ans.push_back(make_pair('a'+i,'a'+p[i]-1));
			p[p[i] - 1] = 0;
			p[i] = 0;			
		}
	}
	cout << ans.size() << "\n";
	for (i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << "\n";
	return 0;
}