//bs,string
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int g[1001];
vector<int> head;
char s[1002];
int G;
int last[30];
char dic[30];
char q1(int i) {
	printf("? 1 %d\n", i); fflush(stdout);
	char s; scanf(" %c",&s);
	return s;
}
int q2(int l, int r) {
	printf("? 2 %d %d\n", l,r); fflush(stdout);
	int num; scanf("%d", &num);
	return num;
}
int group(int k) {
	vector<pii > v;
	for (int i = 1; i < G; ++i) {
		v.push_back({last[i],i});
	}
	sort(v.begin(), v.end());
	int s = 0, e = v.size() - 1;
	int g = -1;
	while (s <= e) {
		int m = (s + e) >> 1;
		int d = q2(v[m].first, k);
		int cnt = v.size() - m;
		if (d == cnt) {
			s = m + 1;
			g = v[m].second;
		}
		else e = m - 1;
	}
	if (g == -1) g = G++;
	return g;
}
int main() {
	int i, n; scanf("%d",&n);
	s[n + 1] = '\0';
	if (n <= 26) {
		for (i = 1; i <= n; ++i) s[i] = q1(i);
	}
	else {
		G = 2;
		head = { 1 };
		g[1] = 1; last[1] = 1;
		for (i = 2; i <= n; ++i) {
			if (q2(i - 1, i) > 1) head.push_back(i);
		}
		for (i = 1; i <head.size(); ++i) {
			int k = head[i];
			int _g = group(k);
			last[_g] = k;
			g[k] = _g;			
		}
		for (i = 1; i < G; ++i) dic[i] = q1(last[i]);
		for (i = 1; i <= n; ++i) {
			if (g[i] == 0) s[i] = s[i - 1];
			else s[i] = dic[g[i]];
		}

	}

	printf("! %s", s + 1); fflush(stdout);

	return 0;
}