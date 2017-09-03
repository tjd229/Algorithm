//category : ft



#include <stdio.h>
#define BI (1<<17)
int ft[BI + 1];
int arr[100001];
void update(int ix, int diff){
	while (ix <= BI){
		ft[ix] += diff;
		ix += (ix&-ix);
	}
}
int sum(int ix){
	int s = 0;
	while (ix != 0){
		s += ft[ix];
		ix -= (ix&-ix);
	}
	return s;
}
int main(){
	int N;
	int i;
	int buff;
	int s = 1,e;
	scanf("%d", &N);
	e = N;
	for (i = 1; i <= N; i++) scanf("%d", &buff), arr[buff] = i;
	for (i = 1; i <= N; i++) update(i, 1);
	for (i = 1; i <= N; i++){
		if (i % 2 == 0){
			printf("%d\n", ft[BI] - sum(arr[e]));
			update(arr[e--], -1);
		}
		else{
			printf("%d\n", sum(arr[s] - 1));
			update(arr[s++], -1);
		}
		
	}
	return 0;
}
