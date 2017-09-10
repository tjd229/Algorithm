//category : math

#include <stdio.h>
int ans1, ans2;
float max;
int gcd(int a, int b){
	if (a%b == 0) return b;
	return gcd(b, a%b);
}
int main(){
	int n;
	int half;
	float fvalue;
	int ivalue;
	scanf("%d",&n);
	half = n >> 1;
	ans1 = 1;
	ans2 = n - 1;
	max = 1.f / (float)ans2;
	for (int i = 2; i <= half; i++){
		if (i + i == n) continue;
		if (gcd(n - i, i) != 1) continue;
		fvalue = (float)i / (float)(n - i);
		
		if (max < fvalue){
			ans1 = i;
			ans2 = n - i;
			max = fvalue;
		}
	}
	printf("%d %d",ans1,ans2);

	return 0;
}