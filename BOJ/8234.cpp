//category : greedy

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
int a[250001];
int main(){
	int i;
	int n;
	int b;
	ll tot = 0;
	priority_queue<pii > q;
	for (scanf("%d", &n), i = 1; i <= n; i++) scanf("%d",a+i);
	for (i = 1; i <= n; i++){
		scanf("%d",&b);
		tot += a[i];
		if (tot >= b){
			tot -= b;
			q.push({b,i});
		}
		else if (q.size()&&q.top().first>b){
			tot += q.top().first-b;			
			q.pop();
			q.push({b,i});
		}
	}
	vector<int> candi;
	while (q.size()){
		candi.push_back(q.top().second);
		q.pop();
	}
	sort(candi.begin(), candi.end());
	printf("%d\n",candi.size());
	for (i = 0; i < candi.size(); i++) printf("%d ",candi[i]);

	return 0;
}

