//category : greedy
#include <stdio.h>
#include <unordered_map>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod = 1e9 + 7;
pii lev[300000];
int main(){
	int i;
	int N;
	unordered_map<int, int> cnt;
	for (scanf("%d", &N), i = 0; i < N; i++) scanf("%d", &lev[i].first);
	for (i = 0; i < N; i++) scanf("%d", &lev[i].second);
	sort(lev, lev + N);
	if (lev[0].first != lev[0].second || (N>1 && lev[0].first == lev[1].first)) {
		printf("0");
		return 0;
	}
	cnt[lev[0].second]++;
	ll ans = 1;
	int left = 1;
	for (i = 1; i < N; i++){
		while (left != i && lev[i].first != lev[i - 1].first){
			cnt[lev[left++].second]++;
		}
		int r = lev[i].second - lev[i].first;
		ans = ans*cnt[r] % mod;
	}
	printf("%lld",ans);

	return 0;
}
