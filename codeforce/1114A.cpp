//greedy
#include <stdio.h>
int main() {
	int x, y, z;
	int a,b,c;
	int i;
	scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
	int eat1 = a=a - x;
	b += a;
	int eat2 = b = b - y;
	c+= b;
	int eat3 = c = c - z;
	if (eat1 < 0 || eat2 < 0 || eat3 < 0) printf("NO");
	else printf("YES");
	return 0;
}
