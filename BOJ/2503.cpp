//greedy
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> guess(int ask,int s,int b,vector<int> &candi) {
	vector<int> res;
	int pick[3] = { 0 };
	int stat = 0;
	int n = ask;
	for (int i = 0; i < 3; ++i,n/=10) {
		int d = n % 10;
		pick[i] = d;
		stat |= (1 << d);
	}
	for (auto c : candi) {
		int strk, ball;
		strk = ball = 0;	
		int n = c;
		for (int i = 0; i < 3; ++i,n/=10) {
			int d = n % 10;
			strk += (d == pick[i]);
			if (stat&(1 << d)) ++ball;
		}
		ball -= strk;
		if (ball==b &&s == strk) res.push_back(c);
	}
	return res;
}
int main() {
	int i;
	int N;
	vector<int> candi;
	for (i = 111; i < 1000; ++i) {
		int stat = 1;
		int n = i;
		for (int j = 0; j < 3 && n>=0; ++j,n/=10) {
			int b = n % 10;
			if (stat & (1 << b)) {
				n = -1;
				break;
			}
			else stat |= (1 << b);
		}
		if (n >= 0) candi.push_back(i);
	}
	for (scanf("%d", &N); N--;) {
		int ask, s, b;
		scanf("%d%d%d",&ask,&s,&b);
		candi = guess(ask, s, b, candi);
	}
	printf("%d",candi.size());
	return 0;
}
