//category : implementation
#include <stdio.h>
char inst[10];
int N;
int q[100000];
int front, back;
int main(){
	int X;
	for (scanf("%d", &N); N--;){
		scanf("%s", inst);
		switch (inst[0]){
		case 'b':
			printf("%d\n", front == back ? -1 : q[back-1]);
			break;
		case 'f':
			printf("%d\n", front == back ? -1 : q[front]);
			break;
		case 'e':
			printf("%d\n",back==front);
			break;
		case 's':
			printf("%d\n",back-front);
			break;
		case 'p':
			if (inst[1] == 'u'){
				scanf("%d",&X);
				q[back++] = X;
			}
			else printf("%d\n",front==back? -1:q[front++]);
		}

	}
}
