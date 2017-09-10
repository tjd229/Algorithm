//category : bs


#include <stdio.h>
#define MIN(a,b) a<b? a:b
int N, L, W, H;
bool check(double A){
	long long n1 = L / A;
	long long n2 = W / A;
	long long n3 = H / A;
	return n1*n2*n3 < N;
}
int main(){
	double l, r, mid;
	scanf("%d%d%d%d",&N,&L,&W,&H);
	l = 0;
	r = 1000000000;
	int cnt=10000;
	while (cnt--){
		mid = (l + r) / 2;
		if (check(mid)){
			r = mid;
		}
		else l = mid;
	}

	printf("%.10lf", l);

	return 0;
	
}

//reference : https://fatc.club/2017/03/01/335