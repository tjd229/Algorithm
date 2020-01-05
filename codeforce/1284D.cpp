//line sweeping
#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
#define pii pair<int ,int>
using namespace std;
int sa[100001], ea[100001];
int sb[100001], eb[100001];
bool happy(vector<pii > &evt,int *s,int *e) {//time,|ix|(ix<0 open else close)
	int l = 0, r = 2e9;
	multiset<int> S,E;
	for (int i = 0; i < evt.size();) {
		int t = evt[i].first;
		int from = i;
		while (i < evt.size() && t == evt[i].first) {
			if (evt[i].second > 0) break;
			int ix = -evt[i].second;
			S.insert(s[ix]); E.insert(e[ix]);	
			++i;
		}
		for (; from < i; ++from) {
			int ix = -evt[from].second;
			auto it = S.lower_bound(s[ix]);	S.erase(it);
			it = E.lower_bound(e[ix]);	E.erase(it);
			if (S.empty())
				l = 0, r = 2e9;
			else {
				it = S.end(); l=*(--it);
				r = *E.begin();
			}
			//printf("chk %d\n",ix);
			if (r<s[ix] || e[ix]<l) return 0;
			S.insert(s[ix]); E.insert(e[ix]);
		}
		while (i < evt.size() && t == evt[i].first) {//close
			int ix = evt[i].second;
			auto it = S.lower_bound(s[ix]);	S.erase(it);
			it = E.lower_bound(e[ix]);	E.erase(it);
			++i;
		}
		
	}
	//printf("happy\n");
	return 1;
}
int main() {
	int i, n;
	vector<pii > A, B;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", sa + i, ea + i, sb + i, eb + i);
		A.push_back({ sa[i],-i }); A.push_back({ea[i],i});
		B.push_back({ sb[i],-i }); B.push_back({eb[i],i});
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if (happy(A, sb, eb) && happy(B, sa, ea))
		printf("YES");
	else printf("NO");
 
	return 0;
}