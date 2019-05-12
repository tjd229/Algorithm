//game, graph
#include "coprobber.h"
#include <queue>
using namespace std;
struct Tuple { int x, y, z; };
int mv[500][500];
int vis[500][500][2];
int d[500];
int opt[500][500];
int C;
int start(int N, bool A[MAX_N][MAX_N])
{
	queue<Tuple> q;
	for (int i = 0; i < N; ++i) {
		q.push({ i,i,0 }); q.push({ i,i,1 });
		vis[i][i][0] = 1; vis[i][i][1] = 1;
		for (int j = 0; j < N; ++j) d[i] += A[i][j];
	}
	while (q.size()) {
		Tuple t = q.front(); q.pop();
		C = t.x; int R = t.y; int z = t.z;
		if (z) {
			for (int i = 0; i < N; ++i) {//deg chk
				if (A[R][i] == 0) continue;
				if (vis[C][i][0]) continue;
				if (++opt[C][i]==d[i]) {
					vis[C][i][0] = 1;
					q.push({ C,i,0 });
				}
			}
		}
		else {
			for (int i = 0; i < N; ++i) {				
				if (i != C && A[C][i] == 0) continue;
				if (vis[i][R][1]) continue;
				vis[i][R][1] = 1;
				mv[i][R] = C;
				q.push({ i,R,1 });
			}
		}
	}
	for (C = 0; C < N; ++C) {
		bool flag = 1;
		for (int i = 0; i < N; ++i) 
			if(i!=C)
				flag &= vis[C][i][1];//i==C?
		if (flag) return C;
	}
    return -1;
}
int nextMove(int R)
{
	C = mv[C][R];
    return C;
}
