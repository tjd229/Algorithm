//category : greedy

#include <stdio.h>
#include <algorithm>
using namespace std;
int w[1000];
int main(){
	int i;
	int N;
	int s = 0;
	for (scanf("%d", &N), i = 0; i < N; i++) scanf("%d",w+i);
	sort(w, w + N);
	for (i = 0; i < N; i++){
		if (s + 1 < w[i]) break;
		s+=w[i];
	}
	printf("%d",s+1);

	return 0;
}
