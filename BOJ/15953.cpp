//implementation

#include <stdio.h>
int m7[7] = {0,500,300,200,50,30,10};
int m8[6] = {0,512,256,128,64,32};
int p7[101], p8[101];
int main(){
	int i,j,k;
	int T, a, b;
	for (i = 1, k = 1; i <= 6; i++){
		for (j = 1; j <= i; j++) p7[k++] = m7[i];
	}
	for (i = 0, k = 1; i < 5; i++){
		int b = 1 << i;
		for (j = 1; j <= b; j++) p8[k++] = m8[i + 1];
	}
	
	for (scanf("%d", &T); T--;){
		scanf("%d%d",&a,&b);
		int tot = p7[a] + p8[b];
		if (tot) printf("%d0000\n",tot);
		else puts("0");
	}

	return 0;
}
