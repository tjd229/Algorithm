//category : graph, ft



#include <stdio.h>
#include <vector>
using namespace std;
int pay[500001];
int pre[500001];
int post[500001];
vector<int> edge[500001];
int cnt = 0;
long long ft[1 << 19];
int limit = 1 << 19;
void dfs(int ix){
	pre[ix] = ++cnt;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i]);
	post[ix] = cnt;
}
long long sum(int ix){
	long long res = 0;
	while (ix!=0){
		res += ft[ix];
		ix -= (ix&-ix);
	}
	return res;
}
void update(int ix,long long d){
	while (ix<limit){
		ft[ix] += d;
		ix += (ix&-ix);
	}
}
int main(){
	int i;
	int N, M;
	int p;
	char q;
	int a, x;
	scanf("%d%d",&N,&M);
	scanf("%d",pay+1);
	for (i = 2; i <= N; i++){
		scanf("%d%d",pay+i,&p);
		edge[p].push_back(i);
	}
	dfs(1);
	while (M--){
		scanf(" %c%d",&q,&a);
		if (q == 'u'){
			printf("%lld\n",sum(pre[a])+pay[a]);
		}
		else{
			scanf("%d",&x);
			update(pre[a]+1, x);
			update(post[a]+1, -x);
		}
	}
	return 0;
}