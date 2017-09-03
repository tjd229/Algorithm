//category : string, KMP

#include <stdio.h>

char s[1000000];
int pi[1000000];
int main(){
	int L;
	int i, j = 0;
	scanf("%d", &L);
	scanf("%s", s);
	for (i = 1; i < L; i++){
		while (j>0&&s[j] != s[i]){
			j = pi[j - 1];
		}
		if (s[j] == s[i]) pi[i] = ++j;
	}
	printf("%d", L - pi[L - 1]);
	return 0;
}