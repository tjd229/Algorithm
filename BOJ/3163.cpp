//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
int a[100000],p[100000];
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i,N,L,k;
		vector<pii > v;
		vector<int> l,r;
		for (scanf("%d%d%d", &N, &L, &k), i = 0; i < N; ++i) {
			scanf("%d%d",p+i,a+i);
			if (a[i] > 0) r.push_back(L-p[i]);
			else l.push_back(p[i]);
		}
		sort(l.begin(), l.end()); sort(r.begin(), r.end());
		for (i = 0; i < l.size(); ++i)
			v.push_back({l[i],a[i]});
		for (i = 0; i < r.size(); ++i)
			v.push_back({r[i],a[N-1-i]});
		sort(v.begin(), v.end());
		printf("%d\n",v[k-1].second);
		
	}

	return 0;
}