//category : string, hashing

#include <iostream>
#include <string>
#include <queue>

#include <map>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = mod1 + 2;
const int base = 256;
int a[100000];
int use[100000];
ll h1[100000],h2[100000];
ll inv1[100000], inv2[100000];
deque<int> dq[100000];
int cnt;
ll roll(ll h, int val, int mod){
	h = (h*base+val)%mod;
	return h;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k, n;
	string s;
	ll tot = 0;
	ll ans = 0;
	priority_queue<pii > q;
	map<pii, int> m;
	int i,j;
	cin >> k >> n;
	for (i = 0; i < k; i++){
		cin >> s >> a[i];
		for (j = 0; j < n; j++){
			h1[i] = roll(h1[i], s[j], mod1);
			h2[i] = roll(h2[i], s[j], mod2);
			inv1[i] = roll(inv1[i], s[n - 1 - j], mod1);
			inv2[i] = roll(inv2[i], s[n - 1 - j], mod2);
		}		
		q.push({a[i],i});
	}
	while (!q.empty()){
		pii top = q.top();
		q.pop();
		pii p = { h1[top.second], h2[top.second] };
		if (m.find(p) == m.end()||dq[m[p]].empty()){
			p = { inv1[top.second], inv2[top.second] };
			if (m.find(p) == m.end()){
				m[p] = cnt++;
			}
			i = m[p];
			dq[i].push_back(top.second);
		}
		else{
			i = m[p];			
			if (dq[i].size() && a[dq[i].front()] + top.first > 0){
				tot += a[dq[i].front()] + top.first;
				use[dq[i].front()] = use[top.second] = a[dq[i].front()] + top.first;
				dq[i].pop_front();
			}
		}
	}
	ans = tot;
	for (i = 0; i < k; i++){
		if (h1[i] == inv1[i] && h2[i] == inv2[i]){
			if (use[i]){
				if (ans < tot - use[i] + a[i]) ans = tot - use[i] + a[i];
			}
			else if (ans < tot + a[i]) ans = tot + a[i];
		}
	}
	cout << ans;
	return 0;
}
