//category : implementation

#include <string>
#include <iostream>
using namespace std;
int bulb[12][12];
int sim(int init){
	int i, j;
	int cnt = 0;
	int on=0;
	int stat[12][12] = { 0 };
	for (i = 1; i <= 10; i++){
		for (j = 1; j <= 10; j++){
			stat[i][j] = bulb[i][j];
		}
	}
	for (i =j=1; i <= 10; i++,j<<=1){
		if (init&j){
			cnt++;
			stat[1][i] ^= 1;
			stat[2][i] ^= 1;
			stat[1][i + 1] ^= 1;
			stat[1][i - 1] ^= 1;
		}
	}
	for (i = 2; i <= 10; i++){
		for (j = 1; j <= 10; j++){
			if (stat[i - 1][j] == 1){
				cnt++;
				stat[i][j] ^= 1;
				stat[i][j-1] ^= 1;
				stat[i][j+1] ^= 1;
				stat[i-1][j] ^= 1;
				stat[i+1][j] ^= 1;
			}
		}
	}
	for (i = 1; i <= 10; i++){
		for (j = 1; j <= 10; j++)
			on += stat[i][j];
	}
	return on == 0 ? cnt : 1e9;
}
int main(){
	int i,j;
	int ans = 1e9;
	int res;
	string s;
	for (i = 1; i <= 10; i++){
		cin >> s;
		for (j = 0; j < 10; j++)
			bulb[i][j + 1] = s[j] == 'O';
	}
	for (i = 0, j = 1 << 10; i < j; i++){
		res = sim(i);
		if (ans > res) ans = res;
	}
	if (ans == 1e9) ans = -1;
	cout << ans;
	return 0;
}
