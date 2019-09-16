//greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int wanna[100001];
int x[100001], y[100001];
int eat[100001];
int out[100001];
vector<int> g[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); int i;
	int n, k; cin >> n >> k;
	vector<pii > v;
	int sad = 0;
	for (i = 1; i <= k; ++i) {//guest num
		cin >> x[i] >> y[i];
		wanna[x[i]]++;
		wanna[y[i]]++;
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
	}
	for (i = 1; i <= n; ++i) {//snk num
		v.push_back({wanna[i],i});
	}
	sort(v.begin(), v.end());
	
	for (auto p : v) {
		int snk = p.second;
		queue<int> q;
		q.push(snk);
		while (q.size()) {
			int top = q.front();
			q.pop();
			for (auto gst : g[top]) {
				if (out[gst]) continue;
				out[gst] = 1;
				int w1 = x[gst];
				int w2 = y[gst];
				if (eat[w1] && eat[w2])++sad;
				if (eat[w1] == 0) q.push(w1);
				if (eat[w2] == 0) q.push(w2);
				eat[w1] = eat[w2] = 1;
			}
		}
	}
	cout << sad;
	return 0;
}