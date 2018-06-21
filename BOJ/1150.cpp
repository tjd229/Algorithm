//category : greedy

#include <stdio.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
struct Cable{
	int ix;
	int cost;
	int plus;
	bool operator<(const Cable c) const{
		if (plus == c.plus) return cost>c.cost;
		return plus < c.plus;
	}
};
bool use[(int)2e5];
int p[(int)2e5], l[(int)2e5], r[(int)2e5];
int c[(int)2e5], sz[(int)2e5];
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
int main(){
	int last;
	int n, k;
	int cost = 0;
	int cnt = 0;
	int s;
	int i;
	priority_queue<Cable> q;
	for (scanf("%d%d%d", &n, &k, &last), i = 1; i < n; i++){
		scanf("%d", &s);
		p[i] = i;
		l[i] = i - 1;
		r[i] = i + 1;
		c[i] = s - last;
		sz[i] = 1;
		q.push({ i,c[i],1 });
		last = s;
	}
	r[n] = 0;
	while (cnt!=k){
		while (use[q.top().ix]) q.pop();
		int ix = q.top().ix;
		cnt += q.top().plus;
		q.pop();
		cost += c[ix];
		int left = find(l[ix]);
		int right=find(r[ix]);
		use[left] = use[right] = true;
		
		p[left] = p[right] = ++n;
		l[n] = l[left];
		r[n] = r[right];
		c[n] = c[left] + c[right] - c[ix];
		sz[n] = sz[left] + sz[right] - sz[ix];
		p[n] = n;
		q.push({n,c[n],sz[n]});
	}
	printf("%d",cost);
	
	return 0;
}
