//string

#include <string>
#include <iostream>
using namespace std;

int main(){
	int i;
	string s;
	cin >> s;
	int len = 1;
	int ans = 0;
	char last = s[0];
	for (i = 1; i < s.size(); i++){
		if (last != s[i]) len++;
		else{
			if (ans < len) ans = len;
			len = 1;
		}
		last = s[i];
	}
	if (ans < len) ans = len;
	if (s.size() == 1){
		cout << 1;
		return 0;
	}
	if (s[0] != s[s.size() - 1]){
		len = 1;
		last = s[0];
		for (i = 1; i < s.size(); i++){
			if (last != s[i]) len++;
			else break;
			last = s[i];
		}
		int bnd = i;
		last = s[0];
		
		for (i = s.size() - 1; i >= bnd; i--){

			if (last != s[i]) len++;
			else break;
			last = s[i];
		}
		if (ans < len) ans = len;
	}
	cout << ans;

	return 0;
}
