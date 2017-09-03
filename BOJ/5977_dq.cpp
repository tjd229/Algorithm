//category : mdp

#include <stdio.h>
#include <deque>
using namespace std;
long long s[100001];
long long d[100001];
int main(){
	int i;
	int N, K;
	deque<int> q;
	scanf("%d%d",&N,&K);
	for (i = 1; i <= N; i++){
		scanf("%lld",s+i);
		s[i] += s[i - 1];
	}
	for (i = 0; i <= N; i++){
		while (!q.empty() && q.front() < i - K) q.pop_front();
		while (!q.empty() 
			&& d[q.back() - 1] - s[q.back()] <= d[i - 1] - s[i])
			q.pop_back();
		q.push_back(i);
		d[i] = d[q.front() - 1] - s[q.front()] + s[i];		
	}
	printf("%lld", d[N]);
	return 0;
}