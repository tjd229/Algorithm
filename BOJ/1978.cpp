//category : math
#include <stdio.h>
int filter[1001];
int main(){
	int N;
	int i,j;
	
	for (i = 2; i <= 1000;i++){
		if (filter[i]) continue;
		j = i + i;
		while (j <= 1000){
			filter[j] = 1;
			j += i;
		}
	}
	filter[1] = 1;
	j = 0;
	for (scanf("%d", &N); N--;){
		scanf("%d",&i);
		j += filter[i] == 0;
	}
	printf("%d",j);
}
