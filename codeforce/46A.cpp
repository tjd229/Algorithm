//category : math

#include <stdio.h>

int main(){
	int n;
	int range = 1;
	int curr=1;
	scanf("%d",&n);
	for (int i = 1; i < n; i++,range++){
		curr += range;
		if (curr > n) curr %= n;
		if (range > n) curr %= n;
		printf("%d ",curr);
	}
	return 0;
}