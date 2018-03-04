//category : bs

#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
int n, T;
int a[200000];
pii prob[200000];
vector<int> hist;
bool solve(int k){
	int spend = 0;
	int i;
	hist.clear();
	for (i = 0; i <n&&hist.size()!=k; i++){
		int ix = prob[i].second;
		int t = prob[i].first;
		if (a[ix] >= k){
			spend += t;
			if (spend > T) return false;
			hist.push_back(ix+1);
		}
	}
	return hist.size() == k&&spend <= T;
}
int main(){
	int i;
	int l, r;
	int ans = 0;
	for (scanf("%d%d", &n, &T), i = 0; i < n; i++){
		scanf("%d%d",a+i,&prob[i].first);
		prob[i].second = i;
	}
	sort(prob, prob+n);

	l = 0;
	r = n;
	while (l <= r){
		int m = (l + r) >> 1;
		if (solve(m)) l = m + 1;
		else r = m - 1;
	}
	ans = l - 1;
	solve(ans);
	printf("%d\n%d\n",ans,ans);
	for (i = 0; i < ans; i++) printf("%d ",hist[i]);
}
