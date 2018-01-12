//category : implementation

#include <stdio.h>
char inst[10];
int N;
int q[20001];
int sz;
int main(){
	int X;
	int *link = q;
	link += 10000;
	for (scanf("%d", &N); N--;){
		scanf("%s", inst);
		switch (inst[0]){
		case 'b':
			printf("%d\n", sz ?  link[sz-1]:-1);
			break;
		case 'f':
			printf("%d\n", sz ? link[0]:-1);
			break;
		case 'e':
			printf("%d\n",sz==0);
			break;
		case 's':
			printf("%d\n",sz);
			break;
		case 'p':
			if (inst[1] == 'u'){
				scanf("%d", &X);
				if (inst[5] == 'f'){
					--link;
					link[0] = X;
				}
				else link[sz] = X;
				sz++;
			}
			else{
				if (sz == 0) printf("-1\n");
				else if (inst[4] == 'f'){
					printf("%d\n", link[0]);
					++link;
					sz--;
				}
				else{
					printf("%d\n", link[--sz]);
				}
			}
		}

	}
}
