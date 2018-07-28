//math

#include <iostream>
#include <string>
#include <random>
using namespace std;
int stat[2][32][32];
int ostat[32][32];
int t;
int N;
int last = -1;

int cnt(int ix){
	int i, j;
	int e = 0;
	for (j = 0; j < N; j++){
		int cnt = 0;
		for (i = 0; i < N; i++){
			cnt += stat[ix][i][j];
		}
		if (cnt + cnt > N) cnt = N - cnt;
		e += cnt;
	}
	return e;
}
int anneal(){
	int i, j;
	int row = last;
	while (last == row) row = rand() % N;

	for (i = 0; i < N; i++) for (j = 0; j < N; j++) stat[t ^ 1][i][j] = stat[t][i][j];
	for (j = 0; j < N; j++) stat[t ^ 1][row][j] ^= 1;

	
	return cnt(t^1);
}
int main(){
	srand(818);
	int i, j;
	int e1, e2;
	int ans = 33 * 33;
	double p = 0.005;
	string s;
	cin >> N;
	for (i = 0, e1 = 0; i < N; i++){
		cin >> s;
		int cnt = 0;
		for (j = 0; j < N; j++){
			ostat[i][j]=stat[0][i][j] = s[j] == 'T';
			cnt += stat[0][i][j];
		}
		if (cnt + cnt > N) cnt = N - cnt;
		e1 += cnt;
	}
	int loop = 229229;

	while (loop--){
		e2 = anneal();
		if (e1 > e2){
			e1 = e2;
			t ^= 1;
		}
		else if (rand() % 10000  < p*1e4){ //rand()%10000/1e4 <p
			for (i = 0; i < N; i++){
				int swap = rand() & 1;
				for (j = 0; j < N; j++) stat[t][i][j] = ostat[i][j] ^ swap;
			}
			e1 = cnt(t);
		}
		if (ans > e1) ans = e1;
	}



	cout << ans;
	return 0;
}
