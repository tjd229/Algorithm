//category : implementation

#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int cnt[26];
int main(){
	int i,j;
	int n;
	int val = 0;
	int ans = 0;
	string s;
	cin >> n;
	cin >> s;
	for (i = 0; i < n;i++){
		if (s[i] >= 'A'&&s[i] <= 'Z') continue;
		val = 0;
		memset(cnt, 0, sizeof(cnt));		
		for (j = i; j < n; j++){
			if (s[j] >= 'A'&&s[j] <= 'Z'){
				break;
			}
			if (cnt[s[j] - 'a'] == 0){
				val++;
			}
			cnt[s[j] - 'a']++;
			if (i==j||s[i] != s[j]){
				if (ans < val) ans = val;
			}
		}
	}
	cout << ans;
	return 0;
}