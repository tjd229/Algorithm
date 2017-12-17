//category : math, greedy

#include <stdio.h>

int main(){
	int n;
	int h;
	int s, e;
	scanf("%d",&n);
	h = n >> 1;
	if (n == 2){
		printf("1\n1 1");
	}
	else if (n == 3){
		printf("0\n2 1 2");
	}
	else{
		if (h & 1){
			if (n & 1){
				printf("0\n%d 1",h+1);
				s = 2;
				e = n;
				for (int i = 0; i < h/2; i++){
					printf(" %d %d",s,e);
					s += 2;
					e -= 2;

				}
				printf(" %d",s);
			}
			else{
				printf("1\n%d", h);
				s = 1;
				e = n;
				for (int i = 0; i < h / 2; i++){
					printf(" %d %d", s, e);
					s += 2;
					e -= 2;
				}
				printf(" %d", s);
			}
		}
		else{
			if (n & 1){
				printf("1\n%d 1", h+1);
				s = 2;
				e = n;
				for (int i = 0; i < h / 2; i++){
					printf(" %d %d", s, e);
					s += 2;
					e -= 2;
				}
			}
			else{
				printf("0\n%d", h);
				s = 1;
				e = n;
				for (int i = 0; i < h / 2; i++){
					printf(" %d %d", s, e);
					s += 2;
					e -= 2;
				}
			}
		}
	}
}
