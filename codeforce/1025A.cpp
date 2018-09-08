//string

#include <string>
#include <iostream>
using namespace std;
int cnt[26];
int main(){
	int n;
	string s;
	int i;
	cin >> n >> s;
	if (n == 1) cout << "Yes";
	else{
		bool flag = false;
		for (i = 0; i < s.size(); i++){
			cnt[s[i] - 'a']++;
			if (cnt[s[i] - 'a']>1) flag = true;
			
		}
		if (flag) cout << "Yes";
		else cout << "No";
	}

	return 0;
}
