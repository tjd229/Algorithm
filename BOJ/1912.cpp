//category : dp

#include <stdio.h>

int d[100000];
int s[100000];


int main(){

	int n;
	int i,j;
	int t;
	
	scanf("%d",&n);
	for (i = 0; i < n; i++){
		scanf("%d", &d[i]);
	}
	s[n-1] = d[n-1];
	int ans = d[n - 1];
	for (i = n - 2; i >= 0; i--){
		s[i] = d[i] > d[i] + s[i + 1] ? d[i] : d[i] + s[i + 1];
		if (ans < s[i]) ans = s[i];
	}
	
	printf("%d",ans);

	return 0;
}

