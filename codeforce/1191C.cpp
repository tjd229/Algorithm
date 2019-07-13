//dp
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
ll p[100001];
int d[100001];
int cnt[100001];
ll last[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m; ll n, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) cin >> p[i];
	ll s = 1;
	s += k * ((p[1] - s) / k); int i = 1;
	while (i <= m && s + k - 1 >= p[i]) {
		d[i] = 1;
		cnt[1]++;
		++i;
	}
	int t = 2;
	last[1] = s + k - 1;
	//for (int i = 1; i <= m; ++i) cout << d[i] << endl;
	while(i<=m){
		if (last[t - 1] + cnt[t - 1] >= p[i]) {
			d[i] = t;
			cnt[t]++;
			++i;
		}
		else if(cnt[t]){
			last[t] = last[t - 1] + cnt[t - 1];
			++t;
		}
		else {
			s = last[t - 1] + cnt[t - 1]+1;
			s += k * ((p[i] - s) / k);
			while (i <= m && s + k - 1 >= p[i]) {
				d[i] = t;
				cnt[t]++;
				++i;
			}
			last[t] = s + k - 1;
			++t;
		}
	}
	cout << d[m];
	//for (int i = 1; i <= m; ++i) cout << d[i] << endl;
	return 0;
}