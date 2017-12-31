//category : string

#include <iostream>
#include <string>
using namespace std;
int cnt_A[101];
int cnt_Q[101];
int main(){
	int i,j;
	int a, q;
	long long ans = 0;
	string s;
	cin >> s;
	a = q = 0;
	for (i = s.size() - 1; i >= 0; i--){
		if (s[i] == 'A'){
			cnt_Q[i] = q;
			a++;
		}
		if (s[i] == 'Q'){
			q++;
			cnt_A[i] = a;
		}
		
	}
	for (i = 0; i < s.size(); i++){
		if (s[i] == 'Q'){
			for (j = i + 1; j < s.size(); j++){
				if (s[j] == 'A'){
					ans += cnt_Q[j];
				}
			}
		}
	}
	cout << ans;
	return 0;
}
