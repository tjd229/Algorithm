//implementation

#include <iostream>
#include <string>
using namespace std;
string coin[20];
int N;
int min(int a, int b){ return a < b ? a : b; }
int swap(int row){
	if (row == N){
		int i, j;
		int ans = 0;
		for (j = 0; j < N; j++){
			int cnt = 0;
			for (i = 0; i < N; i++){
				cnt += coin[i][j] == 'T';
			}
			if (cnt + cnt > N) cnt = N - cnt;
			ans += cnt;
		}
		return ans;
	}
	for (int j = 0; j < N; j++) coin[row][j] = coin[row][j] == 'H' ? 'T' : 'H';
	int ans = swap(row + 1);
	for (int j = 0; j < N; j++) coin[row][j] = coin[row][j] == 'H' ? 'T' : 'H';
	ans = min(ans, swap(row + 1));
	return ans;
	
	
}
int main(){
	int i;
	cin >> N;
	for (i = 0; i < N; i++) cin >> coin[i];
	cout << swap(0);
}
