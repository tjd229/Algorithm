//implementation

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int A[11][11];
int src[11][11], death[11][11];
int born[12][12];
vector<int> tree[11][11];
int main() {
	int i, j, k;
	int x, y, z;
	for (scanf("%d%d%d", &N, &M, &K), i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			scanf("%d", A[i] + j);
			src[i][j] = 5;
		}
	}
	for (i = 0; i < M; ++i) {
		scanf("%d%d%d",&x,&y,&z);
		tree[x][y].push_back(z);
	}
	while (K--) {
		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= N; ++j) {
				sort(tree[i][j].begin(), tree[i][j].end());
				int &r = src[i][j];
				vector<int> &v = tree[i][j];
				z = 0;
				for (k = 0; k < v.size(); ++k) {
					if (v[k] <= r) { //spr
						r -= v[k];
						++z;
						++v[k];
					}
					else {  //summer
						death[i][j] += (v[k] >> 1);
					}
				}
				v.resize(z);
				for (auto age : v) {//aut
					if (age % 5 == 0) {
						for (y = -1; y <= 1; ++y) {
							for (x = -1; x <= 1; ++x) {
								if (x==0 && y==0) continue;
								++born[i + x][j + y];
							}
						}
					}
				}
			}
		}
		for (i = 1; i <= N; ++i) {//win & init
			for (j = 1; j <= N; ++j) {
				src[i][j] += A[i][j] + death[i][j];
				death[i][j] = 0;
				int &baby = born[i][j];
				while (baby--) tree[i][j].push_back(1);
				baby = 0;
			}
		}
	}
	int ans = 0;
	for (i = 1; i <= N; ++i) for (j = 1; j <= N; ++j) ans += tree[i][j].size();
	printf("%d",ans);
	return 0;
}
