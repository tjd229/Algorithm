//dp
#include <stdio.h>
int kill(int n) {
	if (n == 1) return 0;
	int k = n >> 1;
	int r = n & 1;
	int x = (kill(n - k) - r + n - k) % (n-k);
	return x + x;
}
int main() {
	int N;
	scanf("%d",&N);
	printf("%d",N==1? 1:kill(N-1)+2);
	return 0;
}
