//category : d&c 

#include <stdio.h>
int N, r, c;
int ans;
bool search(int x,int y,int n){
	int d = 1 << n;
	if (!(x <= c&&c < x + d&&y <= r&&r < y + d)){
		return false;
	}
	if (n == 0)
		return x == c&&y == r;
	n = n - 1;
	d /= 2;
	int i, j;
	int cnt = 0;
	
	bool res;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			res = search(x+j*d,y+i*d,n);
			if (res){
				ans += d*d*cnt;
				return true;
			}
			cnt++;
		}
	}
	return false;
}
int main(){
	scanf("%d%d%d",&N,&r,&c);
	search(0, 0, N);
	printf("%d",ans);

	return 0;
}