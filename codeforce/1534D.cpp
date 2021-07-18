//graph
#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
int n;
int d[2001];
void ask(int r) {
	printf("? %d\n", r); fflush(stdout);
	for (int i = 1; i <= n; ++i)scanf("%d",d+i);
}
int main() {
	int i; scanf("%d", &n);
	vector<pii > ans;
	vector<int> o,e;
	ask(1);
	for (i = 1; i <= n; ++i) {
		if(d[i]==1) ans.push_back({ 1, i });
		if (d[i] & 1) o.push_back(i);
		else if (d[i] > 0) e.push_back(i);
	}
	vector<int> r = o.size() < e.size() ? o : e;
	for (auto x : r) {
		ask(x);
		for (i = 2; i <= n; ++i) {
			if (i == x) continue;
			if (d[i] == 1) ans.push_back({ x,i });
		}
	}
	printf("!\n");
	for (auto p : ans) 
		printf("%d %d\n",p.first,p.second);
	fflush(stdout);

	return 0;
}