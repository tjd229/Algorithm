//math, greedy
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000007764/0000000000036601


#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
int e[100001];
int d[100001];
int nxt[100001];
int main() {
	int tc, T;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		int i, N,L;
		int mx = 0;
		vector<int> fix;
		priority_queue<pair<double,int> > q;
		for (scanf("%d%d", &N, &L), i = 1; i <= N; ++i) {
			e[i] = round(i*100.0 / N);
			d[i] = e[i] - e[i - 1];
			if (mx < d[i]) mx = d[i];
		}
		int r = N+1;
		for (i = N; i >= 0; --i) {
			nxt[i] = r;
			if (d[i] == mx) r = i;
		}
		int remain = N;
		for (i = 0; i < L; ++i) {
			int resp; scanf("%d",&resp);
			remain -= resp;
			int step = nxt[resp]-resp;
			double profit = 1.0 / step;
			q.push({profit,resp});
		}
		q.push({1.0/nxt[0],0});
		while (q.size() && remain) {
			int now = q.top().second; q.pop();
			int step = nxt[now] - now;
			if (step > remain) {
				fix.push_back(now);
				continue;
			}
			if (now == 0)
				q.push({1.0/nxt[0],0});
			remain -= step;
			now += step;
			step= nxt[now] - now;
			q.push({1.0/step,now});
		}
		int y = 0;
		
		for (auto resp : fix)
			y += e[resp];
		while (q.size()) {
			int now = q.top().second; q.pop();
			y += e[now];
		}
		if (remain) y += e[remain];
		printf("Case #%d: %d\n",tc,y);
		/*for (i = 0; i <= N; ++i)
			printf("%d,%d,%d\n",e[i],d[i],nxt[i]);*/
		
	}

	return 0;
}