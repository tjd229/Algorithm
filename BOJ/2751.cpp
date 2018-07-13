//implementation

#include <stdio.h>
int a[1000000];
int tmp[1000000];
void sort(int s,int e,int *a){
	if (s == e) return;
	int m = (s + e) >> 1;
	sort(s, m, a);
	sort(m + 1, e, a);
	int l = s;
	int r = m + 1;
	int ix = l;
	while (l <= m || r <= e){
		if (l > m) tmp[ix++] = a[r++];
		else if (r > e) tmp[ix++] = a[l++];
		else{
			tmp[ix++] = a[l] < a[r] ? a[l++] : a[r++];
		}
	}
	for (ix = s; ix <= e; ix++) a[ix] = tmp[ix];
}
int main(){
	int i;
	int N;
	for (scanf("%d", &N), i = 0; i < N; i++) scanf("%d",a+i);
	sort(0, N - 1, a);
	for (i = 0; i < N; i++) printf("%d\n",a[i]);
}
