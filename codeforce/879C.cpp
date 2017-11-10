//category : math

#include <stdio.h>

int main(){
	int i;
	int n;
	int x1,x2;
	int stat;
	char op;
	int a = 0;
	int b = 1023;
	for (scanf("%d", &n), i = 0; i < n; i++){
		scanf(" %c%d",&op,&x1);
		switch (op){
		case '|':
			a |= x1;
			b |= x1;
			break;
		case '^':
			a ^= x1;
			b ^= x1;
			break;
		case '&':
			a &= x1;
			b &= x1;
			break;
		}
	}
	x1 = x2 = 0;
	for (i = 1; i < 1024; i<<=1){
		if ((i&a) && (i&b)) x1 += i;
		if (!(i&a) && !(i&b)) x1 += i, x2 += i;
		if ((i&a) && !(i&b)) x2 += i;
	}
	printf("2\n| %d\n^ %d",x1,x2);

	return 0;
}
