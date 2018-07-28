//implementation

#include <iostream>
#include <string>
using namespace std;
string a, b;
int main(){
	int i,j;
	int n;
	int cnt = 0;
	int half = 0;
	cin >> n >> a >> b;
	half = (n >> 1);
	for (i = 0; i < half; i++){
		int hist[26] = { 0 };
		int mx = 0;
		hist[a[i] - 'a']++;
		hist[a[n - 1 - i] - 'a']++;
		hist[b[i] - 'a']++;
		hist[b[n - 1 - i] - 'a']++;
		for (j = 0; j < 26; j++){
			if (hist[j] > mx) mx = hist[j];
		}
		if (mx == 3) cnt++;
		else if (mx == 1) cnt+=2;
		else if (mx == 2){
			if ((1 << (a[i] - 'a')) ^ (1 << (a[n-1-i] - 'a')) ^( 1 << (b[i] - 'a')) ^ (1 << (b[n-1-i] - 'a'))){
				cnt++;
				cnt += (a[i] == a[n - 1 - i]);
			}
			
		}

		//cout << i << "," << mx << "," << cnt << endl;
	}
	//cnt >>= 1;
	if (n & 1 && a[half] != b[half]) cnt++;
	cout << cnt;
	return 0;
}
