//math
#include <stdio.h>
#include <vector>
#include <numeric>
using namespace std;
int ask(vector<int> b) {
	printf("?");
	for(auto x:b) printf(" %d",x);
	printf("\n"); fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}
int main() {
	int i,n,k; scanf("%d%d",&n,&k);
	int r = n % k;
	if (k == 1) {
		int ans = 0;
		for (i = 1; i <= n; ++i) ans ^= ask({ i });
		printf("! %d", ans); fflush(stdout);
	}
	else if ((k & 1) == 0 && (n & 1)==1) {
		printf("-1"); fflush(stdout);
	}
	else  {
		int ans = 0;
		int r = n % k;
		if (r&1) r += k;
		else if (r>0 &&((r+k)&1)==0 &&r+k<n ) r += k;
		int remain = n;
		int done = 0;
		while (remain > r) {
			remain -= k;
			vector<int> b(k);
			iota(b.begin(), b.end(), done+1);
			ans ^= ask(b);
			done += k;
		}
		int unit = remain >> 1;
		if (unit + k > n) {
			unit = n - k;
			while (done < n) {
				vector<int> b, c;
				for (i = 1; i <= unit + unit && done + i + 1 <= n; i += 2) {
					b.push_back(done + i);
					c.push_back(done + i + 1);
				}
				done = c.back();
				for (i = 1; c.size() < k; ++i) {
					b.push_back((done + i - 1) % n + 1);
					c.push_back((done + i - 1) % n + 1);
				}
				ans ^= ask(c) ^ ask(b);
			}
		}
		else if(unit>0){//2 qry
			vector<int> b, c;
			for (i = done + 1; i + 1 <= n; i += 2) {
				b.push_back(i);
				c.push_back(i + 1);
			}
			for (i = 1; b.size() < k; ++i) {
				b.push_back(i);
				c.push_back(i);
			}

			ans ^= ask(b) ^ ask(c);
		}
		printf("! %d", ans); fflush(stdout);
	}
	
	return 0;
}