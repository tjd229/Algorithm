//math
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
int k;
int _xor(int a, int b) {
	vector<int> A, B, C;
	while (a) {
		A.push_back(a%k);
		a /= k;
	}
	while (b) {
		B.push_back(b%k);
		b /= k;
	}
	int mn = A.size() < B.size() ? A.size() : B.size();
	for (int i = 0; i < mn; ++i) C.push_back((A[i] + B[i]) % k);
	for (int i = mn; i < A.size(); ++i) C.push_back(A[i]);
	for (int i = mn; i < B.size(); ++i) C.push_back(B[i]);
	int res = 0;
	reverse(C.begin(), C.end());
	for (auto c : C) res = res * k + c;
	return res;
}
 
int _c(int a) {
	vector<int> A;
	while (a) {
		A.push_back(a%k);
		a /= k;
	}
	int res = 0;
	reverse(A.begin(), A.end());
	for (auto a : A) {
		int b = k - a;
		if (b == k) b = 0;
		res = res * k + b;
	}
	return res;
}
//int pwd=3;
//int ask(int y) {
//	printf("ask:%d\n",y);
//	if (y == pwd) {
//		printf("1\n");
//		return 1;
//	}
//	else {
//		//pwd ^= y;
//		//pwd->y
//		vector<int> P, Y,C;
//		int p = pwd; int _y = y;
//		while (p) {
//			P.push_back(p%k);
//			p /= k;
//		}
//		while (_y) {
//			Y.push_back(_y%k);
//			_y /= k;
//		}
//		int mn = P.size() < Y.size() ? P.size() : Y.size();
//		for (int i = 0; i < mn; ++i) {
//			int d = Y[i] - P[i];
//			if (d < 0) d += k;
//			C.push_back(d);
//		}
//		for (int i = mn; i < P.size(); ++i) C.push_back(k-P[i]);
//		for (int i = mn; i < Y.size(); ++i) C.push_back(Y[i]);
//		int res = 0;
//		reverse(C.begin(), C.end());
//		for (auto c : C) {
//			if (c == k) c = 0;
//			printf("%d",c);
//			res = res * k + c;
//		}
//		printf("--\n");
//		pwd = res;
//		printf("0:%d\n\n",pwd);
//		return 0;
//	}
//}
 
int ask(int y) {
	cout << y << endl;
	int r; cin >> r;
	return r;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n >> k;
		if (ask(0));
		else {
			int last = 0;
			//printf("last:%d\n", last);
			int tog = 1;
			for (int i = 1; i < n; ++i) {
				int inp = i;
				if (tog) inp = _c(inp);
				int val = _xor(last, inp);
				if (ask(val)) break;
				//last = _c(inp);//cmp
				last = inp;
				tog = 1 - tog;
				//printf("last:%d\n",last);
			}
		}
	}
 
	return 0;
}