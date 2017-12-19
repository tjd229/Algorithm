//category : graph, MCMF, SPFA

#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#define RIGHT 40
#define SRC 0
#define SINK RIGHT+RIGHT+1
#define pii pair<int,int>
#define ll long long
using namespace std;
struct Edge{
	int to;
	int cap;
	int r;
	int num;
	int deno;
	float cost;
};
pii from[SINK + 1];
vector<Edge> edge[SINK+1];
float d[SINK + 1];
int visit[SINK + 1];
int N;
ll gcd(ll a, ll b){
	if (a == 0) return b;
	return gcd(b%a, a);
}
void add_edge(int u,int v,int num,int deno){
	Edge e;
	edge[u].push_back(e);
	edge[v].push_back(e);
	Edge *fe = &edge[u][edge[u].size() - 1];
	Edge *be = &edge[v][edge[v].size() - 1];
	fe->to = v;
	fe->num = num;
	fe->deno = deno;
	fe->cost = -log(num / (float)deno);
	fe->cap = 1;
	fe->r = edge[v].size() - 1;
	be->to = u;
	be->num = num;
	be->deno = deno;
	be->cost = -fe->cost;
	be->cap = 0;	
	be->r = edge[u].size() - 1;
	//printf("add:%f,%f\n", fe->cost,be->cost);
}
bool spfa(int stamp){
	bool inq[SINK + 1] = { 0 };
	queue<int> q;
	q.push(SRC);
	inq[SRC] = true;
	from[SRC] = from[SINK] = {-1,-1};
	int curr, to;
	int i;
	Edge *e;
	while (!q.empty()){
		curr = q.front();
		q.pop();
		inq[curr] = false;
		for (i = 0; i < edge[curr].size(); i++){
			e = &edge[curr][i];
			to = e->to;
			
			if (e->cap > 0 &&
				(visit[to] != stamp||d[to] > d[curr] + e->cost)){
				visit[to] = stamp;
				d[to] = d[curr] + e->cost;
				from[to] = { curr, i };
				if (!inq[to]){
					inq[to] = true;
					q.push(to);
				}
			}
		}
	}
	if (visit[SINK] != stamp) return false;
	curr = SINK;
	do{
		e = &edge[from[curr].first][from[curr].second];
		e->cap -= 1;
		edge[e->to][e->r].cap += 1;
		curr = from[curr].first;
	} while (curr != SRC);
	return true;
}
void flow(){
	static int stamp = 1;
	while (spfa(stamp++));
	int i, j;
	ll a, b,div;
	a = b = 1;
	int n[RIGHT + 1] = { 0 };
	int d[RIGHT + 1] = { 0 };
	for (i = 1; i <= N; i++){
		for (j = 0; j < edge[RIGHT + i].size(); j++){
			if (edge[RIGHT + i][j].cap>0){
				n[edge[RIGHT + i][j].to] = edge[RIGHT + i][j].num;
				d[edge[RIGHT + i][j].to] = edge[RIGHT + i][j].deno;
				break;
			}
		}
	}
	for (i = 1; i <= N; i++){
		if (d[i] == 0){
			printf("1/1\n");
			return;
		}
		a *= n[i];
		b *= d[i];
		div=gcd(a, b);
		a /= div;
		b /= div;
	}
	printf("%lld/%lld\n",b-a,b);
}
int main(){
	int T;
	int i, j;
	int a, b;
	for (scanf("%d", &T); T--;){
		for (scanf("%d", &N), i = 1; i <= N; i++){
			
			for (j = 1; j <= N; j++){
				scanf("%d/%d",&a,&b);
				if (a != b)
					add_edge(i,RIGHT+j,b-a,b);
			}
			add_edge(SRC, i, 1, 1);
			add_edge(RIGHT+i, SINK, 1, 1);
		}
		flow();
		for (i = 1; i <= N; i++){
			edge[i].clear();
			edge[i + RIGHT].clear();
		}
		edge[SRC].clear();
		edge[SINK].clear();
	}
	return 0;
}
