//categoty : dp

#include <stdio.h>
#include <memory.h>
#include <map>
#define ll long long
using namespace std;
const int mod = 10000007;

int a[251];
ll d[251][250*250];
int main(){
	int tc = 1;
	int i,j;
	int T;
	int n;
	int cnt,diff,s;
	ll ans;
	int ij;
	for (scanf("%d", &T); T--;tc++){
		scanf("%d",&n);
		for (i = 1; i <= n; i++) scanf("%d",a+i);
		memset(d,0,sizeof(d));
		map<int,int> m;
		m.insert(make_pair(0, 0));
		cnt = 1;
		ans = n;
		for (i = n; i > 0; i--){
			for (j = i+1; j <= n; j++){
				diff = a[j] - a[i];
				if (m.find(diff) == m.end()) m.insert(make_pair(diff,cnt++));
				s = m[diff];
				ij = 1 + d[j][s];
				if (ij >= mod) ij -= mod;
				d[i][s] += ij;
				if (d[i][s] >= mod) d[i][s] -= mod;
				ans += ij;
				if (ans >= mod) ans -= mod;	
			}
		}
		printf("Case %d: %lld\n",tc,ans);


	}

	return 0;
}