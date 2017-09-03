//category : implementation

#include <stdio.h>

int main(){
	int n;
	int a;
	int last;
	int res = 0;
	int cnt = 0;
	scanf("%d%d", &n, &last);
	while (--n){
		scanf("%d", &a);
		cnt++;
		if (last > a) res=cnt;
		last = a;
	}
	
	printf("%d", res);
}