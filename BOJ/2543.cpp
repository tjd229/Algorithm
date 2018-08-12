//graph, dp

#include <stdio.h>
#include <algorithm>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int mod = 20070713;
ll d[100001];
pii bot[100001];
int main(){
	int i;
	int N;
	for (scanf("%d", &N), i = 0; i < N; i++){
		scanf("%d%d", &bot[i].first, &bot[i].second);
	}
	sort(bot, bot + N);
	bot[N] = { 1e9, 1e9 };
	d[N] = 1;
	for (i = N - 1; i >= 0; --i){
		pii p = { bot[i].second, 0 };
		int nxt = lower_bound(bot, bot + N + 1,p)-bot;
		d[i] = (d[1+i] + d[nxt])%mod;
	}
	printf("%lld",d[0]);

	return 0;
}
