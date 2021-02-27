//math
#include <stdio.h>
void print(int n, int val) {
	while (n--) printf("%d",val);
}
int main() {
	int a, b, k; scanf("%d%d%d",&a,&b,&k);
	int len = a + b;
	if (k == 0) {
		printf("Yes\n");
		print(b, 1); print(a, 0); puts("");
		print(b, 1); print(a, 0); puts("");
	}
	else {
		if (b == 1 || a==0) {
			printf("No\n");
			return 0;
		}
		if (a >= k) {
			printf("Yes\n");
			print(b, 1); print(a, 0); puts("");
			print(b - 1, 1); print(k, 0); print(1, 1); print(a - k, 0);
		}
		else if(a>0 && a+b-2>=k){//a<k
			printf("Yes\n");
			print(b - (k - a), 1); print(a - 1, 0); print(k - a, 1); print(1, 0); puts("");
			print(b - 1 - (k - a), 1); print(a, 0); print(k - a, 1); print(1, 1);
		}
 
		else{
			printf("No\n");
			return 0;
		}
	}
	return 0;
}