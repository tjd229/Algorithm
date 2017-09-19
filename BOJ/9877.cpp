//category : graph, djs, pbs

#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
int ela[500*500];
int mid[500 * 500*2], l[2*500 * 500], r[2*500 * 500];
int p[500 * 500];
int family[500 * 500];
vector<int> v[500*500*2];
vector<int> sp;
vector<pair<int, pair<int, int> > >edge;
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void join(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	family[a] += family[b];
}
void add_edge(int u, int v){
	int d = ela[u] - ela[v];
	if (d < 0) d = -d;
	edge.push_back(make_pair(d,make_pair(u,v)));
}
int main(){
	int i, j;
	int M, N, T;
	int MN;
	int s;
	bool still=false;
	long long ans = 0;
	scanf("%d%d%d",&M,&N,&T);
	MN = N*M;
	for (i = 0; i < MN; i++) scanf("%d", ela + i);
	for (i = 0; i < MN; i++){
		if (i%N != N - 1)
			add_edge(i, i + 1);
		if (i + N < MN)
			add_edge(i, i + N);
	}
	for (i = 0; i < MN; i++){
		scanf("%d", &s);
		if (s != 0){
			sp.push_back(i);
			l[i] = 0;
			r[i] = edge.size()-1;
		}
	}
	
	sort(edge.begin(), edge.end());
	while (true){
		still = false;
		for (i = 0; i < MN; i++){
			p[i] = i;
			family[i] = 1;
		}
		for (i = 0; i < sp.size(); i++){
			if (l[sp[i]] <= r[sp[i]]){
				mid[sp[i]] = (l[sp[i]] + r[sp[i]]) >> 1;
				v[mid[sp[i]]].push_back(sp[i]);
				still = true;
			}
		}
		if (!still) break;
		for (i = 0; i < edge.size(); i++){
			join(edge[i].second.first, edge[i].second.second);
			for (j = 0; j < v[i].size(); j++){
				s = v[i][j];
				if (family[find(s)] >= T) r[s] = mid[s] - 1;
				else l[s] = mid[s] + 1;
			}
			v[i].clear();
		}

	}
	for (i = 0; i < sp.size(); i++){
		s = sp[i];
		ans += edge[r[s]+1].first;
	}
	printf("%lld",ans);

}