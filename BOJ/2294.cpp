//category : dp
#include <stdio.h>
int coin[100];
int d[100][10001];
bool visit[100][10001];

int accnt(int val,int ix){
	if (val < 0) return -1;
	if (ix == 0){
		return val%coin[ix] ? -1 : val / coin[ix];
	}
	if (visit[ix][val]) return d[ix][val];
	visit[ix][val] = true;

	int t1 = accnt(val-coin[ix],ix);
	int t2 = accnt(val,ix-1);
	t1 = t1 < 0 ? 20000 : t1 + 1;
	t2 = t2 < 0 ? 20000 : t2;
	d[ix][val] = t1 < t2 ? t1 : t2;
	if (d[ix][val] == 20000) d[ix][val] = -1;
	
	return d[ix][val];


}
int main(){
	int n, k;
	int i;
	for (scanf("%d%d", &n, &k), i = 0; i < n; i++) scanf("%d",coin+i);
	printf("%d",accnt(k,n-1));
	return 0;
}
