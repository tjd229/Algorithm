//implementation

#include <iostream>
#include <string>
using namespace std;
char pos[2001];
string bird[2001];
int mv[2001];
int main(){
	int i, j;
	int N, M;
	int dis = 3000 * 3000;
	int ans = 0;
	cin >> N >> M;
	for (i = 1; i <= N; i++){
		cin >> pos[i] >> bird[i];
		int sign = 1;
		if (pos[i] == 'L') sign = -1;
		for (j = 0; j < M; j++){
			if (bird[i][j] == '1') mv[j] += sign * 1;
		}
	}
	for (i = 1; i <= N; i++){
		int curr = 0;
		int mx = 0;
		int sign = 1;
		if (pos[i] == 'L') sign = -1;
		for (j = 0; j < M; j++){
			curr += mv[j] - sign*(bird[i][j] == '1');
			int acurr = curr;
			if (acurr < 0) acurr = -acurr;
			if (acurr > mx) mx=acurr;
		}
		if (mx < dis){
			dis = mx;
			ans = i;
		}
	}
	cout << ans << "\n" << dis;
	return 0;
}
