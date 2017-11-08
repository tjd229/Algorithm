//category : djs

#include <stdio.h>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
int mat[601][601];
int V[601][601];
int H[601][601];
int lc[601][601];
int p[601];
int sz[601];
int N, M;
int find(int a){
	if (p[a] != a) p[a]=find(p[a]);
	return p[a];
}
void join(int a,int b,int *sz){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	sz[a] += sz[b];
}
int histo(int col){
	int i;
	bool cover[602] = { false };
	int res = 0;
	vector<pii > v;
	for (i = 0; i < N; i++){
		v.push_back(mp(lc[i][col],i+1));
		p[i+1] = i+1;
		sz[i + 1] = 1;
	}
	sort(v.begin(), v.end());
	while (!v.empty()){
		if (v.back().first == 1) break;
		
		i = v.back().second;
		if (cover[i + 1]) join(i,i+1,sz);
		if (cover[i - 1]) join(i - 1, i, sz);
		cover[i] = true;
		res = max(res, (sz[find(i)]+1) * v.back().first);
		v.pop_back();
	}
	return res;

}

int main(){
	int i, j;
	
	int ans;
	while (scanf("%d%d", &N, &M)){
		if (N + M == 0) break;
		ans = 0;
		for (i = 0; i < N; i++){
			for (j = 0; j < M; j++)
				scanf("%d", &mat[i][j]), mat[i + 1][j] = -1e7;
			mat[i][j] = -1e7;
		}
		for (i = N - 1; i >= 0; i--){
			
			for (j = M - 1; j >= 0; j--){
				if (mat[i][j] < mat[i][j + 1]) H[i][j] = H[i][j+1]+1;
				else H[i][j] = 1;
				if (mat[i][j] < mat[i + 1][j]){
					V[i][j] = V[i + 1][j] + 1;
					int *it = lower_bound(mat[i]+j,mat[i]+j+H[i][j],mat[i+1][j]);
					it--;
					int len = it - (mat[i] + j) + 1;
					lc[i][j] = min(len,H[i+1][j]);

				}
				else V[i][j] = lc[i][j] = 1;
				ans = max(ans, V[i][j]);
				ans = max(ans, H[i][j]);

			}
		}
		for (i = 0; i < M; i++){
			ans = max(ans, histo(i));
		}


		printf("%d\n",ans);
	}

	return 0;
}

