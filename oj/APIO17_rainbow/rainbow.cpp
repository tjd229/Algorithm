//graph, pst
#include "rainbow.h"
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 18;
const int MEM = 8e6;
//v,ve,he,sq
int st_v[MEM], st_ve[MEM], st_he[MEM], st_sq[MEM];
int l_v[MEM], l_ve[MEM], l_he[MEM], l_sq[MEM];
int r_v[MEM], r_ve[MEM],r_he[MEM], r_sq[MEM];
int rt_v[LEAF], rt_ve[LEAF], rt_he[LEAF], rt_sq[LEAF];
int v, ve, he, sq;
int max_x, max_y, min_x, min_y;
int _R, _C;
inline void unq_sort(vector<pii > &v) {
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());

}
int make_tree(int pre,int s,int e,int pos,int *st, int *l, int *r, int &cnt) {
	if (pos<s || pos>e) return pre;
	int ix = ++cnt;
	if (s == e) st[ix] = st[pre] + 1;
	else {
		l[ix] = make_tree(l[pre], s, (s + e) >> 1, pos, st, l, r, cnt);
		r[ix] = make_tree(r[pre], 1+( (s + e) >> 1),e, pos, st, l, r, cnt);
		st[ix] = st[l[ix]] + st[r[ix]];
	}
	return ix;
}
void make_tree(vector<pii > &v,int *root,int *st,int *l,int *r,int &cnt) {
	auto it = v.begin();
	for (int y = 1; y <= _R; ++y) {
		if (it != v.end() && y == it->first) {
			int pre = root[y - 1];
			while (it != v.end() && y == it->first) {
				pre = root[y] = make_tree(pre, 0, LEAF - 1, it->second, st, l, r, cnt);
				++it;
			}
		}
		else root[y] = root[y - 1];
	}
}
int range_sum(int ix, int s,int e,int from,int to, int *st, int *l, int *r) {
	if (ix == 0) return 0;
	else if (e < from || to < s) return 0;
	else if (from <= s && e <= to) return st[ix];
	return range_sum(l[ix], s, (s + e) >> 1, from, to, st, l, r)
		+ range_sum(r[ix], 1 + ((s + e) >> 1), e, from, to, st, l, r);
}
int sum(int y1,int x1,int y2,int x2,int *root,int *st, int *l, int *r) {
	if (x2 < x1 || y2 < y1) return 0;

	return range_sum(root[y2], 0, LEAF - 1, x1, x2, st, l, r)
		- range_sum(root[y1 - 1], 0, LEAF - 1, x1, x2, st, l, r);
}
void init(int R, int C, int sr, int sc, int M, char *S) {
	_R = R; _C = C;
	v = ve = he = sq = 0;
	max_x = max_y = 0; min_x = C+1; min_y = R+1;
	vector<pii > vv,vve,vhe,vsq;
	vsq.push_back({sr,sc});//y,x
	for (int i = 0; i < M; ++i) {
		switch (S[i]) {
		case 'N':
			--sr; break;
		case 'E':
			++sc; break;
		case 'S':
			++sr; break;
		case 'W':
			--sc; break;
		}
		vsq.push_back({ sr,sc });
	}
	unq_sort(vsq);
	for (auto p : vsq) {
		vv.push_back(p); vv.push_back({ p.first,p.second + 1 });
		vv.push_back({ p.first + 1,p.second}); vv.push_back({ p.first+1,p.second + 1 });
		vve.push_back(p); vve.push_back({ p.first,p.second + 1 });
		vhe.push_back(p); vhe.push_back({ p.first+1,p.second });
		min_x = min(min_x, p.second); max_x = max(max_x, p.second + 1);
		min_y = min(min_y, p.first); max_y = max(max_y, p.first + 1);
	}
	_R = max(_R, max_y); _C = max(_C, max_x);
	unq_sort(vv); unq_sort(vve); unq_sort(vhe);
	make_tree(vsq, rt_sq, st_sq, l_sq, r_sq, sq);

	make_tree(vv, rt_v, st_v, l_v, r_v, v);
	make_tree(vve, rt_ve, st_ve, l_ve, r_ve, ve);
	make_tree(vhe, rt_he, st_he, l_he, r_he, he);
}
int colour(int ar, int ac, int br, int bc) {
	//return 0;
	int v = br + br + 4 - ar - ar + bc + bc + 4 - ac - ac - 4;
	int e = v;
	v += sum(ar + 1, ac + 1, br, bc,rt_v,st_v,l_v,r_v);
	e += sum(ar, ac+1, br, bc, rt_ve, st_ve, l_ve, r_ve)
		+ sum(ar+1, ac, br, bc, rt_he, st_he, l_he, r_he);
	int sq = sum(ar,ac,br,bc,rt_sq,st_sq,l_sq,r_sq);
	//printf("%d,%d,%d\n",v,e,sq);
	//printf("%d,%d,%d,%d\n",min_x,max_x,min_y,max_y);
	int f = 2 + e - v - sq;
	if (ac < min_x && ar < min_y && max_x <= bc && max_y <= br) ++f;
    return f-1;
}