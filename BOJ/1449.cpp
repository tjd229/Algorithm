//category : greedy

#include <stdio.h>
#include <algorithm>
using namespace std;
int pos[1000];
int main(){
	int i;
	int N, L;
	int s;
	s = -5000;
	int ans = 0;
	for (scanf("%d%d", &N, &L), i = 0; i < N; i++){
		scanf("%d",pos+i);
	}
	sort(pos, pos + N);
	for (i = 0; i < N; i++){
		if (pos[i] - s > L-1){
			s = pos[i];
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
