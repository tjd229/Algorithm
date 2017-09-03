//category : ft

#include <stdio.h>
#include <vector>
using namespace std;
#define LEAF (1<<17)
int st[LEAF + LEAF];
vector<int> v;
void update(int ix, int diff){
	while (ix != 0){
		st[ix] += diff;
		ix = (ix >> 1);
	}
}

int find_kth(int ix, int k){
	if (ix >= LEAF) return ix-LEAF+1;
	if (st[ix + ix] >= k) return find_kth(ix + ix, k);
	else return find_kth(ix + ix + 1, k - st[ix + ix]);
}
int main(){
	int N, M;
	int i,k;
	int ix;
	scanf("%d%d", &N, &M);
	k = M;
	for (i = 0; i < N; i++) update(LEAF + i, 1);
	for (i = N; i !=0; i--){
		while (i < k) k -= i;
		ix = find_kth(1, k);
		update(LEAF + ix - 1, -1);
		v.push_back(ix);
		k += M - 1;
	}
	printf("<");
	for (i = 0; i < N; i++){
		if (i != 0) printf(", ");
		printf("%d", v[i]);
	}printf(">");
	return 0;
}
