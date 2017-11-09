//categoty : MITM

#include <stdio.h>
#include <map>

#define mp make_pair
#define pii pair<int,int>
using namespace std;
int tog1[36];
int tog2[36];
int p1[1 << 18];
int p2[1 << 18];
map<pii, int> m;
void toggled(int u,int v,int mid){
	if (v > mid) tog2[u] ^= (1 << (v-1-mid));
	else tog1[u] ^= (1 << (v - 1));
}
int main(){
	int i,j,k;
	int N, M;
	int u, v;
	int mid;
	int t1, t2;
	int stat1, stat2;
	int num;
	int ans;
	scanf("%d%d", &N, &M);
	mid = N >> 1;
	ans = N;
	for (i = 0; i < M; i++){
		scanf("%d%d",&u,&v);
		toggled(u, v, mid);
		toggled(v, u, mid);
	}
	
	t1 = (1 << mid) - 1;
	t2 = t1;
	if (N & 1){
		t2 <<= 1;
		t2++;
	}
	for (i = 0; i <= t1; i++){
		num = 0;
		stat1 = stat2 = 0;
		for (j = 1; j <= mid; j++){
			if (i&(1<<(j-1))){
				num++;
				stat1 ^= (1 << (j-1));
				stat1 ^= tog1[j];
				stat2 ^= tog2[j];
			}
		}
		pii p = mp(stat1, stat2);
		if (m.find(p) == m.end())
			m.insert(mp(p, num));
		else{
			if (m[p] > num) m[p] = num;
		}
	}
	for (i = 0; i <= t2; i++){
		num = 0;
		stat1 = stat2 = 0;
		for (j = mid+1; j <= N; j++){
			if (i&(1 << (j - mid-1))){
				num++;
				stat2 ^= (1 << (j - mid-1));
				stat2 ^= tog2[j];
				stat1 ^= tog1[j];
			}
		}
		pii p = mp(stat1^t1,stat2^t2);
		if (m.find(p) != m.end()){
			u = m[p];
			if (ans > u + num) ans = u + num;
		}

	}
	printf("%d",ans);


	return 0;
}
