//category : graph

#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> a[10001];
bool check[10001];
void initCheck(){
	for (int i = 0; i < 10001; i++)
		check[i] = false;
}
void dfs(int x){
	if (check[x] == true) return;
	printf("%d ",x);
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++)
		dfs(a[x][i]);
}
void bfs(int s){
	queue<int> q;
	int now;
	int k;
	int next;

	q.push(s);
	check[s] = true;
	while (!q.empty()){
		now = q.front();
		q.pop();
		printf("%d ",now);
		for (k = 0; k < a[now].size(); k++){
			next = a[now][k];
			if (check[next] == false){
				check[next] = true;
				q.push(next);
			}
		}
	}
	
}
int main(){

	int n, m, s;
	int u,v;
	int i;
	scanf("%d %d %d",&n,&m,&s);
	for (i = 0; i < m; i++){
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);

	}
	for (i = 0; i < n; i++){
		sort(a[i].begin(), a[i].begin()+a[i].size());		
	}
	initCheck();
	dfs(s);
	printf("\n");
	initCheck();
	bfs(s);

	return 0;
}