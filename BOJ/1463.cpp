//category : dp


#include <stdio.h>


int d[1000001];
int main(){

	int n;
	int t1, t2, t3;
	int i;

	scanf("%d",&n);

	d[1] = 0;
	
	for (i = 2; i <= n; i++){
		t1 = t2=t3=d[i - 1];
		if (i % 2 == 0) t2 = d[i / 2];
		if (i % 3 == 0) t3 = d[i / 3];

		if (t1 > t2) t1 = t2;
		if (t1 > t3) t1 = t3;
		d[i] = t1 + 1;
	}
	printf("%d",d[n]);


	return 0;
}