//category : graph, djs

#include <stdio.h>
#include <vector>
using namespace std;
int cnt;
int p[100001];
int pre[100001];
int post[100001];
vector<int> edge[100001];
vector<pair<int, int> > q;
vector<pair<int, int> > doc;
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void joint(int a,int b){
	a = p[a];
	b = p[b];
	if (a == b) return;
	p[a] = b;
}
void dfs(int ix){
	pre[ix] = ++cnt;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i]);
	post[ix] = ++cnt;
}
bool inPath(int a,int b,int c){
	return pre[a] <= pre[c] && pre[c] <= pre[b] && post[c] >= post[b] && post[a] >= post[c];
}
int main(){
	int n, m;
	int t, x, y, i;
	scanf("%d%d",&n,&m);
	for (i = 1; i <= n; i++) p[i] = i;
	while(m--){
		scanf("%d",&t);
		switch (t){
		case 1:
			scanf("%d%d",&x,&y);
			edge[y].push_back(x);
			joint(x, y);
			break;
		case 2:
			scanf("%d", &x);
			doc.push_back(make_pair(find(x),x));
			break;
		case 3:
			scanf("%d%d", &x, &i);
			q.push_back(make_pair(x,i));
			break;
		}
	}
	for (i = 1; i <= n; i++){
		if (i == p[i]) dfs(i);
	}

	for (i = 0; i < q.size(); i++){
		printf("%s\n", inPath(doc[q[i].second - 1].first, doc[q[i].second - 1].second, q[i].first)? "YES":"NO");
	}
	return 0;
}