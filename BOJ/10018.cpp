//category : st, line sweeping


#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using namespace std;
const int LEAF = 1 << 18;
struct Sq{
	int x, y1,y2, g;
	bool operator<(Sq sq) const{
		if (x == sq.x) return g>sq.g;
		return x < sq.x;
	}
};
vector<Sq> evt;
vector<int> comp_y;
ll cover[LEAF + LEAF], grass[LEAF + LEAF];
int get_comp(int val){
	return lower_bound(comp_y.begin(), comp_y.end(), val) - comp_y.begin() + 1;
}
void update(int ix,int s,int e,int from,int to,int val){
	if (e<from || s>to) return;
	ll g = 0;
	if (from <= s&&e <= to){
		cover[ix] += val;
	}
	else{
		update(ix + ix, s, ((s + e) >> 1), from, to, val);
		update(1 + ix + ix, 1 + ((s + e) >> 1), e, from, to, val);		
	}
	if (ix < LEAF){
		g = grass[ix + ix];
		if (g < grass[ix + ix + 1]) g = grass[ix + ix + 1];
	}
	grass[ix] = cover[ix] + g;
}
int main(){
	
	int i, j;
	int N, K;
	int x, y, g;
	ll ans = 0;
	scanf("%d%d",&N,&K);
	for (i = 0; i < N; i++){
		Sq sq;
		scanf("%d%d%d",&g,&x,&y);
		sq.x = x - y - K;
		sq.y1 = x + y - K;
		sq.y2 = x + y + K;
		sq.g = g;
		evt.pb(sq);
		sq.x = x - y + K;
		sq.g = -g;
		evt.pb(sq);
		comp_y.pb(sq.y1);
		comp_y.pb(sq.y2);
	}
	sort(evt.begin(), evt.end());
	sort(comp_y.begin(), comp_y.end());
	comp_y.erase(unique(comp_y.begin(), comp_y.end()), comp_y.end());
	for (i = 0; i < evt.size(); i++){
		evt[i].y1 = get_comp(evt[i].y1);
		evt[i].y2 = get_comp(evt[i].y2);
		update(1, 0,LEAF-1,evt[i].y1, evt[i].y2,evt[i].g);
		if (evt[i].g>0 && ans < grass[1]) ans = grass[1];
	}
	printf("%lld",ans);
	return 0;
}