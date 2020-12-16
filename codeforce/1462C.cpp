//math
#include <stdio.h>
int ans[51];
 
int main(){
	for (int i = 1; i < 1024; ++i) {
		int x = 0; int num = 0;
		for (int j = 0; j < 10; ++j) {
			if (i&(1 << j)) {
				x += j;
				num = num * 10 + j;
			}
			if (x > 0 && x <= 50) {
				if(ans[x]==0 || ans[x]>num)
					ans[x] = num;
			}
		}
	}
	
	int t;
	for (scanf("%d", &t); t--;) {
		int x; scanf("%d",&x);
		printf("%d\n",ans[x]? ans[x]:-1);
	}
 
	return 0;
}