//category : math

#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	int ans = a*c;
	ans = (ans / b) + (ans%b!=0)-c;
	printf("%d",ans);
	return 0;
}