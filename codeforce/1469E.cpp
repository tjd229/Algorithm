//string
#include <stdio.h>
#include <set>
using namespace std;
int s[1000001],rs[1000001];
int trie[1<<20];
int n, k;
bool chk() {
	set<int> st;
	int t = 0; int cap = 1 << k;
	for (int i = 1; i <= k; ++i) t += t + s[i];
	st.insert(t);
	for (int i = k + 1; i <= n && cap>st.size(); ++i) {
		t += t+s[i];
		t &= (cap - 1);
		st.insert(t);
	}
	return cap == st.size();
}
int main() {
	int tc;
	for (scanf("%d", &tc); tc--;) {
		int i;
		for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i)
			scanf("%1d",s+i);
		if (k < 20 && n - k + 1 >= (1 << k)) {
			if (chk()) {
				printf("NO\n");
				continue;
			}
		}
		int r = k;
		if (r > 20) r = 20;
		int l = k - r;
		for (i = 1; i <= n; ++i) {
			s[i] = 1 - s[i];
			rs[i] = rs[i - 1] + s[i];
		}
		
		int t = 0; int mask = (1 << r)-1;
		for (i = 1; i < r; ++i) t += t + s[i + l];
		for (i = 1; i+k-1<= n; ++i) {
			t += t + s[i + k-1];
			t &= mask;
			if (rs[i - 1 + l] - rs[i - 1] == 0) {
				trie[t] = tc + 1;
			}
		}
		int ans = -1;
		for (i = 0; i<=mask && ans < 0; ++i) if (trie[i] != tc + 1) ans = i;
		if (ans < 0) printf("NO\n");
		else {
			printf("YES\n");
			while (l--) printf("0");
			for (i = r - 1; i >= 0; --i)printf("%d",(ans&(1<<i))>0);
			puts("");
		}
	}
 
	return 0;
}