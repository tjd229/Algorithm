//category : greedy

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<int> ans;
vector<int > fridge;
//set<pair<int, int> > milk;
vector<pair<int, int> > milk;
int main(){
	int i;
	int n, m, k;
	int f, s;
	int num;
	int end_date = 0;
	scanf("%d%d%d",&n,&m,&k);
	for (i = 0; i < n; i++){
		scanf("%d",&f);
		if (end_date < f) end_date = f;
		fridge.push_back(f);
	}
	
	for (i = 1; i <= m; i++){
		scanf("%d",&s);
		if (end_date < s) end_date = s;
		milk.push_back(make_pair(s,i));
	}
	sort(fridge.begin(), fridge.end());
	sort(milk.begin(), milk.end());
	auto buy=milk.begin();
	for (i = 0; i <= end_date; i++){
		num = upper_bound(fridge.begin(), fridge.end(), i) - lower_bound(fridge.begin(), fridge.end(), i);
		if (num > k){
			printf("-1");
			return 0;
		}
		num = k - num;
		buy = lower_bound(buy,milk.end(),make_pair(i,0));
		while (num--&&buy != milk.end()){
			ans.push_back(buy->second);
			buy++;
		}
	}
	printf("%d\n",ans.size());
	for (i = 0; i < ans.size(); i++) printf("%d ",ans[i]);
	return 0;
}