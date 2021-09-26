//MITM
#include <stdio.h>
#include <vector>
#include <numeric>
#include <queue>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
const int mod = 998244353;
int k, A, h;
ll Ap[100];
int p[33];
int place[16] = {1,2,3,3,5,5,5,5,9,9,9,9,9,9,9,9};
int place2[16] = { 0,3,5,5,9,9,9,9, 17,17,17,17,17,17,17,17 };
void play(int stat,vector<int> &team, vector<int> &order) {
	order.clear(); order.resize(team.size());
	queue<int> q;
	for (auto x : team) q.push(x);
	while (q.size()>1) {
		int t1 = q.front(); q.pop();
		int t2 = q.front(); q.pop();
		if (stat & 1) {
			t1 ^= t2 ^= t1 ^= t2;
		}
		q.push(t1);
		order.push_back(t2);
		stat >>= 1;
	}
	order.push_back(q.front());
	reverse(order.begin(), order.end());
}
int main() {
	int i; scanf("%d%d%d", &k, &A, &h);
	Ap[0] = 1; Ap[1] = A;
	for (i = 2; i < 20; ++i) Ap[i] = Ap[i - 1] * A%mod;
	if (k <= 4) {
		int num_team = 1 << k;
		int b = 1 << (num_team - 1);
		vector<int> t(num_team),order;
		iota(t.begin(), t.end(), 1);
		for (int stat = 0; stat < b; ++stat) {
			play(stat,t, order);
			ll val = 0;
			for (i = 0; i < order.size(); ++i) {
				val = (val + order[i] * Ap[place[i]])%mod;
				p[order[i]] = place[i];
			}
			if (val == h) {
				for (i = 1; i <= num_team; ++i) printf("%d ",p[i]);
				return 0;
			}
		}
	}
	else {
		int num_team = 1 << k;
		int batch = 1 << 4;
		int b = 1 << (batch - 1);
		vector<int> t0(batch),t1(batch), order;
		iota(t0.begin(), t0.end(), 1);
		map<int, int> W, L;
		for (int stat = 0; stat < b; ++stat) {
			play(stat, t0, order);
			ll val = 0;
			for (i = 1; i < order.size(); ++i) {
				val = (val + order[i] * Ap[place2[i]]) % mod;
			}
			ll case0 = val + order[0] * Ap[1];
			ll case1 = val + order[0] * Ap[2];
			W[case0 % mod] = stat+1;
			L[case1 % mod] = stat+1;
		}
		iota(t1.begin(), t1.end(), 17);
		for (int stat = 0; stat < b; ++stat) {
			play(stat, t1, order);
			ll val = 0;
			for (i = 1; i < order.size(); ++i) {
				val = (val + order[i] * Ap[place2[i]]) % mod;
				p[order[i]] = place2[i];
			}
			ll case0 = val + order[0] * Ap[2]; case0 %= mod;
			ll case1 = val + order[0] * Ap[1]; case1 %= mod;
			ll dst = (h+mod - case0)%mod;
			int prev = -1, winner=-1;
			if (W[dst] != 0) {
				prev = W[dst] - 1;
				p[order[0]] = 2;
			}
			dst= (h + mod - case1) % mod;
			if (L[dst] != 0) {
				prev = L[dst] - 1;
				p[order[0]] = 1;
				winner = order[0];
			}
			if (prev != -1) {
				play(prev, t0, order);
				for (i = 1; i < order.size(); ++i) {
					p[order[i]] = place2[i];
				}
				if (winner != -1) p[order[0]] = 2;
				else p[order[0]] = 1;
				for (i = 1; i <= num_team; ++i) printf("%d ", p[i]);
				return 0;
			}

		}
	}
	printf("-1");

	return 0;
}