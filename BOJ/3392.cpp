//category : st, line sweeping


#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int LEAF = 1 << 15;
struct Sq{
	int val, x, y1, y2;
	bool operator<(Sq sq) const{
		if (sq.x == x) return val < sq.val;
		return x < sq.x;
	}
};
vector<Sq> evt;
int st[LEAF + LEAF], cover[LEAF + LEAF];
void update(int ix,int s,int e,int from,int to,int val){
	if (e < from || to < s) return;
	if (from <= s&&e <= to){
		cover[ix]+=val;
	}
	else{
		update(ix + ix, s, ((s + e) >> 1), from, to, val);
		update(1 + ix + ix, 1 + ((s + e) >> 1), e, from, to, val);
	}
	if (cover[ix]) st[ix] = e - s + 1;
	else{
		st[ix] = 0;
		if (ix<LEAF)
			st[ix] = st[ix + ix] + st[ix + ix + 1];
	}
}
int main(){
	int i;
	int N;
	int x1, x2, y1, y2;
	ll ans = 0;
	for (scanf("%d", &N);N--;){
		Sq sq;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		sq.x = x1;
		sq.y1 = y1;
		sq.y2 = y2;
		sq.val = 1;
		evt.push_back(sq);
		sq.x = x2;
		sq.val = -1;
		evt.push_back(sq);
	}
	sort(evt.begin(), evt.end());
	x1 = evt[0].x;
	for (i = 0; i < evt.size(); i++){
		ans += (evt[i].x - x1)*(ll)st[1];
		update(1, 0, LEAF-1, evt[i].y1, evt[i].y2-1, evt[i].val);
		x1 = evt[i].x;
	}
	printf("%lld",ans);

	return 0;
}