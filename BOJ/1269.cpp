//category : line sweeping
#include <stdio.h>
int A[200001];
int B[200001];
int tmp[200001];
void merge_sort(int s,int e,int *a){
	if (s == e) return;
	int m = (s + e) >> 1;
	merge_sort(s, m,a);
	merge_sort(1+m,e,a);
	int len = e - s + 1;
	int ix1, ix2;
	int i;
	for (i = 0,ix1=s,ix2=m+1; i < len; i++){
		if (ix1 > m){
			tmp[s + i] = a[ix2++];
		}
		else if (ix2 > e) tmp[s + i] = a[ix1++];
		else tmp[s + i] = a[ix1] < a[ix2] ? a[ix1++] : a[ix2++];
	}
	for (i = 0; i < len; i++)
		a[i + s] = tmp[s + i];

}
int main(){
	int i, j;
	int na,nb;
	for (scanf("%d%d", &na, &nb), i = 0; i < na; i++)
		scanf("%d",A+i);
	for (i = 0; i < nb; i++)
		scanf("%d",B+i);
	merge_sort(0, na - 1, A);
	merge_sort(0, nb - 1, B);
	int u = 0;
	i = j = 0;
	for (i = j = 0; i < na&&j < nb; j++){
		while (i < na&&B[j] > A[i]) i++;
		if (i<na&&A[i] == B[j]){
			u++;
			i++;
		}
	}
	printf("%d",na+nb-u-u);
	return 0;
}
