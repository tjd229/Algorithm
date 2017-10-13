//category : geometry, line sweeping
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define pb push_back
using namespace std;
pii pt[101];
int N, half;
int sweeping(vector<int> &v){
	int l, r;
	int res = 20000;
	l = r = 0;

	while (r < v.size()){
		if (l == r||r-l+1<half) r++;
		else{
			res = min(res, v[r] - v[l]+2);
			l++;
		}
	}
	return res;
}
int main(){
	int i,j;
	
	int ans = 20000 * 20000;
	for (scanf("%d", &N), i = 0; i < N; i++){
		scanf("%d%d",&pt[i].first,&pt[i].second);
	}
	half = N >> 1;
	sort(pt,pt+N);
	for (i = 0; i < N; i++){
		vector<int> y;
		for (j = i; j < N; j++){
			y.pb(pt[j].second);
			if (y.size() < half) continue;
			sort(y.begin(), y.end());
			ans = min(ans, (pt[j].first - pt[i].first + 2)*sweeping(y));
		}
	}printf("%d",ans);
	return 0;
}