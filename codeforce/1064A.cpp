//math, geometry

#include <stdio.h>
int main(){
	int a, b, c;
	int ans = 0;
	scanf("%d%d%d",&a,&b,&c);
	if (a < b) a ^= b ^= a ^= b;
	if (a < c) a ^= c ^= a ^= c;
	if (a >= b + c){
		ans = a - b - c+1;
	}


	printf("%d",ans);
	return 0;
}
