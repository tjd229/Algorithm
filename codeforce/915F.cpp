//category : graph, djs

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
int sz[1000001];
int p[1000001];
int a[1000001],v[1000001];
vector<int> edge[1000001];
int find(int a){
	if(p[a]!=a) p[a] = find(p[a]);
	return p[a];
}
ll join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	ll res = (ll)sz[a] * sz[b];
	sz[a] += sz[b];
	p[b] = a;
	return res;
}
int main(){
	int i,j;
	int n;
	int x, y;
	ll mx = 0;
	ll mn = 0;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		v[i] = i;
		p[i] = i;
		sz[i] = 1;
		scanf("%d", a+i);
		
	}
	for (i = 1; i < n; i++){
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	sort(v + 1, v + 1 + n, [](const int a1, const int a2){
		return a[a1] < a[a2];
	});
	for (i = 1; i <= n; i++){
		x = v[i];
		for (j = 0; j < edge[x].size(); j++){
			y = edge[x][j];
			if (a[x] >= a[y])
				mx += a[x] * join(x, y);
		}		
	}
	for (i = 1; i <= n; i++){		
		p[i] = i;
		sz[i] = 1;
	}
	for (i = n; i > 0; i--){
		x = v[i];
		for (j = 0; j < edge[x].size(); j++){
			y = edge[x][j];
			if (a[x] <= a[y])
				mn += a[x] * join(x, y);
		}
	}
	printf("%I64d",mx-mn);
	return 0;
}
