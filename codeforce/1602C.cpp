//math
#include <stdio.h>
#include <set>
#define ll long long
using namespace std;
int gcd(int a, int b) {
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;
	return gcd(b%a,a);
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n; 
		int b[40] = { 0 };
		ll cum = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			int a; scanf("%d",&a);
			cum += a;
			for (int k = 0; a; ++k) {
				if (a & 1) ++b[k];
				a >>= 1;
			}
		}
		if (cum == 0) {
			for (i = 1; i <= n; ++i)
				printf("%d ",i);
		}
		else {
			int d = 0;
			set<int> st;
			for (i = 0; i < 33; ++i) {
				if (b[i] == 0) continue;
				if (d == 0) d = b[i];
				else d = gcd(d, b[i]);
			}
			for (i = 1; i*i <= d; ++i) {
				if (d%i == 0) {
					st.insert(i);
					st.insert(d/i);
				}
			}
			for (auto it = st.begin(); it != st.end(); ++it)
				printf("%d ",*it);
		}
		puts("");
	}
 
	return 0;
}