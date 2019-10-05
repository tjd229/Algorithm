//https://programmers.co.kr/learn/courses/30/lessons/60059
//implementation
#include <string>
#include <vector>

using namespace std;
int N, M;
int b[20];//for lock
int gk[100][100];
void copy(int dir, vector<vector<int>> &key) {
	if (dir == 0) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				gk[i][j] = key[i][j];
		}
	}
	else if (dir == 1) {
		for (int j = N-1; j >=0; --j) {
			for (int i = 0; i < N; ++i) {
				gk[N-1-j][i] = key[i][j];
			}
		}
	}
	else if (dir == 2) {
		for (int i = N - 1; i >= 0; --i) {
			for (int j = N - 1; j >= 0; --j)
				gk[N - 1 - i][N - 1 - j] = key[i][j];
		}
	}
	else {
		for (int j = 0; j < N; ++j) {
			for (int i = N - 1; i >= 0; --i) {
				gk[j][N-1-i] = key[i][j];
			}
		}
	}
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int i, j;
	N = key.size(); M = lock.size();
	int NN = N + N;
	int MM = M + M;
	int mx = NN < MM ? MM : NN;
	int pad = mx >> 1;
	int sum = 0;
	int mask = (1 << M) - 1;
	for (int i = 0; i < M; ++i) {
		b[i] = 0;
		for (int j = 0; j < M; ++j) {
			b[i] += b[i] + (1-lock[i][j]);
			sum += lock[i][j];
		}		
	}
	if (sum == 0) return 1;//all 0 case
	for (int dir = 0; dir < 4; ++dir) {
		copy(dir, key);
		int h[60] = { 0 };
		for (int j = 0; j < mx; ++j) {
			for (int i = 0; i < N; ++i) {
				h[pad+i] += h[pad + i];
				h[pad + i] &= mask;
				h[pad + i] += gk[i][j];
				//cout << h[i] << endl;
			}//cout << "\n";
			for (int i = mx - 1; i >= 0; --i) {
				bool flag = 1;
				for (int k = 0; k < M &&flag; ++k) {//try
					flag &= h[i + k] == b[k];
				}
				if (flag)return 1;
			}
		}
	}
	return 0;
}