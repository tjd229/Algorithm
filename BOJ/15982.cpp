//st

#include <stdio.h>
#include <set>
using namespace std;
const int leaf = 1 << 18;
int st[leaf + leaf];
int s[100001],cow[100001];
set<int> pos[200002];
int max(int a, int b){ return a < b ? b : a; }
void update(int ix, int val){
	st[ix] = val;
	ix >>= 1;
	while (ix){
		st[ix] = max(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
int main(){
	int i;
	int N, M;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; ++i){
		scanf("%d",cow+i);
		if (!cow[i]) --cow[i];
		s[i] = s[i - 1] + cow[i];
	}
	for (i = 0; i <= N; ++i) pos[N + s[i]].insert(i);
	for (i = 0; i <= N; i++){
		if (pos[i].size()){
			auto l = pos[i].begin();
			auto r = pos[i].end();
			update(i + leaf, *(--r) - *l);			
		}
		if (pos[i+N].size()){
			auto l = pos[i+N].begin();
			auto r = pos[i+N].end();
			update(i + N+leaf, *(--r) - *l);
		}
	}
	printf("%d",st[1]);
	while (M--){
		int P;
		scanf("%d",&P);
		if (cow[P] != cow[P + 1]){
			cow[P] ^= cow[P + 1] ^= cow[P] ^= cow[P + 1];
			pos[s[P] + N].erase(P);
			if (pos[s[P] + N].size()){
				auto l = pos[s[P] + N].begin();
				auto r = pos[s[P] + N].end();
				update(s[P] + N + leaf, *(--r) - *l);
			}
			else update(s[P] + N + leaf, 0);
			s[P] = s[P - 1] + cow[P];
			pos[s[P] + N].insert(P);
			auto l = pos[s[P] + N].begin();
			auto r = pos[s[P] + N].end();
			update(s[P] + N + leaf, *(--r) - *l);
		}
		printf("\n%d",st[1]);
	}
	return 0;
}
