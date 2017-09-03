//category : greedy

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int k;
string ans;
int cnt[26];
bool generate(int a,int r){
	int i, j;
	if (a == 26 && r != 0) return false;
	if (r == 0){
		for (i = 0; i < 26; i++){
			for (j = 0; j < cnt[i]; j++)
				ans += (char)('a' + i);

		}
		cout << ans;
		return true;
	}
	for (int i = 1; i <= 452; i++){
		if (i*(i + 1) / 2>r)break;
		cnt[a]=i+1;
		if (generate(a + 1, r - (i*(i + 1)) / 2)) return true;
		cnt[a] = 0;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	if (k == 0){
		cout << "a";
		return 0;
	}
	if (k == 1){
		cout << "aa";
		return 0;
	}
	generate(0, k);
	return 0;
}