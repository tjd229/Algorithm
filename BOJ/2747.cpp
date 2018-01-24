//category : dp

#include <stdio.h>
int f[46];
int fibo(int n){
	if (n <= 1) return n;
	if (f[n] != 0) return f[n];
	f[n] = fibo(n - 1) + fibo(n - 2);
	return f[n];
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",fibo(n));
}
