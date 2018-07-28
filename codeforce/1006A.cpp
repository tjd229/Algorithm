//implementation
#include <stdio.h>
int a[1000];
int main(){
	int i;
	int n;
	for (scanf("%d", &n), i = 0; i < n; i++) scanf("%d",a+i);
	for (i = 0; i < n; i++){
		printf("%d ",a[i]&1? a[i]:a[i]-1 );
	}
	return 0;
}
