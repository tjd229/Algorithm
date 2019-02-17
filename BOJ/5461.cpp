//greedy
#include <stdio.h>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int S[500000], Q[500000];
pair<double, int> order[500000];
int main() {
	int i, N;
	ll W;
	ll tot = 0;
	double k,mn = 1e10;
	int r,h = 0;
	priority_queue <pair<int,int> > q;
	for (scanf("%d%lld", &N, &W), i = 0; i < N; ++i) {
		scanf("%d%d", S + i, Q + i);
		order[i] = {(double)S[i]/Q[i],i};
	}
	sort(order, order + N, [](pair<double,int> a, pair<double,int> b) {
		pair<double, int> p1, p2;
		p1 = { a.first,S[a.second] };
		p2 = { b.first,S[b.second] };
		return p1 < p2;
	});
	for (i = 0; i < N; ++i) {
		int ix = order[i].second;
		k = order[i].first;
		tot += Q[ix];
		q.push({ Q[ix],ix });
		//printf("%f,%d,%lld\n", k, ix,tot);
		while (k*tot > W) {			
			tot -= q.top().first;
			q.pop();
		}
		if (h < q.size()
			|| (h==q.size() && mn>k*tot)) {
			h = q.size();
			mn = k * tot;
			r = i;
		}		
	}
	sort(order, order + r+1, [](pair<double, int> a, pair<double, int> b) {
		return Q[a.second] < Q[b.second];
	});
	printf("%d\n",h);
	for (i = 0; i < h; ++i) printf("%d\n",order[i].second+1);
	return 0;
}