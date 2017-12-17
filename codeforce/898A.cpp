//category : math
#include <stdio.h>

int main(){
	int n;
	int d;
	int p=0;
	scanf("%d",&n);
	d = n % 10;
	if (d > 5) p = 10;
	printf("%d",n-d+p);

	return 0;
}
