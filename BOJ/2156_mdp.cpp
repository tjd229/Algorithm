//category : mdp


#include <stdio.h>
#include <deque>
using namespace std;
int s[10001];
int d[10001];
int main(){
	int i;
	int n;
	deque<int> q;
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		scanf("%d",s+i);
		s[i] += s[i - 1];
	}
	
	for (i = 0; i <= n; i++){
		while (!q.empty() && q.front() < i - 2) q.pop_front();
		while (!q.empty() && d[q.back() - 1] - s[q.back()] <= d[i - 1] - s[i]) q.pop_back();
		q.push_back(i);
		d[i] = d[q.front()-1]-s[q.front()] + s[i];
	}

	printf("%d",d[n]);

	return 0;
}