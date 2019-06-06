//implementation
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int p[300001];
int pos[300001];
vector<pii > ans;
int _n;
void myswap(int a, int b) {
	//printf("swap:%d,%d\n", a, b);
	if (a == b) return;
	p[a] ^= p[b] ^= p[a] ^= p[b];
	ans.push_back({ a,b });
	pos[p[a]] = a;
	pos[p[b]] = b;
	//printf("pos[%d]=%d\n", p[a], a);

	//printf("pos[%d]=%d\n", p[b], b);
	//for (int i = 1; i <= _n; ++i) cout << p[i] << " ";
		//cout << endl;
	int d = a - b;
	if (d < 0) d = -d;
	if (d + d < _n) printf("!%d,%d\n", a, b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i; int n; cin >> n;
	int half = n >> 1;
	_n = n;
	for (i = 1; i <= n; ++i) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (i = 1; i <= n; ++i) {
		if (pos[i] == i) continue;
		int d = pos[i] - i;
		if (d < 0) d = -d;
		if (d >= half) myswap(pos[i], i);
		else {
			int a = pos[i]; int b = i;
			if (a <= half && b <= half) {
				a < b ? b += half : a += half;
			}
			else if (a > half && b > half) {
				a < b ? a -= half : b -= half;
			}
			else {
				a = pos[i] > half ? pos[i] - half : pos[i] + half;
				b = i > half ? i - half : i + half;
				
			}
			int ori = pos[i];
			myswap(pos[i], a);
			myswap(a, b);
			if (b != i) {
				myswap(i, b);
				myswap(a, b);
			}
			myswap(ori, a);
			
		}
	}
	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
	//for (i = 1; i <= n; ++i) cout << p[i] << " ";
	return 0;
}