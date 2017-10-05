//category : implementation

#include <stdio.h>
int num[101];
int ans[101];
int main(){
	int i;
	int n;
	int a;
	int c = 0;
	scanf("%d",&n);
	while (n--){
		scanf("%d",&a);
		if (num[a] == 0){
			ans[c] = a;
			c++;
		}
		num[a]++;
	}
	if (c != 2) printf("NO");
	else if (num[ans[0]] != num[ans[1]]) printf("NO");
	else{
		printf("YES\n%d %d",ans[0],ans[1]);
	}
	return 0;
}