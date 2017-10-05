//category : pbs, merge st
//reference : http://codeforces.com/contest/484/submission/21340351


#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX(a,b) a<b? b:a
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
const int LEAF = 1 << 17;
vector<int> query[(int)1e5];
pii fence[LEAF];
int left[LEAF], right[LEAF], mid[LEAF];
int l[LEAF], r[LEAF], w[LEAF];
struct Node{
	int from_l, from_r, range, val;
	void init(int n){
		from_l = from_r = val = n;
		range = 1;
	}
}node[LEAF + LEAF];
Node mrg(Node l, Node r){
	Node n;
	n.from_l = l.from_l;	//s~m
	if (l.range == l.from_l) n.from_l += r.from_l;	//s~m~r'
	n.from_r = r.from_r;	//m~e
	if (r.range == r.from_r) n.from_r += l.from_r;	//l'~m~e
	n.val = MAX(l.val, r.val);
	n.val = MAX(n.val, l.from_r + r.from_l);	//s~m or m~e or l'~r'
	n.range = l.range + r.range;
	return n;
}
void init(int ix, int s, int e, int from, int to){
	if (e < from || to < s) return;
	if (ix >= LEAF){
		node[ix].init(0);
		return;
	}
	init(ix + ix, s, (s + e) >> 1, from, to);
	init(1 + ix + ix, 1 + ((s + e) >> 1), e, from, to);
	node[ix] = mrg(node[ix + ix], node[ix + ix + 1]);
}
void update(int ix){
	node[ix].init(1);
	ix >>= 1;
	while (ix != 0){
		node[ix] = mrg(node[ix + ix], node[ix + ix + 1]);
		ix >>= 1;
	}
}
Node measure(int ix, int s, int e, int from, int to){
	if (e < from || to < s) return{ 0, 0, 0, 0 };
	if (s >= from&&to >= e) return node[ix];
	Node l = measure(ix + ix, s, (s + e) >> 1, from, to);
	Node r = measure(1 + ix + ix, 1 + ((s + e) >> 1), e, from, to);
	return mrg(l, r);
}

int main(){
	int i, j;
	int n;
	int m;
	int h;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &h);
		fence[i] = mp(-h, i);
	}
	sort(fence, fence + n);
	scanf("%d", &m);
	for (i = 0; i < m; i++){
		scanf("%d%d%d", l + i, r + i, w + i);
		right[i] = n - 1;
	}

	bool x;
	while (true){
		x = true;
		init(1, 0, LEAF - 1, 0, n - 1);

		for (i = 0; i < m; i++){
			if (left[i] <= right[i]){
				mid[i] = (left[i] + right[i]) >> 1;
				query[mid[i]].pb(i);
				x = false;
			}
		}
		if (x) break;
		for (i = 0; i < n; i++){
			update(LEAF + fence[i].second);
			while (!query[i].empty()){
				j = query[i].back();
				query[i].pop_back();
				Node n = measure(1, 0, LEAF - 1, l[j]-1, r[j]-1);

				if (n.val >= w[j]){
					right[j] = mid[j] - 1;
				}
				else left[j] = mid[j] + 1;
			}
		}
	}
	for (i = 0; i < m; i++){
		printf("%d\n", -fence[right[i] + 1].first);
	}
	return 0;
}