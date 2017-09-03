//category : graph, tp sort, djs

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int table[1000000];
int p[1000000];
int indegree[1000000];
vector<int> edge[1000000];
int n, m;
int nm;
int find(int x){
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
bool joint(int a,int b){
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return false;
	if (pa < pb) p[pb] = pa;
	else p[pa] = pb;
	return true;
}
int to1D(int x, int y){
	return x + y*m;
}
void tp_sort(){
	int i;
	int curr;
	int to;
	queue<int> q;
	for (i = 0; i < nm; i++){
		if (i != find(i)) continue;
		if (indegree[i] == 0) q.push(i), table[i] = 1;
	}
	while (!q.empty()){
		curr = q.front();
		q.pop();
		for (i = 0; i < edge[curr].size(); i++){
			to = edge[curr][i];
			table[to] = table[curr] + 1;
			indegree[to]--;
			if (indegree[to]==0)
				q.push(to);			
		}
	}
}
int main(){
	int i,j;
	int ix;
	int last;
	vector<vector<pair<int, int> > >row,col;
	scanf("%d%d",&n,&m);
	nm = n*m;
	for (i = 0; i < nm; i++){
		scanf("%d", table + i);
		p[i] = i;
	}

	for (i = 0; i < n; i++){
		vector<pair<int, int> > v;
		vector<pair<int, int> > dag;
		for (j = 0; j < m; j++){
			ix = to1D(j, i);
			v.push_back(make_pair(table[ix], ix));
		}
		sort(v.begin(), v.end());
		for (j = 0; j < m; j++){
			if (j > 0 && last == v[j].first)
				joint(v[j - 1].second, v[j].second);
			last = v[j].first;
		}
		for (j = 0; j < m; j++){
			if (j > 0 && last == v[j].first)
				joint(v[j - 1].second, v[j].second);
			else dag.push_back(v[j]);
			last = v[j].first;
		}
		row.push_back(dag);
	}

	for (i = 0; i < m; i++){
		vector<pair<int, int> > v;
		vector<pair<int, int> > dag;
		for (j = 0; j < n; j++){
			ix = to1D(i, j);
			v.push_back(make_pair(table[ix], ix));
		}
		sort(v.begin(), v.end());
		for (j = 0; j < n; j++){
			if (j > 0 && last == v[j].first)
				joint(v[j - 1].second, v[j].second);
			else dag.push_back(v[j]);
			last = v[j].first;
		}
		col.push_back(dag);
	}
	for (i = 0; i < row.size(); i++){
		vector<pair<int, int> > dag = row[i];
		for (j = 1; j < dag.size(); j++){
			last = find(dag[j - 1].second);
			ix = find(dag[j].second);
			edge[last].push_back(ix);
			indegree[ix]++;
		}
	}
	for (i = 0; i < col.size(); i++){
		vector<pair<int, int> > dag = col[i];
		for (j = 1; j < dag.size(); j++){
			last = find(dag[j - 1].second);
			ix = find(dag[j].second);
			edge[last].push_back(ix);
			indegree[ix]++;
		}
	}

	tp_sort();

	for (i = ix = 0; i < n; i++){
		for (j = 0; j < m; j++){
			printf("%d ",table[find(ix++)]);
		}
		printf("\n");
	}

	return 0;
}