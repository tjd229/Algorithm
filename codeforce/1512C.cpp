//greedy
#include <stdio.h>
char s[200001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, a, b; scanf("%d%d",&a,&b);
		int n = a + b;
		for (i = 1; i <= n; ++i) {
			scanf(" %c", s + i);
			if (s[i] == '0') --a;
			else if (s[i] == '1')--b;
		}
		int l = 1, r = n;
		while (l < r) {
			if (s[l] == '?' && s[r] != '?') {
				s[l] = s[r];
				if (s[r] == '0') --a;
				else --b;
			}
			else if (s[l] != '?' && s[r] == '?') {
				s[r] = s[l];
				if (s[l] == '0') --a;
				else --b;
			}
			++l; --r;
		}
		l = 1; r = n;
		while (l < r) {
			if (s[l] == '?' && s[r] == '?') {
				if (a > 1) s[l] = s[r] = '0',a-=2;
				else s[l] = s[r] = '1', b -= 2;
			}
			++l; --r;
		}
		if (l == r && s[l]=='?') {
			//odd case
			if (a == 1) s[l] ='0', --a;
			else s[r] = '1', --b;
		}
		for (i = 1; i <= n; ++i) {
			if (s[i] == '?') a = b = -1;
		}
		l = 1; r = n;
		while (l < r) {
			if (s[l] != s[r]) a = b = -1;
			++l; --r;
		}
		if (a != 0 || b != 0)
			printf("-1\n");
		else {
			for(i = 1; i <= n; ++i)
				printf("%c",s[i]);
			puts("");
		}
 
	}
 
	return 0;
}