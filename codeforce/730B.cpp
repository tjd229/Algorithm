//math
#include <stdio.h>
#include <vector>
using namespace std;
char cmp(int i, int j) {
	printf("? %d %d\n", i, j); fflush(stdout);
	char resp; scanf(" %c",&resp);
	return resp;
}
int find(vector<int> &v,char symbol) {
	int n = v.size();
	if (n == 1) return v[0];
	vector<int> new_v;
	for (int i = 0; i+1 < n; i+=2) {
		char resp = cmp(v[i], v[i + 1]);
		if (resp == symbol) new_v.push_back(v[i]);
		else new_v.push_back(v[i+1]);
	}
	if (n & 1) new_v.push_back(v.back());
	return find(new_v, symbol);
	
}
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int n; scanf("%d",&n);
		if (n == 1) {
			printf("! 1 1\n"); fflush(stdout);
		}
		else if (n == 2) {
			int i = 1, j = 2;
			char resp=cmp(1, 2);
			if (resp == '>') i = 2, j = 1;
			printf("! %d %d\n", i, j); fflush(stdout);
		}
		else {
			vector<int> mx, mn;
			for (int i = 1; i+1 <= n; i += 2) {
				char resp = cmp(i, i + 1);
				if (resp == '>') {
					mx.push_back(i);
					mn.push_back(1 + i);
				}
				else {
					mx.push_back(1 + i);
					mn.push_back(i);
				}
			}
			if (n & 1) {
				mx.push_back(n);
				mn.push_back(n);
			}
			int i = find(mn, '<'), j = find(mx, '>');
			printf("! %d %d\n", i, j); fflush(stdout);
		}
	}
	
	return 0;
}