//idea reference : https://github.com/jwvg0425/SoftCon/blob/master/1/F.%20%EC%A0%95%EC%9B%90%EC%82%AC/solution.md
//st, ft

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int LEAF = 1 << 20;
const int bnd = 1 << 17;
const ll INF = 1e18;
ll st[LEAF + LEAF];
int ft[bnd + 1];
struct Info{
	int p1, p2, p3;
	ll p4;
	bool operator<(Info info) const{
		if (info.p1 == p1) return p2 < info.p2;
		return p1 < info.p1;
	}
};
void prune(int ix, ll val){
	st[ix] = val;
	ix >>= 1;
	while (ix){
		st[ix] = min(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
int when(int ix,int s,int e,int lb,ll h){
	if (e <= lb || st[ix] >= h) return -1;
	if (s == e) return s;
	int res = when(ix + ix, s, (s + e) >> 1, lb, h);
	if (res < 0) res = when(ix + ix + 1, 1 + ((s + e) >> 1), e, lb, h);
	return res;
}
int sum(int ix){
	int res = 0;
	for (; ix > 0; ix -= (ix&-ix)) res += ft[ix];
	return res;
}
void update(int ix, int val){ for (; ix <= bnd; ix += (ix&-ix)) ft[ix] += val; }
int main(){
	int i;
	int N, M, k;
	int type, t, l, r, h;
	vector<Info> evt; //where, qur_type, t, h
	vector<Info> qur; //when, qur_type, (l,r) or (pos, +-)  
	ll ti;
	for (scanf("%d%d%d", &N, &M,&k),ti=1; M--;ti++){
		scanf("%d%d%d%d",&type,&t,&l,&r);
		switch (type){
		case 1:
			//h = r - ti*k;
			evt.push_back({ l, 2, ti, r-(ll)t*k });
			break;
		case 2:
			scanf("%d", &h);
			//h = h - ti*k;
			evt.push_back({ l, 1, ti, h-(ll)t*k });
			evt.push_back({ r + 1, 1, ti, INF });
			break;
		case 3:
			qur.push_back({ ti, 3, l, r });
			break;
		}
	}
	fill(st, st + LEAF + LEAF, INF);
	prune(LEAF + ti, -INF);
	sort(evt.begin(), evt.end());
	for (i = 1,t=0; i <= N; i++){
		while (t < evt.size() && evt[t].p1 <= i){
			if (evt[t].p2 == 1) //query 2
				prune(evt[t].p3+LEAF, evt[t].p4);
			else{ //query 1
				qur.push_back({ evt[t].p3, 1, i, 1 });
				qur.push_back({ when(1,0,LEAF-1,evt[t].p3,evt[t].p4), 1, i, -1 });
			}
			t++;
		}
	}
	sort(qur.begin(), qur.end());

	for (auto q : qur){
		//printf("%d,%d\n",q.p2, q.p1);
		if (q.p2 == 3) printf("%d\n",sum(q.p4)-sum(q.p3-1));
		else
			update(q.p3, q.p4);
		
	}

	return 0;
}
