//ft
#include <stdio.h>
#include <memory.h>
#include <map>
using namespace std;
const int LEAF = 1 << 19;
int pt[100001];
int ft[LEAF];
char qry[200000];
int j[200000], k[200000];
void upd(int ix,int val) {
	for (; ix < LEAF; ix += (ix & -ix)) ft[ix] += val;
}
int sum(int ix) {
	int s = 0;
	for (; ix > 0; ix -= (ix&-ix)) s += ft[ix];
	return s;
}
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, N, M;
		map<int, int> mp;
		memset(ft, 0, sizeof(ft));
		for (scanf("%d%d", &N, &M),i=1;i<=N;++i) 
			pt[i] = 0;
		mp[0] = 1;
		for (i = 0; i < M; ++i) {
			scanf(" %c",qry+i);
			if (qry[i] == 'Q') scanf("%d",j+i);
			else {
				scanf("%d%d",j+i,k+i);
				pt[j[i]] += k[i];
				mp[pt[j[i]]] = 1;
			}
		}
		int order = 0;
		for (auto &it : mp) 
			it.second = ++order;
		upd(1, N); memset(pt, 0, sizeof(int)*(N + 1));
		for (i = 0; i < M; ++i) {
			if (qry[i] == 'Q')
				printf("%d\n",1+N-sum(mp[pt[j[i]]] ));
			else {
				upd(mp[pt[j[i]]], -1);
				pt[j[i]] += k[i];
				upd(mp[pt[j[i]]], 1);
			}
		}
		
	}

	return 0;
}