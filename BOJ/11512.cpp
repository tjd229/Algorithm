//category : graph, tdp

#include <stdio.h>
#include <bitset>
#include <vector>
#define pii pair<int,int>
using namespace std;
int V[10001];
vector<int> edge[10001];
vector<pii > range[10001];
bitset<101> tor[101], tol[101];
void dfs(int ix,int from){
	int i,j;
	int l, r;
	for (i = 0; i < edge[ix].size(); i++) if (edge[ix][i] != from) dfs(edge[ix][i], ix);
	for (i = 1; i <= 100; i++) tor[i].reset(), tol[i].reset();
	for (i = 0; i < edge[ix].size(); i++){
		int to = edge[ix][i];
        if(to==from) continue;
		for (j = 0; j < range[to].size(); j++){
			l = range[to][j].first;
			r = range[to][j].second;
			tor[l][r] = 1;
			tol[r][l] = 1;
		}
	}
	bitset<101> L, R;
	L[V[ix]]=1;
	R[V[ix]] = 1;
	for (i = V[ix]; i < 100; i++) if(R[i]) R |= tor[i + 1];
	for (i = V[ix]; i >1; i--) if(L[i]) L |= tol[i - 1];
	for (i = 1; i <= 100; i++){
		if (L[i] == 0) continue;
		for (j = i; j <= 100; j++){
			if (R[j]) range[ix].push_back({i,j});
		}
	}
}
int main(){
	int i;
	int N;
	int A, B;
	for (scanf("%d", &N), i = 1; i <= N; i++) scanf("%d",V+i);
	for (i = 1; i < N; i++){
		scanf("%d%d",&A,&B);
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	dfs(1, 0);
	printf("%d",range[1].size());

	return 0;
}
