//category : graph, dp

#include <stdio.h>
#include <vector>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
const int BND = 100000;
vector<pii > edge[BND + 1];
int visit[BND + 1];
int stat[BND + 1];
vector<int> vec[2];
int cnt;
int stamp;
int n, m;

int min(int a, int b){ return a < b ? a : b; }
int color(int ix, int pick, int target, int stamp, vector<int> &hist){
	int res = 0;
	int to;
	int c;
	if (visit[ix] == stamp){
		if (stat[ix] == pick) return 0;
		return BND + BND;
	}
	//printf("%d|%d|%d\n",ix,pick,target);
	res = pick;
	stat[ix] = pick;
	visit[ix] = stamp;
	if (pick) hist.push_back(ix);
	for (int i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i].first;
		c = edge[ix][i].second^pick;
		res += color(to, c == target ? 0 : 1, target, stamp, hist);
		if (res > BND) return res;
	}
	return res;
}
int color(int target){
	int i;
	int res = 0;
	int c1, c2;
	int s = ++stamp;
	vector<int> v1, v2;
	for (i = 1; i <= n; i++){
		if (visit[i] >= s) continue;
		v2.clear();
		v1.clear();
		c1 = color(i, 0, target, stamp++, v1);
		c2 = color(i, 1, target, stamp++, v2);
		res += min(c1, c2);
		if (res > BND) return BND + 1;
		if (c1 > c2){
			while (!v2.empty()) vec[target].push_back(v2.back()), v2.pop_back();
		}
		else{
			while (!v1.empty()) vec[target].push_back(v1.back()), v1.pop_back();
		}

	}

	return res;
}

int main(){
	int i;
	int u, v, clr;
	char c;
	for (scanf("%d%d", &n, &m), i = 0; i < m; i++){
		scanf("%d%d %c", &u, &v, &c);
		clr = 0;
		if (c == 'B') clr = 1, cnt++;
		edge[u].push_back(mp(v, clr));
		edge[v].push_back(mp(u, clr));
	}
	if (cnt == 0 || cnt == m){
		printf("0");
		return 0;
	}
	u = color(0); v = color(1);
	if (u > BND&&v > BND){
		printf("-1");
		return 0;
	}
	clr = u > v ? 1 : 0;

	printf("%d\n", vec[clr].size());
	for (i = 0; i < vec[clr].size(); i++)
		printf("%d ", vec[clr][i]);



	return 0;
}
//reference : http://codeforces.com/contest/662/submission/17328977