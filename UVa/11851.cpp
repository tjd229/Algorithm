//category : MITM
//idea reference : http://sgc109.tistory.com/110

#include <stdio.h>
#include <map>
#define ll long long
#define mp make_pair
using namespace std;
int N;
int half;
ll p[24];
ll ans;
map<ll,ll> m;
void bf(int i,ll a,ll b, bool search){
	if (search){

		if (m.find(b - a) != m.end()){
			if (ans < m[b - a] + a + b)
				ans=m[b - a] + a + b;
		}
		if (i >= N) return;
	}
	else{
		
		//m
		if (m.find(a - b) == m.end()) m.insert(mp(a - b, a + b));
		else if (m[a - b] < a + b) m[a - b] = a + b;
		if (i >= half) return;
	}
	bf(i + 1, a + p[i], b,search);
	bf(i + 1, a, b + p[i],search);
	bf(i + 1, a, b,search);
}
int main(){
	int i;
	ll total;
	while (scanf("%d", &N)){
		if (N == 0) break;
		ans = 0;
		total = 0;
		for (i = 0; i < N; i++) scanf("%lld", p + i),total+=p[i];
		half = N >> 1;
		map<ll, ll> lm;
		m = lm;
		bf(0, 0, 0, false);
		bf(half, 0, 0, true);
		printf("%lld\n",total-ans);
	}

	return 0;
}
