//category : greedy

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int a[200000];
int t[200000];
int solve[200000];
int main(){
	int i;
	int n, T;
	int ans = 0;
	int tot = 0;
	vector<pii > prob;
	priority_queue<pii > q;
	for (scanf("%d%d", &n, &T), i = 0; i < n; i++){
		scanf("%d%d",a+i,t+i);
		prob.push_back({a[i],i});
	}
	sort(prob.begin(), prob.end());
	for (i = n; i > 0;i--){
		while (prob.size()&&i == prob.back().first){
			int ix = prob.back().second;
			tot += t[ix];
			q.push({t[ix],ix});
			prob.pop_back();
		}
		while (tot > T){
			int ix = q.top().second;
			tot -= q.top().first;
			solve[ix] = i;
			q.pop();
		}
		ans = max(ans, min(i, (int)q.size()));
	}
	printf("%d\n%d\n",ans,ans);
	for (tot=0; i < n&&tot!=ans; i++){
		//printf("%d,%d\n",solve[i],a[i]);
		if (a[i] >= ans&&solve[i] < ans){
			tot++;
			printf("%d ",i+1);
		}
	}

	return 0;
}
