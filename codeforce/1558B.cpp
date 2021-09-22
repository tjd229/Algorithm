//math, dp
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, m;
ll d[4000001];
 
int main() {
	//
	scanf("%d%d",&n,&m);
	
	d[1] = 1; d[2] = 2;
	for (int j = 4; j <= n; j += 2) ++d[j];
	for (int i = 3; i <= n; ++i) {
		d[i] += (d[i - 1] + d[i - 1] + d[1]);
		d[i] %= m;
		int delta = (d[i] - d[i - 1] + m) % m;
		for (int j = i+i; j <= n; j += i)
			d[j] = (d[j] + delta) % m;
	}
	printf("%d",d[n]%m);
 
	return 0;
}