//category : greedy

#include <stdio.h>
int machine[101];
int last[101];
int nxt[101];
int plug[101];
int priority[101];
bool use[101];
int main(){
	int i, j;
	int N, K;
	int pos, far;
	int ans = 0;
	for (scanf("%d%d", &N, &K), i = 1; i <= K; i++){
		scanf("%d", machine + i);
		nxt[last[machine[i]]] = i;
		last[machine[i]] = i;
		nxt[i] = K + 1;
	}
	for (i = 1; i <= K; i++){
		if (use[machine[i]]) continue;
		pos = 0;
		for (j = 1; j <= N; j++){
			if (plug[j] == 0){
				pos = j;
			}
		}
		if (pos == 0){
			far = 0;
			ans++;
			for (j = 1; j <= N; j++){
				while (priority[j] <= i)
					priority[j] = nxt[priority[j]];
				if (far < priority[j]){
					far = priority[j];
					pos = j;
				}
			}
		}
		use[plug[pos]] = false;
		use[machine[i]] = true;
		priority[pos] = nxt[i];
		plug[pos] = machine[i];
	}
	printf("%d", ans);
}
