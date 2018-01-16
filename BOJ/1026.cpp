//category : cnt sort
#include <stdio.h>
int A[50], B[50];
int N;
void cnt_sort(int *arr){
	int i;
	int tmp[50];
	int cnt[101] = { 0 };
	for (i = 0; i < N; i++) cnt[arr[i]]++;
	for (i = 1; i <= 100; i++) cnt[i] += cnt[i - 1];
	for (i = N - 1; i >= 0; i--) tmp[--cnt[arr[i]]] = arr[i];
	for (i = 0; i < N; i++) arr[i] = tmp[i];
}
int main(){
	
	int i;
	int ans = 0;
	for (scanf("%d", &N), i = 0; i < N; i++) scanf("%d",A+i);	
	for (i = 0; i < N; i++) scanf("%d",B+i);
	cnt_sort(A);
	cnt_sort(B);
	for (i = 0; i < N; i++) ans += A[i] * B[N - i-1];
	
	printf("%d",ans);
	return 0;
}
