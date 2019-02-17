//greedy
#include <stdio.h>
#include <queue>
#include <unordered_map>
using namespace std;
const long long bnd = 1LL << 31;
int p[100];
int main(){
	int i, N, K;
	int k = 0;
	int mx = 0;
	priority_queue<int> q;
	unordered_map<int, int> dict;
	for (scanf("%d%d", &K, &N), i = 0; i < K; ++i) {
		scanf("%d", p + i);
		q.push(-p[i]);
		dict[-p[i]]++;
	}
	while (1) {
		int num = q.top(); q.pop();		
		if (++k == N) {
			printf("%d",-num);
			break;
		}
		for (i = 0; i < K; ++i) {
			long long res = num * (long long)p[i];
			if (res <= -bnd) break;
			if (dict[res]) continue;
			if (q.size() > 5e5 && res <= mx) break;
			if (mx > res) mx = res;
			q.push(res); ++dict[res];
		}
	}

	return 0;
}