//category : implementation

#include <stdio.h>
int n;
int s[100001];
int stk[100001];
int top;
int max(int a, int b){ return a < b ? b : a; }
int main(){
	int i;
	int ans = 0;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d", s + i);
		while (top&&stk[top - 1] < s[i]){
			ans = max(ans, stk[top - 1] ^ s[i]);
			top--;
		}

		if (top)
			ans = max(ans, stk[top - 1] ^ s[i]);
		stk[top++] = s[i];
	}
	printf("%d",ans);
	
	return 0;
}
