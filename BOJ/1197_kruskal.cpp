//category : graph, MST, djs

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > uv;
vector<pair<int, int> > edges;

int p[10001];
int find(int ix){
	if (ix != p[ix]) p[ix] = find(p[ix]);
	return p[ix];	
}
bool joint(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return false;
	
	p[b] = a;
	return true;
}
int main()
{
	int V, E;
	int A, B, C;
	int i;

	scanf("%d%d",&V,&E);
	for (i = 0; i < E; i++){
		scanf("%d%d%d",&A,&B,&C);
		uv.push_back(make_pair(A,B));
		edges.push_back(make_pair(C,i));
		p[A] = A;
		p[B] = B;
	}
	sort(edges.begin(), edges.end());
	B = C = 0;
	int cost = 0;
	do{
		A = edges[B].second;
		if (joint(uv[A].first, uv[A].second)){
			cost += edges[B].first;
			C++;
		}
		B++;
	} while (C!=V-1);
	printf("%d",cost);
	return 0;
}