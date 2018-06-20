//category : greedy

#include <algorithm>
#include <stdio.h>
using namespace std;
int a[(int)2e5+1];
int main(){
	int n, K;
	int i;
	for (scanf("%d%d", &n, &K), i = 1; i <= n; i++){
		scanf("%d",a+i);
	}
	a[0] = -1e7;
	int ans = n;
	int m = 1;
	sort(a+1, a+1 + n);
	for (i = 1; i <= n; i++){
		int diff = a[i] - a[i - 1];
		if (diff <= K && diff!=0) ans-=m;
		else if (diff == 0) m++;
		if (diff != 0) m = 1;
	}
	printf("%d", ans);
	
	return 0;

}
