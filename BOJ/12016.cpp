//category : ft



#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define BI (1<<17)
vector<pair<int, int> > v;
long long ans[100001];
long long ft[BI + 1];
void update(int ix, int diff){
	while (ix <= BI){
		ft[ix] += diff;
		ix += (ix&-ix);
	}
}
long long sum(int ix){
	long long s = 0;
	while (ix != 0){
		s += ft[ix];
		ix -= (ix&-ix);
	}
	return s;
}
int main(){
	int N;
	int i;
	int t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		scanf("%d", &t);
		v.push_back(make_pair(t,i));
		update(i,1);
	}
	sort(v.begin(), v.end());
	long long p = N;
	long long now = 0;
	t = 0;
	for (i = 0; i < N; i++){
		if (t != v[i].first)
			now += p*(v[i].first-t);
		ans[v[i].second] = now - (ft[BI] - sum(v[i].second));
		update(v[i].second, -1);
		t = v[i].first;
		p--;
	}
	for (i = 1; i <= N; i++) printf("%lld\n", ans[i]);
		
	
	return 0;
}
