//string

#include <string>
#include <iostream>
using namespace std;

int main(){
	int T;
	int i;
	int n;
	string s;
	cin >> T;
	while (T--){
		cin >> n >> s;
		int l = 0;
		int r = s.size() - 1;
		bool flag = true;
		while (l <= r){
			int d = s[l] - s[r];
			if (d < 0) d = -d;
			if (d!=2 && d!=0){
				//if (!((s[l] == 'a' && s[r] == 'z') || (s[l] == 'z'&&s[r] == 'a'))){
					flag = false;
					break;
				//}
			}	
			l++; r--;

		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
