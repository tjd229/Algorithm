//string

#include <iostream>
#include <string>
using namespace std;
string s;
int cnt[26];
bool p(int l,int r){
	while (l <= r){
		if (s[l] != s[r]) return false;
		++l;
		--r;
	}
	return true;
}
int main(){
	int n;
	cin >> n >> s;
	int ans = 0;
	string str = "";
	for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++){
		while (cnt[i]){
			str += 'a' + i;
			--cnt[i];
		}
	}
	cout << str;
	return 0;
}
