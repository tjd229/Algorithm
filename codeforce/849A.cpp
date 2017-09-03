//category : math

#include <stdio.h>
int a[101];

int n;

int main(){
	int i;
	scanf("%d",&n);
	for (i = 1; i <= n; i++) scanf("%d",a+i);
	
	printf("%s",(n&1)&&(a[1]&1)&&(a[n]&1)? "Yes":"No");
	return 0;
}