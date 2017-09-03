//category : dp, knapsack, djs

#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX(a,b) a<b? b:a
using namespace std;
int w[1001];
int b[1001];
int p[1001];
vector<pair<int, int> > group[1001];

int find(int ix){
	if (ix != p[ix]) p[ix] = find(p[ix]);
	return p[ix];
}
void joint(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] = b;
}
int main(){
	int i, j, k;
	int n, m, cap;
	int x, y;
	int g;
	scanf("%d%d%d", &n, &m, &cap);
	for (i = 1; i <= n; i++){
		scanf("%d", w + i);
		p[i] = i;
	}
	for (i = 1; i <= n; i++){
		scanf("%d", b + i);
	}
	for (i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		joint(x, y);
	}
	for (i = 1; i <= n; i++){
		group[find(i)].push_back(make_pair(w[i], b[i]));
	}
	for (i = g = 1; i <= n; i++){
		if (group[i].size()>0)
			group[g++] = group[i];
	}
	for (i = 1; i < g; i++){
		if (group[i].size()>1){
			x = y = 0;
			for (j = 0; j < group[i].size(); j++){
				x += group[i][j].first;
				y += group[i][j].second;
			}
			group[i].push_back(make_pair(x, y));
		}
	}


	vector<int > last(cap + 1);
	vector<int > curr(cap + 1);

	for (i = 1; i < g; i++){

		for (j = 0; j <= cap; j++){
			for (k = 0; k < group[i].size(); k++){
				if (j + group[i][k].first <= cap)
					curr[j + group[i][k].first] = MAX(curr[j + group[i][k].first], last[j] + group[i][k].second);
			}
		}
		
		last = curr;

	}
	printf("%d", curr[cap]);
	return 0;
}