//category : dp, math
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int bnd = 1 << 19;
vector<int> p;
int filter[71];
int cnt[71];
ll d[bnd];
ll tmp[bnd];
ll p2d2[100002];
int main(){
	int i,j;
	int n;
	int a;
	int stat;
	int e;
	for (i = 2; i <= 70; i++){
		if (filter[i]) continue;
		p.push_back(i);
		for (j = i*i; j <= 70; j+=i){
			filter[j] = 1;
		}
		
	}
	for (i = 2, p2d2[0] = p2d2[1] = 1; i <= 100001; i++){
		p2d2[i] = (p2d2[i - 1] << 1) % mod;
	}
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d",&a);
		cnt[a]++;
	}
	d[0] = 1;
	for (i = 2; i <= 70; i++){
		if (cnt[i] == 0) continue;
		j = 0;
		a = i;
		stat=0;
		while (a != 1){
			e = 0;
			while (a%p[j] == 0){
				a /= p[j];
				e++;
			}
			if (e & 1) stat |= (1 << j);
			j++;
		}
		for (j = 0; j < bnd; j++){
			e = d[j] * p2d2[cnt[i]] % mod;
			tmp[j] += e;
			tmp[j] %= mod;
			tmp[j^stat] += e;
			tmp[j^stat] %= mod;
		}
		for (j = 0; j < bnd; j++) d[j]=tmp[j],tmp[j] = 0;
		//return 0;
	}
	ll ans = (d[0] * p2d2[cnt[1]+1] % mod)-1;
	if (ans < 0) ans+=mod;
	printf("%I64d",ans);


	return 0;
}
