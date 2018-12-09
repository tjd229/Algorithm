//bs

#include <stdio.h>
int a[100002];
int half;
bool search(int l,int m) {
	int d1 = a[l] - a[l + half];
	int d2 = a[m] - a[m + half];
	if (d1 > d2) d1 ^= d2 ^= d1 ^= d2;
	return d1 <= 0 && 0 <= d2;
}
int main() {
	int n;
	scanf("%d",&n);
	half = n >> 1;
	if (half & 1) {
		printf("! -1");
		return 0;
	}
	printf("? 1\n"); fflush(stdout);
	scanf("%d",a+1);
	printf("? %d\n",1+half); fflush(stdout);
	scanf("%d", a + 1+ half);
	a[n + 1] = a[1];
	int l = 1;
	int r = 1 + half;
	while (a[l] != a[l + half]) {
		int m = (l + r) >> 1; 
		printf("? %d\n", m); fflush(stdout);
		scanf("%d", a + m);
		printf("? %d\n", m + half); fflush(stdout);
		scanf("%d", a + m + half);
		if (a[m] == a[m + half]) {
			l = m;
			break;
		}
		if (search(l, m)) r = m;
		else l = m;
	}
	printf("! %d",l);


	return 0;
}
