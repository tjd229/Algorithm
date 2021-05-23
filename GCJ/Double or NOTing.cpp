//https://codingcompetitions.withgoogle.com/codejam/round/00000000004362d7/00000000007c1139
//greedy
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
string S, E;
void f(string &s,vector<pii > &v) {
	queue<char> q;
	for (auto c : s) q.push(c);
	while (q.size()) {
		int cnt = 0;
		char piv = q.front();
		while (q.size() && q.front() == piv) {
			++cnt;
			q.pop();
		}
		v.push_back({cnt,piv-'0'});
	}
}
int sim0(int pop, vector<pii > &S, vector<pii > &E) {
	int cnt = pop;
	int tail = -1;
	for (int i = 0; i + pop < S.size(); ++i) {
		if (i >= E.size()) return -1;
		tail = i;
		if (i + pop == S.size() - 1) {
			if (S[i + pop].first > E[i].first) return -1;
			cnt += E[i].first - S[i + pop].first;
		}
		else {
			if (E[i].first != S[i + pop].first) return -1;
		}
	}
	for (++tail; tail < E.size() && pop>0; ++tail) {
		cnt += E[tail].first;
		--pop;
	}
	if (tail < E.size()) return -1;
	return cnt;
}
int sim1(int pop, vector<pii > &S, vector<pii > &E) {
	int cnt = pop;
	int tail = -1;
	int b = 1;
	for (int i = 0; i + pop < S.size(); ++i) {
		if (i >= E.size()) return -1;
		tail = i;
		if (i + pop == S.size() - 1) {
			if (S[i + pop].first > E[i].first) return -1;
			else if (S[i + pop].first < E[i].first) {
				if (pop > 0)
					cnt += E[i].first - S[i + pop].first;
				else return -1;
				b = -1;
			}

			break;
		}
		else {
			if (E[i].first != S[i + pop].first) return -1;
		}
	}
	pop += b;
	for (++tail; tail < E.size() && pop>0; ++tail) {
		cnt += E[tail].first;
		--pop;
	}
	if (tail < E.size()) return -1;
	return cnt;
}
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x,y,T;
	cin >> T;
	for (x = 1; x <= T; ++x) {
		cin >> S >> E;
		vector<pii > s, e; y = -1;
		if (S == E) y = 0;
		else if (S == "0" && E == "1") y = 1;
		else {			
			int zero_st = 0;
			if (S == "0") zero_st = 1;
			f(S, s); f(E, e);
			if (E == "0") y = s.size();
			else {
				for (int st = 0; st <= s.size(); ++st) {
					int cnt=-1;
					if (s.size() & 1) cnt = sim1(st, s, e);
					else cnt = sim0(st, s, e);
					//printf("%d,%d\n",st,cnt);
					if (cnt >= 0) {
						if (y<0 || y>cnt) y = cnt;
					}
				}
				if(y!=-1)
					y += zero_st;
			}
		}

		if(y==-1)
			cout << "Case #" << x << ": IMPOSSIBLE\n";
		else
			cout << "Case #" << x << ": "<<y<<"\n";
	}

	return 0;
}