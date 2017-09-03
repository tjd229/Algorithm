//category : mdp

#include <stdio.h>
#include <queue>
using namespace std;

long long s[100001];
long long d[100001];
int e[100001];

int main(){
	int i;
	int N, K;
	priority_queue<pair<long long, long long> > q;
	scanf("%d%d",&N,&K);
	for (i = 1; i <= N; i++){
		scanf("%d",e+i);
		s[i] = s[i - 1] + e[i];
	}

	for (i = 0; i <= N; i++){
		q.push(make_pair(d[i - 1] - s[i], i));
		while (q.top().second < i - K) q.pop();
		d[i] = q.top().first + s[i];
	}

	printf("%lld",d[N]);


	return 0;
}