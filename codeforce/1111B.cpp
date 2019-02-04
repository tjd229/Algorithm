//math
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100001];
int main() {
	int n, k, m;
	int i;
	long long sum = 0;
	double mx = 0.0;
	for (scanf("%d%d%d", &n, &k, &m), i = 1; i <= n; ++i)
		scanf("%d", a + i), sum += a[i];
	
	sort(a + 1, a + 1 + n);
	i = 1;
	while (n > 0 && m >= 0) {
		//if (k > m) k = m;
		long long nk = n * (long long)k;
		long long up = nk < m ? nk : m;
		double avg = (up+ sum) / (double)n;
		if (mx < avg) mx = avg;
		sum -= a[i++];
		--n; --m;
		
	}
	printf("%f", mx);
}
