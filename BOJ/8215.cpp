//category : graph

#include <stdio.h>
#include <vector>
#define ll long long
#define pil pair<int, ll>
using namespace std;
//num, dist, ddepth
vector<int> edge[1000001];
pil children[1000001];
int ddepth[1000001];
int visit[1000001];
ll h[1000001];
void preinspect(int ix){
	visit[ix] = 1;
	int i;
	int num = 0;
	ll d = 0;
	for (i = 0; i < edge[ix].size(); i++){
		int to = edge[ix][i];
		if (visit[to] != 1){
			preinspect(to);
			if (ddepth[ix] < ddepth[to]) ddepth[ix] = ddepth[to];
			num += children[to].first;
			d += children[to].second;
		}
	}
	d += (num << 1);
	children[ix] = { 1+num, d };
	ddepth[ix]+=(num>0);
}
void inspect(int ix, int num, ll dist, int deep){
	visit[ix] = 2;
	int i;
	int mx=num;
	int fd = deep;
	int sd = 0;
	int dir = -1;
	for (i = 0; i < edge[ix].size(); i++){
		int to = edge[ix][i];
		if (visit[to] != 2){
			if (mx < children[to].first){
				deep = ddepth[to]+1;
				mx = children[to].first;
			}
			else if (mx == children[to].first && ddepth[to]+1>deep){
				deep = ddepth[to]+1;
			}
			if (fd < ddepth[to]+1){
				dir = i;
				sd = fd;
				fd = ddepth[to]+1;
			}
			else if (sd < ddepth[to]+1) sd = 1+ddepth[to];
			num += children[to].first;
			dist += children[to].second + (children[to].first<<1);			
		}
	}
	int r = num - mx;
	if (num == 0 || mx == r + 1) h[ix] = dist - deep;
	else if (mx <= r) h[ix] = dist - fd;
	//else if (mx == r + 1) h[i] = dist - deep;
	for (i = 0; i < edge[ix].size(); i++){
		int to = edge[ix][i];
		if (visit[to] != 2){
			int n = num - children[to].first+1;
			ll d = dist - (children[to].second + (children[to].first << 1)) + (n<<1);
			inspect(to, n, d, dir == i ? sd+1 : fd+1);
		}
	}
}
int main(){
	int i;
	int n;
	int a, b;
	for (scanf("%d", &n), i = 1, h[n] = -1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
		h[i] = -1;
	}
	preinspect(1);
	inspect(1,0,0,0);
	for (i = 1; i <= n; i++) printf("%lld\n", h[i]);
	return 0;
}
