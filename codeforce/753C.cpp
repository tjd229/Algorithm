//implementation
//ref : https://codeforces.com/blog/entry/49635
#include <stdio.h>
#include <memory.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
int in[10000];
vector<int> sieve(int n, vector<int> &v) {
	int b, c;
	vector<int> candi;
	bool use[10] = { 0 };
	int d[4] = { 0 };
	printf("%04d\n", n); fflush(stdout);
	scanf("%d%d", &b, &c);
	for (int i = 0; i < 4; ++i, n /= 10) {
		d[i] = n % 10;
		use[d[i]] = 1;
	}
	for (auto i : v) {
		int bulls, cows;
		int n = i;
		bulls = cows = 0;
		for (int j = 0; j < 4; ++j, n /= 10) {
			int id = n % 10;
			cows += use[id];
			bulls += (id == d[j]);
		}
		cows -= bulls;
		if (b == bulls && cows == c) candi.push_back(i);
		else in[i] = 0;
	}

	return candi;
}
int guess(vector<int> &candi) {
	int g = -1;
	int mn = 1e5;
	int cnt[5][5];
	//for (int n = 0; n < 10000; ++n) {
	for(auto n:candi){
		bool use[10] = { 0 };
		int d[4] = { 0 };
		int mx = -1;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0, j = n; i < 4; ++i, j /= 10) {
			d[i] = j % 10;
			use[d[i]] = 1;
		}
		for (auto i : candi) {
			int bulls, cows;
			int c = i;
			bulls = cows = 0;
			for (int j = 0; j < 4; ++j, c /= 10) {
				int id = c % 10;
				cows += use[id];
				bulls += (id == d[j]);
			}
			cows -= bulls;
			++cnt[bulls][cows];
			if (mx < cnt[bulls][cows]) mx = cnt[bulls][cows];
		}
		if (mx < mn) mn = mx, g = n;
		else if (mx == mn) {
			if (in[n]) g = n;
		}
	}
	return g;
}
int main() {
	int i, j;
	vector<int> candi;
	for (i = 0; i < 10000; ++i) {
		int stat = 0;
		int n = i;
		for (j = 0; j < 4 && stat >= 0; ++j, n /= 10) {
			int d = n % 10;
			if (stat &(1 << d)) stat = -1;
			else stat += (1 << d);
		}
		if (stat >= 0) candi.push_back(i), in[i] = 1;
	}
	//candi = sieve(11, candi);
	candi = sieve(1234, candi);
	//printf("%d\n", candi.size());
	while (candi.size() > 1) {
		int n = guess(candi);
		candi = sieve(n, candi);
	}
	printf("%04d\n", candi[0]); fflush(stdout);


	return 0;
}
