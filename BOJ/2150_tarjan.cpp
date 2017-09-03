//category : graph, SCC



#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAXV 10001
#define MIN(A,B) (A)>(B)? (B):(A)
int num[10001], low[10001];
bool c[10001];
vector<int> edges[10001];
vector<pair<int, int> >books;
stack<int> s;
int dfs(int ix, int &cnt){
	if (num[ix] > 0) return low[ix];
	int i;
	num[ix] = cnt++;
	low[ix] = num[ix];
	c[ix] = true;
	s.push(ix);
	for (i = 0; i < edges[ix].size(); i++){
		if (num[edges[ix][i]]==0) low[ix] = MIN(low[ix], dfs(edges[ix][i], cnt));
		else if (c[edges[ix][i]]) low[ix] = MIN(low[ix], num[edges[ix][i]]);
		
	}
	
	if (num[ix] == low[ix]){
		int min = MAXV;
		num[0]++;
		edges[0].clear();
		while (!s.empty()){
			edges[0].push_back(s.top());
			if (s.top()<min) min = s.top();
			c[s.top()] = false;
			s.pop();
			if (edges[0][edges[0].size() - 1] == ix) break;
		}
		books.push_back(make_pair(min, MAXV));
		for (i = 0; i < edges[0].size(); i++) books.push_back(make_pair(min, edges[0][i]));
		
	}
	return low[ix];
}
int main(){
	int V, E;
	int A, B;
	int i;
	
	scanf("%d%d", &V, &E);

	for (i = 0; i < E; i++){
		scanf("%d%d", &A, &B);
		edges[A].push_back(B);
	}
	for (i = 1; i <= V; i++) sort(edges[i].begin(), edges[i].end());
	A = 1;
	for (i = 1; i <= V; i++) dfs(i, A);
	sort(books.begin(), books.end());
	printf("%d\n",num[0]);
	for (i = 0; i < books.size(); i++){
		if (books[i].second == MAXV) printf("-1\n");
		else printf("%d ",  books[i].second);
	}
	

	return 0;
}