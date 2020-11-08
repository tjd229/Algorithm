//implementation
#include <stdio.h>
int s[100001];
int n;
int find(int st,int tgt) {
	for (int i = st; i < n; ++i) {
		if (s[i] == tgt && s[i + 1] == tgt) return i;
	}
	return n;
}
void swap(int l,int r) {
	while (l < r) {
		s[l] ^= s[r] ^= s[l] ^= s[r];
		++l; --r;
	}
}
int main() {
	int t,i;
	for (scanf("%d", &t); t--;) {
		int last = -1;
		int ans = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%1d",s+i);
		for (i = 1; i <= n; ++i) {
			if (last == s[i]) {
				int pos = find(i, 1 - s[i]);
				swap(i, pos);
				++ans;
			}
			last = s[i];
		}
		printf("%d\n",ans);
	}
 
	return 0;
}