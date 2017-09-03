//category : st

#include <stdio.h>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#define LEAF (1<<18)
//#define LEAF (1<<3)
using namespace std;
struct Laser{
	int a;
	int b;
	int w;
	int ix;
};
struct Ship{
	int x1, x2, y1, y2;
	int w;
};
Ship s[200000];
Laser lay[200000];
int st[2][1<<19];
//int st[2][1 << 4];
int min(int a, int b){ return a > b ? b : a; }
pair<int, int> get_range(int ix, int depth){
	int s = 1 << depth;
	int d = LEAF / s;
	int l = (ix - s)*d;
	return make_pair(1 + l, l + d);
}
void init(int b,int ix){
	if (ix >= LEAF){
		if (st[b][ix] == 0) st[b][ix] = LEAF;
		return;
	}
	init(b,ix + ix);
	init(b,ix + ix + 1);
	st[b][ix] = min(st[b][ix + ix], st[b][ix + ix + 1]);
}
int get_min(int b,int ix,int depth,int l,int r){
	pair<int, int> p = get_range(ix, depth);
	if (l > p.second || r < p.first) return LEAF;
	if (l <= p.first&&r >= p.second){
		return st[b][ix];
	}
	return min(get_min(b, ix + ix, depth + 1, l, r), get_min(b, ix + ix + 1, depth + 1, l, r));
}
int main(){
	int i,j;
	int T;
	int n, k, l;
	int x1, x2, y1, y2;
	int w;
	int a, b;
	//b=0(-):y b=1(|):x
	for (scanf("%d", &T); T--;){
		scanf("%d%d%d", &n, &k, &l);
		memset(st,0,sizeof(st));
		map<int, int> m[2];
		vector<int> v[2];
		for (i = 0; i < k; i++){
			scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &w);
			s[i].x2 = -min(-x1, -x2);
			s[i].x1 = min(x1, x2);
			s[i].y2 = -min(-y1, -y2);
			s[i].y1 = min(y1, y2);
			s[i].w = w;
			v[0].push_back(y1);
			v[0].push_back(y2);
			v[1].push_back(x1);
			v[1].push_back(x2);
		}
		for (i = 0; i < l; i++){
			scanf("%d%d",&a,&b);
			lay[i].a = a;
			lay[i].b = b;
			lay[i].w = 0;
			lay[i].ix = i;
			v[b].push_back(a);
		}
		
		for (i = 0; i < 2; i++){
			sort(v[i].begin(), v[i].end());
			auto end = unique(v[i].begin(), v[i].end());

			j = 1;
			for (auto ptr=v[i].begin(); ptr!=end; ptr++){
				if (m[i].find(*ptr) == m[i].end()){
					m[i].insert(make_pair(*ptr,j++));
				}
			}
		}
		for (i = 0; i < l; i++){
			a = m[lay[i].b][lay[i].a];
			if (st[lay[i].b][LEAF + a - 1]==0)
				st[lay[i].b][LEAF + a - 1] = i+1;
		}
		init(0, 1);
		init(1, 1);

		for (i = 0; i < k; i++){
			j = min(get_min(0, 1, 0, m[0][s[i].y1], m[0][s[i].y2]), get_min(1, 1, 0, m[1][s[i].x1], m[1][s[i].x2]));

			if (j!=LEAF)
				lay[j-1].w = -min(-lay[j-1].w, -s[i].w);
		}
		for (i = 0; i < l; i++){
			printf("%d\n",lay[i].w);
		}
	}
	return 0;
}
