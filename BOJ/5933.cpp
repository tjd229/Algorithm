//category : mdp

#include <stdio.h>
#include <deque>
#include <algorithm>
#define ll long long
#define MIN(a,b) a<b? a:b
using namespace std;
//int X[501], F[501], C[501];
struct Store{
	ll X, F, C;
	bool operator<(Store s) const{
		return this->X < s.X;
	}
}s[501];
ll d[501][10001];
int main(){
	int i,j;
	int K, E, N;
	ll cost;
	scanf("%d%d%d",&K,&E,&N);
	for (i = 1; i <= N; i++){
		scanf("%lld%lld%lld",&s[i].X,&s[i].F,&s[i].C);
	}
	s[0].X = s[0].F = s[0].C = 0;
	sort(s+1,s+N+1);

	for (i = 0; i <= N; i++){
		for (j = 0; j <= K; j++){
			d[i][j] = 2e18;
		}
	}d[0][0] = 0;
	for (i = 1; i <= N; i++){
		deque<pair<ll,int> > q;

		for (j = 0; j <= K; j++){

			while (!q.empty() && q.front().second < j - s[i].F)
				q.pop_front();
			cost = d[i - 1][j] - j*s[i].C + (s[i].X - s[i-1].X)*j*j;
			while (!q.empty() && q.back().first >= cost)
				q.pop_back();
			q.push_back(make_pair(cost,j));
			d[i][j] =MIN( q.front().first+j*s[i].C,d[i][j]);
		}
	}
	
	printf("%lld",d[N][K]+(E-s[N].X)*K*K);
	return 0;
}