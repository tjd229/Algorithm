//category : d&c, implementation



#include <stdio.h>
int A[1000];
int temp[1000];

void merge(int s, int m, int e){
	int ix1 = s;
	int ix2 = m;

	for (int i = s; i < e; i++){
		if (ix1 == m){
			temp[i] = A[ix2];
			ix2++;
		}
		else if (ix2 == e){
			temp[i] = A[ix1];
			ix1++;
		}
		else if (A[ix1] >A[ix2]){
			temp[i] = A[ix2];
			ix2++;
		}
		else{
			temp[i] = A[ix1];
			ix1++;
		}
	}
	for (int i = s; i < e; i++){
		A[i] = temp[i];
	}
}
void mergesort(int s, int e){
	if (e - s <= 1)
		return;
	int m = (s + e) / 2;
	mergesort(s, m);
	mergesort(m, e);
	merge(s, m, e);
}
int main(){
	int i;
	int N;
	scanf("%d",&N);
	for (i = 0; i < N; i++) scanf("%d", A + i);
	mergesort(0, N);
	for (i = 0; i < N; i++) printf("%d\n", A[i]);
	return 0;
}