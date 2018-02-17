//category : implementation
#include <stdio.h>
#define ll long long
const int mod = 1e9;
ll a[50];
ll b[50];
int main(){
	int i,j;
	int n,m;
	ll max = -1e9*1e9;;
	ll local = 0;
	int toms=0;
	for (scanf("%d%d", &n, &m), i = 0; i < n; i++)
		scanf("%I64d",a+i);
	for (i = 0; i < m; i++) scanf("%I64d",b+i);
	for (i = 0; i < n; i++){
		local = -1e9*1e9;
		for (j = 0; j < m; j++){
			if (local < a[i] * b[j]){
				local = a[i] * b[j];
			}
		}
		if (max < local){
			max = local;
			toms = i;
		}
	}
	max = -1e9*1e9;;
	for (i = 0; i < n; i++){
		if (i == toms) continue;
		for (j = 0; j < m; j++){
			if (max < a[i] * b[j])
				max = a[i] * b[j];
		}
	}
	printf("%I64d",max);
	return 0;
}
