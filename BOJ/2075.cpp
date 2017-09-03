//category : greedy

#include <stdio.h>
#include <queue>
using namespace std;
int main(){
	int N;
	int x;
	int i, j;
	priority_queue<int> q;
	scanf("%d",&N);
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf("%d",&x);
			q.push(-x);
			if (q.size()>N) q.pop();
		}
	}
	printf("%d",-q.top());
	return 0;
}

