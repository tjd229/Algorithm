//category : d&c

#include <stdio.h>
int s[129][129];
int b, w;
void cut(int rx,int dy,int len){
	int sum = s[dy][rx] - s[dy - len][rx] - s[dy][rx - len] + s[dy - len][rx - len];
	if (sum == 0) w++;
	else if (sum == len*len) b++;
	else{
		len >>= 1;
		cut(rx, dy, len);
		cut(rx - len, dy, len);
		cut(rx - len, dy - len, len);
		cut(rx, dy - len, len);
	}
}
int main(){
	int N;
	int i, j;
	for (scanf("%d", &N), i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%d",&s[i][j]);
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	cut(N, N, N);
	printf("%d\n%d",w,b);
	return 0;
}
