//category : d&c

#include <stdio.h>
struct History{
	int from;
	int to;
};
History h[1<<20];
int ix=0;
void hanoi(int n,int s,int m,int e){
	if (n == 1){
		h[ix].from = s;
		h[ix].to = e;
		ix++;
		return;
	}
	hanoi(n - 1, s, e, m);

	h[ix].from = s;
	h[ix].to = e;
	ix++;

	hanoi(n - 1, m, s, e);
}
int main(){
	int N;
	scanf("%d",&N);
	hanoi(N,1,2,3);
	int cnt = ix;
	printf("%d\n",cnt);
	for (int i = 0; i < cnt; i++){
		printf("%d %d\n",h[i].from,h[i].to);
	}
	return 0;
}