//ft, string
//https://programmers.co.kr/learn/courses/30/lessons/68938


#include <string>
#include <vector>
using namespace std;
const int LEAF = 1 << 19;
long long ft_l[26][LEAF], ft_R[26][LEAF], ft_cnt[26][LEAF];
int L[300000],R[300000];
vector<int> pos[26],book[300000];
void upd(int ix, int val, long long *ft) {
	for (; ix < LEAF; ix += (ix&-ix)) ft[ix] += val;
}
long long sum(int ix, long long *ft) {
	if (ix < 0) return 0;
	long long res = 0;
	for (; ix >0; ix -= (ix&-ix)) res+=ft[ix];
	return res;
}
long long sum(int s, int e, long long *ft) { return sum(e, ft) - sum(s - 1, ft); }
long long solution(string s) {
	long long answer = 0;
	long long stk[26] = { 0 };
	int cnt[26] = { 0 };
	int i,j;
	int n = s.size();
	for (i = 0; i < 26; ++i) pos[i] = {-1};
	for (i = 0; i < n; ++i) {
		for (L[i] = -1, j = 0; j < 26; ++j) {
			if (s[i] - 'a' == j) continue;
			int bk = pos[j].back();
			if (L[i] < bk) L[i] = bk;
		}
		pos[s[i] - 'a'].push_back(i);
	}
	for (i = 0; i < 26; ++i) pos[i] = { n };
	for (i = n - 1; i >= 0; --i) {
		for (R[i] = n, j = 0; j < 26; ++j) {
			if (s[i] - 'a' == j) continue;
			int fr = pos[j].back();
			if (R[i] > fr) R[i] = fr;
		}
		if (R[i] < n) book[R[i]].push_back(i);
		pos[s[i] - 'a'].push_back(i);
	}
	for (i = 0; i < n; ++i) {
		int c;
		for (auto x : book[i]) {
			c = s[x] - 'a';
			upd(R[x] - x, x, ft_l[c]);
			upd(R[x] - x, R[x], ft_R[c]);
			upd(R[x] - x, 1, ft_cnt[c]);
		}
		c = s[i] - 'a';
		long long lsum = 0;
		long long count = 0;
		for (j = 0; j < 26; ++j) {
			if (c == j) continue;
			lsum += stk[j];
			count += cnt[j];
		}
		answer += i * count - lsum;
		if (L[i] >= 0) {
			int piv = i - L[i];
			count = sum( 0, piv-1,ft_cnt[c]);
			lsum = sum(0,piv-1, ft_R[c]);
			answer += i * count - lsum;
			count = sum(piv, LEAF-1,  ft_cnt[c]);
			lsum = sum(piv, LEAF-1, ft_l[c]);
			answer += L[i] * count - lsum;
		}
		++cnt[c];
		stk[c] += i;
	}

	return answer;
}