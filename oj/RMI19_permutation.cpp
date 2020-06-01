//implementation, math
#include  "permutation.h"
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;
 
 
int Tx[257], x[257+257];
int use[257];
int _N;
 
 
bool recon(int ix, int depth,vector<int> &P) {
 
	int bk = P.back();
	
	//
	if (depth == _N) {
		int d = bk - P[0];
		if (d < 0) d = -d;
		return d == x[ix+1];
	}
	int nxt = bk + x[ix + 1];
	if (nxt <= _N && use[nxt] == 0) {
		use[nxt] = 1;
		P.push_back(nxt);
		if (recon(ix + 1, depth+1,P)) return 1;
		P.pop_back();
		use[nxt] = 0;
	}
	nxt = bk - x[ix + 1];
	if (nxt > 0 && use[nxt] == 0) {
		use[nxt] = 1;
		P.push_back(nxt);
		if (recon(ix + 1, depth+1,P)) return 1;
		P.pop_back();
		use[nxt] = 0;
	}
	return 0;
}
void solve(int N) {
	_N = N;
	int sum = 0;
	vector<int> P, V;
	for (int i = 1; i <= N; ++i) V.push_back(i);
	/*mt19937 g(random_device);
	shuffle(V.begin(), V.end(),g);*/
	srand(time(0));
	random_shuffle(V.begin(), V.end());
 
	for (int i = 1; i <= N; ++i) {
		Tx[i] = query(V);
		sum += Tx[i];
		use[i] = 0;
		int bk = V[0];
		for (int j = 1; j < N; ++j) V[j - 1] = V[j];
		V.back() = bk;
	}
	int T = sum / (N - 1);
	int mx = -1;
	int src = 0;
	for (int i = 1; i <= N; ++i) {
		x[N + i]=x[i] = T - Tx[i];
		
		if (mx < x[i]) {
			mx = x[i];
			src = i - 1;
		}
	}
	if (src == 0) src = N;
	
 
	for (int i = 1; i <= N; ++i) {
		//continue;
		if (i + x[src] > N && i - x[src] < 1) continue;
		//printf("%d,%d\n",i,x[src]);
		P.push_back(i); use[i] = 1;
		
		if (recon(src,1, P)) {
			vector<int> ans(N);
			for (i = 0; i < N; ++i)
				ans[V[(src+i-1)%N] - 1] = P[i];
				//ans[V[i] - 1] = P[i];// , printf("%d,%d\n", V[i], P[i]);
 
			answer(ans);
			return;
		}
		P.pop_back(); use[i] = 0;
	}
}