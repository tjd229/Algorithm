//MITM

#include <stdio.h>
#include <unordered_map>
#define ll long long
using namespace std;
unordered_map<ll, ll> abv[20];
ll a[20][20];
int n, m, half;
ll k, ans;
void down(int i, int j, int lev,ll ex){
	if (i >= n || j >= m) return;
	ex ^= a[i][j];
	if (half == lev){
		abv[j][ex]++;
		return;
	}
	down(i + 1, j,1+lev, ex);
	down(i, j + 1,1+lev, ex);
}
void up(int i, int j, int lev,ll ex){
	if (i < 0 || j < 0) return;
	
	if (lev == n + m - 2 - half){
		ans += abv[j][ex^k];
		return;
	}
	ex ^= a[i][j];
	up(i - 1, j,lev+1, ex);
	up(i, j - 1, lev+1,ex);
}
int main(){
	int i, j;
	for (scanf("%d%d%I64d", &n, &m, &k), i = 0; i < n; i++){
		for (j = 0; j < m; j++) scanf("%I64d",&a[i][j]);
	}
	half = (n + m - 2) >> 1;
	//if (half == 0) abv[0][0] = 1;
	down(0, 0, 0,0);
	up(n - 1, m - 1,0, 0);
	printf("%I64d",ans);

	return 0;
}
