//string
#include <stdio.h>
char s[301];
int qry(const char *s) {
	printf("%s\n", s); fflush(stdout);
	int d; scanf("%d", &d);
	return d;
}
int main() {
	int d0 = qry("a");
	if (!d0) return 0;
	int n = d0 + 1;
	if (n > 300) n = 300;
	for (int i = 0; i < n; ++i) s[i] = 'a';
	s[n] = '\0';
	int d1 = qry(s);
	if (!d1) return 0;
	if (d0 < d1) s[--n] = '\0';
	d0 = d1;
	for (int i = 0; i < n - 1; ++i) {
		s[i] = 'b';
		d1 = qry(s);
		if (!d1) return 0;
		if (d1 > d0) s[i] = 'a';
		else d0 = d1;
	}
	if (d0) s[n-1] = 'b';
	qry(s);
 
	return 0;
}