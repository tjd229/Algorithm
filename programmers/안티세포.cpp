//https://programmers.co.kr/learn/courses/30/lessons/86054
//dp
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int d[200011];
const int mod = 1e9 + 7;
map<ll,int> mp[200011];//Y,len
int solve(vector<int> &b) {
	int n = b.size();
	d[0] = 1;
	for (int i = 1; i < n; ++i) {
		d[i] = d[i - 1];
		ll X = b[i];
		int len = 1;
		int l;
		while (1) {
			l = i - len;
			if (l <= 0) break;
			if (mp[l][X] == 0) break;
			len += mp[l][X];
			int cnt = d[i-len];
			d[i] += cnt;
			d[i] %= mod;
			X += X;
			mp[i][X] = len;
		}
		mp[i][b[i]] = 1;
		//printf("%d:%d\n",i,d[i]);
	}
	for (int i = 1; i < n; ++i) mp[i].clear();
	return d[n-1];
}
vector<int> solution(vector<int> a, vector<int> s) {
	vector<int> answer;
	vector<int> b; int i = 0;
	for (auto len : s) {
		b = { -1 };
		for (int j = 0; j < len; ++j) {
			b.push_back(a[i+j]);
		}
		answer.push_back(solve(b));
		i += len;
	}
	return answer;
}