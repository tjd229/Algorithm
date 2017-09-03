//category : math

#include <stdio.h>
int hexa(int a,int b,int c){
	if (a <= 1 || b <= 1 || c <= 1) return a*b*c;
	int perimeter = a + b + c - 3;
	return hexa(a - 1, b - 1, c - 1) + perimeter + perimeter;
}
int main(){
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",hexa(a,b,c));
	return 0;
}