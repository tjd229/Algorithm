//line sweeping
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
int h[100001], m[100001];
int in[100001];
int N, M, H, K;
vector<int> black_list(int t,int half) {
	
	vector<int> v;	
	if (K == 1) return v;
	for (int i = 1; i <= N; ++i) {
		int s = (m[i]+1) % half, e = (m[i] + K - 1) % half;
		if (s <= e) {
			if (s <= t && t <= e) v.push_back(i);
		}
		else {
			if (e >= t || t >= s) v.push_back(i);
		}
	}
	return v;
}
int main() {
	int i, t;
	for (scanf("%d%d%d%d", &N, &H, &M, &K), i = 1; i <= N; ++i) scanf("%d%d",h+i,m+i);
	int half = M >> 1;
	vector<pii > evt;
	for (i = 1; i <= N; ++i) {
		int t = (m[i]) % half;		
		evt.push_back({t,-i });//in
		evt.push_back({t+half,-i});
		t = (m[i] + K-1) % half;
		evt.push_back({ t,i });//out
		evt.push_back({ t+half,i });
	}
	sort(evt.begin(), evt.end());
	int stk = 0,mn=1e9;
	int it = 0;
	while (it < evt.size() && evt[it].first<K+half) {
		int cur = evt[it].first;
		//printf("%d\n",cur);
		if (cur>=K &&mn > stk) {
			t = cur;
			mn = stk;
		}
		while (it < evt.size() && evt[it].first == cur) {
			if (evt[it].second < 0) {
				++stk;
				in[-evt[it].second] = 1;
			}
			else if(in[evt[it].second]){
				in[evt[it].second] = 0;
				--stk;
			}
			++it;
		}
		//printf("stk:%d\n",stk);
	}
	//t-half
	if (t >= half) t -= half;
	vector<int> ans = black_list(t, half);
	printf("%d %d\n",mn,t);
	for (auto x : ans) printf("%d ",x);
	return 0;
}