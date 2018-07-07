//category : implementation

#include <stdio.h>
int a[1000000];
int b[1000000];
int main(){
	int i;
	int n;
	int s,e;
	bool can = false;
	for (scanf("%d", &n), i = 0; i < n; i++) scanf("%d",a+i);
	for (i = 0; i < n; i++){
		scanf("%d",b+i);
		if (b[i] == a[0]) s = i;
		if (b[i] == a[n - 1]) e = i;
	}
	for (i = 0; i < n; i++)
		if (a[i] != b[(s + i) % n]) break;
	can = (i == n);
	for (i = 0; i < n && !can; i++){
		if (a[n-1-i] != b[(e + i) % n]) break;		
	}
	if(!can) can = (i == n);
	printf("%s puzzle", can? "good":"bad");
	return 0;
}
