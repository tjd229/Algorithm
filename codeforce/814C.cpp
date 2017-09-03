//category : line sweeping

#include <iostream>
#include <string>
using namespace std;
int s[26][1501];
int table[26][1501];
int n, q;
int recolor(int m,int c){

	int l, r;
	int diff;
	int res = 0;
	l = r = 1;
	while (r <= n&&l <= r){
		diff = r - l + 1 - (s[c][r] - s[c][l - 1]);
		
		if (diff <= m){
			//cout << l << "," << r << endl;
			r++;
			if (res < r - l + 1) res = r - l + 1;
		}
		else{
			l++;
			if (l > r) l++;
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int i,j;
	int m;
	char c;
	string garland;
	
	cin >> n;
	cin >> garland;
	for (i = 0; i < n; i++){
		for (j = 0; j < 26; j++) s[j][i+1] = s[j][i];
		s[garland[i] - 'a'][i + 1] += 1;
	}
	for (i = 1; i <= n; i++){
		for (j = 0; j < 26; j++){
			table[j][i] = recolor(i,j)-1;
		}
	}


	cin >> q;
	for (i = 0; i < q; i++){
		cin >> m >> c;
		cout << table[c-'a'][m] << "\n";
	}
	return 0;
}