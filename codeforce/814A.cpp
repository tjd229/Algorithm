//category : implementation

#include <stdio.h>
#include <algorithm>
int a[200];
int copy[200];
int b[200];
int main(){
	int i;
	int n, k;
	int ix = -1;
	int mx = -1;
	bool yes=false;
	scanf("%d%d",&n,&k);
	for (i = 0; i < n; i++){
		scanf("%d",a+i);
		if (a[i] == 0) {
			yes = (ix != -1);
			ix = i;
		}
		copy[i] = a[i];
	}
	for (i = 0; i < k; i++){
		scanf("%d",b+i);
	}
	if (yes){
		printf("Yes");
		return 0;
	}	
	a[ix] = b[0];
	for (i = 1; i < n; i++){
		if (a[i - 1] >= a[i]) yes = true;
	}
	printf("%s",yes? "Yes":"No");
	return 0;
}