//category : math

#include <stdio.h>
int cnt[1000];
int main(){
	int i;
	int n;
	int a;
	int half;
	bool y=true;
	scanf("%d",&n);
	half = n / 2 + (n&1);

	for (i = 0; i < n; i++){
		scanf("%d",&a);
		cnt[a]++;
		if (cnt[a]>half) y = false;
	}
	printf("%s",y? "YES":"NO");
	return 0;
}