//category : djs

#include <stdio.h>
#define ll long long
const int bnd = 1e6;
int p[bnd + 2];
int l[bnd + 2];
int r[bnd + 2];
int sz[bnd + 2];
int g[bnd + 2];
int no[bnd + 2];
int cnt;
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	sz[a] += sz[b];
	if (l[a] > l[b]) l[a] = l[b];
	if (r[a] < r[b]) r[a] = r[b];
	p[b] = a;
}
int main(){
	int i;
	int K, N;
	int last=0,A;
	int Q, a, b;
	ll ans = 0;
	for (scanf("%d%d", &K, &N), i = 1; i <= N; i++){
		scanf("%d",&A);
		if (last != A){
			cnt++;
			l[cnt] = cnt - 1;
			r[cnt] = cnt + 1;
			p[cnt] = cnt;
			no[cnt] = A;
		}		
		last = A;
		g[i] = cnt;
		sz[cnt]++;
	}
	for (scanf("%d", &Q); Q--;){
		scanf("%d%d",&a,&b);

		if (a == 1){
			int curr = find(g[b]);
			if (--sz[curr] == 0){
				int left = find(l[curr]);
				int right = find(r[curr]);
				if (no[left] == no[right]) join(left, right);
				else{
					r[left] = right;
					l[right] = left;
				}
			}
		}
		else ans += sz[find(g[b])];
	}
	printf("%lld",ans);
	return 0;
}
