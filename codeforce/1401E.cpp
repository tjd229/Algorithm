//graph, geometry, st
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
struct Tuple {
	int x, y, z;
	bool operator<(Tuple &t) const{
		if (x == t.x) {
			if (y == t.y) return z < t.z;
			return y < t.y;
		}
		return x < t.x;
	}
};
const int LEAF = 1 << 20;
const int M = 1e6;
int st[LEAF + LEAF];
void upd(int ix, int val) {
	while (ix) {
		st[ix] += val;
		ix >>= 1;
	}
}
int sum(int ix, int s, int e, int from, int to) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	return sum(ix + ix, s, (s + e) >> 1, from, to) + sum(ix + ix + 1, ((s + e) >> 1) + 1, e, from, to);
}
int main() {
	int i, n, m;
	vector<Tuple> evt;
	for (scanf("%d%d", &n, &m), i = 0; i < n; ++i) {
		int y, lx, rx; scanf("%d%d%d",&y,&lx,&rx);
		evt.push_back({ lx,1,y }); evt.push_back({ rx,2,y });
	}
	evt.push_back({ 0,1,0 }); evt.push_back({ M, 2, 0 });
	evt.push_back({ 0,1,M }); evt.push_back({ M, 2, M });
	for (i = 0; i < m; ++i) {
		int x, ly, ry; scanf("%d%d%d",&x,&ly,&ry);
		int y = ly == 0 ? ry : -ly;
		evt.push_back({x,0,y});
	}
	evt.push_back({ 0,0,M }); evt.push_back({M,0,M});
	sort(evt.begin(), evt.end());
	ll v = 0, e = 0;
	for (i = 0; i < evt.size(); ) {
		int t = evt[i].x;
		int v_evt = evt[i].y == 0? i++:-1;
		int from = -1, to = -1;
		int tmp = 0;
		if (v_evt >= 0) {
			int y = evt[v_evt].z;
			from = 0, to = M;
			if (y < 0) from =  -y;
			else to = y;
			int cnt = sum(1, 0, LEAF - 1, from, to);
			e += cnt;//h_e
			v += cnt + 2;
			e += cnt+1;//v_e
			//printf("cnt:%d(%d~%d)\n",cnt,from,to);
		}
 
		
		while (i < evt.size() && t == evt[i].x &&evt[i].y==1) { //open			
			int y = evt[i].z;
			++v;
			upd(LEAF + y, 1);
			if (from <= y && y <= to) ++e;//v_e
			++i;
		}
		if (v_evt >= 0) {
			if (st[LEAF + from]) --v,--e;
			if (st[LEAF + to]) --v,--e;
		}
		while (i < evt.size() && t == evt[i].x &&evt[i].y == 2) { //close
			int y = evt[i].z;
			upd(LEAF + y, -1);
			if (y < from || to < y) {
				++v;
				++e; //h_e
			}			
			++i;
		}
		
	}
	//e -= 2;//start,end
	//e += 2;
	//printf("v:%d,e:%d\n",v,e);
	printf("%I64d", 1 - v + e);
 
	return 0;
}