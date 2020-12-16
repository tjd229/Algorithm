//string
#include <stdio.h>
int s[201];
int main(){
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%1d",s+i);
		if (s[1] == 2 && s[n] == 0 && s[n - 1] == 2 && s[n - 2] == 0)
			printf("YES\n");
		else if (s[1] == 2 && s[2] == 0 && s[n - 1] == 2 && s[n ] == 0)
			printf("YES\n");
		else if (s[1] == 2 && s[2] == 0 && s[3] == 2 && s[n] == 0)
			printf("YES\n");
		else if (s[1] == 2 && s[2] == 0 && s[3] == 2 && s[4] == 0)
			printf("YES\n");
		else if (s[n-3] == 2 && s[n-2] == 0 && s[n-1] == 2 && s[n] == 0)
			printf("YES\n");
		else printf("NO\n");
	}
 
	return 0;
}