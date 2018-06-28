//category : implementation

#include <iostream>
#include <string>
using namespace std;
int n, m, k;
string mat[2000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	int cnt = 0;
	int ans = 0;
	cin >> n >> m >> k;
	for (i = 0; i < n; i++){
		cin >> mat[i];
		for (j = 0; j < m; j++){
			if (mat[i][j] == '.') cnt++;
			else{
				cnt -= k - 1;
				if (cnt > 0) ans += cnt;
				cnt = 0;
			}
		}
		cnt -= k - 1;
		if (cnt > 0) ans += cnt;
		cnt = 0;
	}
	for (j = 0; j < m; j++){
		for (i = 0; i < n; i++){
			if (mat[i][j] == '.') cnt++;
			else{
				cnt -= k - 1;
				if (cnt > 0) ans += cnt;
				cnt = 0;
			}
		}
		cnt -= k - 1;
		if (cnt > 0) ans += cnt;
		cnt = 0;
	}
	if (k == 1) ans >>= 1;
	cout << ans;

	return 0;
}
