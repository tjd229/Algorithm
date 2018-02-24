//category : math

#include <stdio.h>
#include <queue>
#include <set>
using namespace std;
#define ll long long
#define pii pair<int,int>
int cntx[100001];
int cnty[100001];
int main(){
	int i;
	int n, m, r, k;
	scanf("%d%d%d%d",&n,&m,&r,&k);
	int x = n - r + 1;
	int y = m - r + 1;
	int bndx = x < r ? x : r;
	int bndy = y < r ? y : r;
	int s = 0;
	for (i = 1; i<bndx; i++){
		cntx[i] = 2;
		s += 2;
	}
	cntx[bndx] = n - s;
	s = 0;
	for (i = 1; i<bndy; i++){
		cnty[i] = 2;
		s += 2;
	}
	cnty[bndy] = m - s;
	pii nxt;
	ll nume = 0;
	priority_queue<pair<ll, pii> > q;
	set<pii> visit;
	visit.insert({ bndx, bndy });
	q.push({ (ll)bndx * bndy, { bndx, bndy } });
	while (k > 0){
		
		pii p = q.top().second;
		ll val = q.top().first;
		ll cnt = cntx[p.first]*(ll)cnty[p.second];
		q.pop();
		if (k < cnt) cnt = k;
		
		nume += cnt*val;
		nxt = { p.first - 1, p.second };
		if (p.first >1 && visit.find(nxt) == visit.end()){
			q.push({ (ll)(p.first - 1) * p.second,nxt });
			visit.insert(nxt);
		}
		nxt = { p.first , p.second-1 };
		if (p.second >1 && visit.find(nxt) == visit.end()){
			q.push({ (ll)p.first  * (p.second-1), nxt });
			visit.insert(nxt);
		}
		
		k -= cnt;
	}

	ll deno = (n - r + 1)*(ll)(m - r + 1);
	printf("%.9f",(double)nume/deno);

	return 0;
}
