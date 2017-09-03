//category : dp

#include <iostream>
#include <string>

using namespace std;
string s;
int p[2501][2501];
int d[2501];
int min(int a, int b){ return a < b ? a : b; }
int main(){
	int i, j;
	cin >> s;	
	
	for (i = 0; i < s.size(); i++){
		d[i] = i;
		for (j = 1; j <= s.size() - i; j++){
			
			if (s[j-1] != s[j + i-1]) continue;
			if (i>1 && p[j + 1][j + i - 1] != 1) continue;
			p[j][j + i] = 1;
		}
	}
	d[i] = i;
	
	for (i = 1; i <= s.size(); i++){
		for (j = i; j >= 1; j--){
			if (p[j][i] != 1) continue;
			d[i] = min(d[i],d[j - 1] + 1);
		}
	}
	
	cout << d[s.size()];
	return 0;
}
