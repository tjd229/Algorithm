//bs
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
int a[100002];
int b[100002];
int call = 0;
void local(int i) {
	printf("%d,%d,%d\n",b[i-1],b[i],b[i+1]);
	printf("%d\n",call);
}
void bd(int n) {
	int i;
	for (i = 1; i <= n; ++i) {
		b[i] = i;
	}
	b[0] = b[n + 1] = 1e9;
	int coin = n;
	int x= rand()*rand() % n;
	int y = 1;
	b[x] ^= b[y] ^= b[x] ^= b[y];
	x = rand()*rand() % n;
	y = n;
	b[x] ^= b[y] ^= b[x] ^= b[y];
	while (coin--) {
		int x = rand()*rand() % n;
		int y = rand()*rand() % n;
		if (y == x) continue;
		++x; ++y;
		b[x] ^= b[y] ^= b[x] ^= b[y];
	}
	printf("done\n");
	printf("%d,%d\n",b[1],b[n]);
}
int qry(int i) {
	//return a[i];
	if (a[i] == 0) {
		//++call;
		//a[i] = b[i];
		cout << "? " << i << endl;
		cin >> a[i];
	}
	return a[i];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	//bd(n);
	a[0] = a[n + 1] = 1e9;
	if (n <= 100 ) {
		for (i = 1; i <= n; ++i) {
			int k = qry(i);
			if (k == 1) {
				cout << "! " << i << endl;
				return 0;
			}
		}
	}
	else {
		qry(1); qry(2);
		qry(n); qry(n-1);
		if (a[1] < a[2]) {
			cout << "! " << 1 << endl;
			return 0;
		}
		if (a[n] < a[n - 1]) {
			cout << "! " << n << endl;
			return 0;
		}
		int st = 1, ed = n;
		while (1) {
			qry(st); qry(st+1); qry(st-1);
			if (a[st] < a[st + 1] && a[st] < a[st - 1]) {
				cout << "! " << st << endl;
				//local(m);
				return 0;
			}
			qry(ed); qry(ed + 1); qry(ed - 1);
			if (a[ed] < a[ed + 1] && a[ed] < a[ed - 1]) {
				cout << "! " << ed << endl;
				//local(m);
				return 0;
			}
			int m = (st + ed) >> 1;
			int val = qry(m); qry(m - 1); qry(m + 1);
			if (a[m] < a[m + 1] && a[m] < a[m - 1]) {
				cout << "! " << m << endl;
				//local(m);
				return 0;
			}
			if(a[m+1]>a[m-1]){
				ed = m - 1;
			}
			else st = m + 1;
		}
	}
 
 
	return 0;
}