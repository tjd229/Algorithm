//category : greedy

#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Dinner{
	int ix, num, p;
	bool operator< (Dinner d) const{
		return p < d.p;
	}
};

int main(){
	int i;
	int n;
	int k;
	int total = 0;
	Dinner d;
	vector<Dinner> v;
	vector<pair<int, int> > ans;
	priority_queue<Dinner> q;
	scanf("%d",&n);
	for (i = 1; i <=n ; i++){
		scanf("%d%d",&d.num,&d.p);
		d.ix = i;
		v.push_back(d);
	}
	scanf("%d", &k);
	for (i = 1; i <= k; i++){
		scanf("%d",&d.num);
		d.ix = i;
		d.p = -1;
		v.push_back(d);
	}
	sort(v.begin(), v.end(),  [](const Dinner &d1, const Dinner &d2){
		if (d1.num == d2.num) return d1.p > d2.p;
		return d1.num < d2.num;

	});
	for (i = 0; i < v.size(); i++){
		if (v[i].p>0) q.push(v[i]);
		else{
			if (!q.empty()){
				d = q.top();
				total += d.p;
				ans.push_back(make_pair(d.ix,v[i].ix));
				q.pop();
			}
		}
	}

	printf("%d %d\n",ans.size(),total);
	for (i = 0; i < ans.size(); i++)
		printf("%d %d\n",ans[i].first,ans[i].second);

	return 0;
}