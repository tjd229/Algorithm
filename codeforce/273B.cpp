//math

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
vector<pii > coord;
unordered_map<int, int> cnt;
int main(){
	int i;
	int n;
	int a, b;
	int m;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d",&a);
		coord.push_back({a,i});
		cnt[a]++;
	}
	for (i = 1; i <= n; i++){
		scanf("%d",&b);
		coord.push_back({ b, i });
		cnt[b]++;
	}
	scanf("%d",&m);
	sort(coord.begin(), coord.end());
	ll ans = 1;
	pii last = { -1, -1 };
	for (pii p : coord){
		if (last.first==-1){
			last = p;
		}
		else if (last == p){
			ll d = cnt[p.first]--;
			d *= cnt[p.first]--;
			d >>= 1;
			d %= m;
			ans = ans*d%m;
			last = { -1, -1 };
		}
		else{
			ll d= cnt[last.first]--;
			d %= m;
			ans = ans*d%m;
			last = p;
		}
	}
	if (last.first > 0){
		ll d = cnt[last.first]--;
		d %= m;
		ans = ans*d%m;
	}
	printf("%I64d",ans);
	return 0;
}
