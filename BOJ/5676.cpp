//category : st

#include <stdio.h>
#include <memory.h>
#define LEAF (1<<17)
int st[LEAF + LEAF];
void update(int ix){
	while (ix != 0){
		st[ix] = st[ix + ix] * st[ix + ix + 1];
		ix = (ix >> 1);
	}	
}
void paste(int ix, int v){
	if (v > 0) v = 1;
	if (v<0) v = -1;
	st[ix] = v;
	update((ix >> 1));
}
int product(int ix,int s,int e,int from,int to){
	if (from > e || to < s) return 1;
	if (from <= s&&to >= e) return st[ix];
	return product(ix + ix, s, (s + e) / 2, from, to)*product(ix + ix + 1, (s + e) / 2 + 1, e, from, to);
}
int main(){
	int N, K;
	int buff;
	int i;
	char code;
	while (scanf("%d%d", &N, &K) == 2){
		for (i = 1; i < LEAF + LEAF; i++) st[i] = 1;
		for (i = 0; i<N;i++)
		{
			scanf("%d",&buff);
			if (buff < 1) paste(LEAF + i, buff);
		}
		do{
			scanf(" %c%d%d",&code,&i,&buff);
			if (code == 'C'){
				paste(LEAF - 1 + i, buff);
			}
			else if (code == 'P'){
				N = product(1, 0, LEAF-1, i-1, buff-1);
				if (N == 0) printf("0");
				else if (N < 0)printf("-");
				else printf("+");
			}
		} while (--K);
		printf("\n");
	}
	
	return 0;
}
