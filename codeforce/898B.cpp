//category : implementation
#include <stdio.h>

int main(){
	int i;
	int n, a, b;
	int cost;
	int r;
	scanf("%d%d%d",&n,&a,&b);
	for (i = 0; i <= 10000000; i++){
		//
		cost = i*a;
		r = n - cost;
		if (r < 0) break;
		if (r%b == 0){
			printf("YES\n%d %d",i,r/b);
			return 0;
		}
	}
	printf("NO");
	return 0;
}
