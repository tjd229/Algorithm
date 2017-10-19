//category : implementation

#include <stdio.h>
#include <algorithm>
#define pii pair<int,int>
#define mp make_pair
#define ll long long
using namespace std;

pii girl[100000];
int main(){
	int i;
	int T;
	int N;
	int h;
	int left, right;
	ll ans;
	for (scanf("%d", &T); T--;){
		for (scanf("%d", &N), i = 0; i < N; i++){
			scanf("%d",&h);
			girl[i] = mp(-h,i);
		}
		sort(girl, girl + N);
		left = right = girl[0].second;
		ans = 0;
		for (i = 1; i < N; i++){
			ans = max(ans, (ll)-girl[i].first*abs(left - girl[i].second));
			ans = max(ans, (ll)-girl[i].first*abs(right - girl[i].second));
			if (left > girl[i].second) left = girl[i].second;
			if (right < girl[i].second) right= girl[i].second;
		}
		printf("%lld\n",ans);
	}

	return 0;
}