//category : greedy


#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v;
int main(){
	int n;
	int i;
	int s, e;
	int ans = 0;
	scanf("%d",&n);
	for (i = 0; i < n; i++){
		scanf("%d%d",&s,&e);
		v.push_back(make_pair(e,s));
	}
	sort(v.begin(), v.end());
	for (i = e = 0; i < n; i++){
		if (v[i].second >= e){
			ans++;
			e = v[i].first;
		}
	}
	printf("%d",ans);
	return 0;
}
