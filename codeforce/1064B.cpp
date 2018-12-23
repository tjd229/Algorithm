//math

#include <stdio.h>
int main(){
	int a, t;
	for (scanf("%d", &t); t--;){
		scanf("%d",&a);
		long long ans = 1;
		
		while (a){
			if (a & 1) ans <<= 1;
			a >>= 1;
		}
		printf("%I64d\n",ans);
		
	}

	return 0;
}
