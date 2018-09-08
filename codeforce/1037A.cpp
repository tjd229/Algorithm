//math

#include <stdio.h>
#define ll long long
int main(){
	int n;
	ll val = 1;
	int cnt = 0;
	scanf("%d",&n);
	while (n > 0){
		n -= val;
		val <<= 1;
		cnt++;
	}
	printf("%d",cnt);

	return 0;
}
