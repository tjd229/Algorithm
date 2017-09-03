//category : dp

#include <stdio.h>


int d[1000000];
int main(){

	int n, m;
	int i;
	int nm;
	int x, y;
	scanf("%d %d",&n,&m);
	
	for (x=i = 0; i < n; i++){
		for (nm = 0; nm < m; nm++) scanf("%d",&d[x++]);
	}
	nm = n*m;
	for (i = 1; i < nm; i++){
		x = y = 0;
		if (i >= m) y = d[i - m];
		if (i%m != 0) x = d[i - 1];
		if (x < y) x = y;
		d[i] += x;
	}
	printf("%d",d[nm-1]);
	return 0;
}

