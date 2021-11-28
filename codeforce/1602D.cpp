//dp
#include <stdio.h>
#include <queue>
#include <set>
#include <vector>
#define pii pair<int,int>
using namespace std;
int d1[300001], d2[300001];
int a[300001], b[300001];
int bk1[300001], bk2[300001];
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		d1[i] = d2[i] = -1;
	}
	for(i=1;i<=n;++i)scanf("%d", b + i);
	d1[n] = d2[n] = 0;
	d1[0] = d2[0] = -1;
	bk1[n] = bk2[n] = n;
	priority_queue<pii > q; q.push({(n-a[n]),n});//max heap
	set<pii > opt; opt.insert({d2[n],n});
	for (i = n - 1; i >= 0; --i) {
		while (q.size() && q.top().first > i) {
			int ix = q.top().second; q.pop();
			opt.erase({d2[ix],ix});
		}
		if (opt.empty()) break;
		d1[i] = opt.begin()->first+1;
		bk1[i] = opt.begin()->second;
		int s = i + b[i];
		if (s - a[s] < i) {
			if (d2[s] == -1) {
				d2[s] = d1[i];
				bk2[s] = i;
				opt.insert({ d2[s],s });
				q.push({ s - a[s],s });
			}
			else if (d2[s] > d1[i]) {
				opt.erase({ d2[s],s });
				bk2[s] = i;
				d2[s] = d1[i];
				opt.insert({ d2[s],s });
			}
		}
		
	}
	printf("%d\n",d1[0]);
	//printf("%d\n",bk1[0]);
	//return 0;
	if (d1[0] > 0) {
		int curr = 0;
		vector<int> v;
		while (curr != n) {
			v.push_back(curr);
			curr = bk1[curr];
			curr = bk2[curr];
		}
		while (v.size()) {
			printf("%d ", v.back());
			v.pop_back();
		}
	}
 
	return 0;
}