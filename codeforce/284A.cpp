//category : math

#include <stdio.h>
int phi(int n){
	int ans = n;
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0){
			while (n%i == 0) n /=i;
			ans -= ans / i;
		}
	}
	if (n > 1) ans -= ans / n;
	return ans;
}
int main(){
	int p;
	int i, j;
	int r;
	scanf("%d",&p);	
	printf("%d",phi(p-1));
	return 0;
}