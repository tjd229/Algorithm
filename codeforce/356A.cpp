//category : st, lazy propagation

#include <stdio.h>
#include <utility>
#define LEAF (1<<19)
using namespace std;
int st[1 << 20];
int l[LEAF], r[LEAF], x[LEAF];
pair<int, int> get_range(int ix,int depth){
	int s = 1 << depth;
	int d = LEAF / s;
	int l = (ix - s)*d;
	return make_pair(1+l, l + d);
}

void update(int ix, int depth, int l, int r, int val){
	pair<int, int> p = get_range(ix, depth);

	if (l > p.second || r < p.first) return;
	if (l <= p.first&&r >= p.second){		
		st[ix] = val;
		return;
	}
	else if (st[ix] != 0){
		update(ix + ix, depth + 1, p.first, (p.first + p.second) / 2, st[ix]);		//range of next node is fit => O(1)
		update(ix + ix + 1, depth + 1, (p.first + p.second) / 2 + 1, p.second, st[ix]);
		st[ix] = 0;
	}
	update(ix + ix, depth + 1, l,r, val);
	update(ix + ix + 1, depth + 1, l, r, val);
}
void print(int ix, int depth, int l, int r){
	pair<int, int> p = get_range(ix, depth);
	if (l>r || p.first > r || p.second < l) return;
	if (st[ix] != 0){
		for (int i = p.first; i <= p.second; i++) printf("%d ",st[ix]==-1? 0:st[ix]);
		return;
	}
	print(ix + ix, depth + 1,l,r);
	print(ix + ix+1, depth + 1,l,r);
}
int main(){
	int i;
	int n, m;
	scanf("%d%d",&n,&m);
	for (i = 0; i < m; i++){
		scanf("%d%d%d",l+i,r+i,x+i);
	}
	update(1, 0, x[m-1], x[m-1], -1);

	while (m--){
		update(1, 0, l[m], x[m] - 1, x[m]);
		update(1, 0, x[m]+1, r[m], x[m]);

	}
	print(1,0,1,n);
	return 0;
}