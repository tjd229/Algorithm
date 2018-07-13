//dp

#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;

ll cnt[2][1 << 20];
int d[2][1 << 20];
int pt[100][4];
int N, M;
int main(){
	int i, j, k;
	int tog = 1;
	int s, ns;
	int nxt_mask = 0;
	scanf("%d%d",&N,&M);
	int NM = 0;
	for (k = 0; k < 4; k++){
		NM = 0;
		for (i = 0; i < N; i++){
			for (j = 0; j < M; j++){
				scanf("%d",&pt[NM++][k]);
			}
		}
	}
	int M2 = M << 1;
	int bnd = 1 << (M2);
	for (k = 0; k < 4; k++) d[0][k] = pt[0][k],cnt[0][k]=1;
	for (i = 0; i < M2 - 2; i++) nxt_mask |= (1 << i);
	NM = 0;
	
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++, tog^=1,NM++){
			if (i+j==0) continue;
			for (s = 0; s < bnd; s++){
				if (cnt[tog][s] == 0) continue;
				ns = s&nxt_mask;
				ns <<= 2;
				for (k = 0; k < 4; k++){
					if (i > 0 && k == (s >> (M2 - 2))) continue;
					if (j > 0 && k == (s & 3)) continue;
					if (d[tog ^ 1][ns + k] < d[tog][s] + pt[NM][k]){
						d[tog ^ 1][ns + k] = d[tog][s] + pt[NM][k];
						cnt[tog ^ 1][ns + k] = cnt[tog][s];	
					}
					else if (d[tog ^ 1][ns + k] == d[tog][s] + pt[NM][k]){
						cnt[tog ^ 1][ns + k] += cnt[tog][s];
						cnt[tog ^ 1][ns + k] %= mod;
					}
				}
				d[tog][s] = cnt[tog][s] = 0;
			}

		}
	}
	int ans1=0;
	ll ans2=0;
	for (s = 0; s < bnd; s++){
		if (ans1 < d[tog][s]){
			ans1 = d[tog][s];
			ans2 = cnt[tog][s];
		}
		else if (ans1 == d[tog][s]){
			ans2 += cnt[tog][s];
			ans2 %= mod;
		}
	}
	printf("%d %lld",ans1,ans2);
	return 0;
}
