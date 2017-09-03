//category : line sweeping



#include <stdio.h>
#define MAX(a,b) a>b? a:b
char present[100001];
int s[2][100001];
int main(){
	int i;
	int n, k;
	int l, r;
	int ans=0;
	scanf("%d%d",&n,&k);
	for (i = 1; i <= n; i++){
		scanf(" %1c", present + i);
		s[0][i] = s[0][i - 1];
		s[1][i] = s[1][i - 1];
		s[present[i] - 'a'][i] += 1;
	}
	
	for (i = 0; i < 2; i++){
		l = r = 1;
		while (r<=n&&l<=r){
			if (k < s[i][r] - s[i][l - 1]){
				l++;
				if (l>r) r++;
			}
			else{
				ans=MAX(ans,r - l + 1);
				r++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}