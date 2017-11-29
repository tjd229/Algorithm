//category : string, SA, cnt sort, pst, djs

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 18;
int d;
int leaf;
int g[200002];
int lcp[200001];
ll tmp[200001];
int cnt[200001];
int s_ix[200001];
int p[200001];
int low[200001];
int high[200001];
int a_ix[200001];
int nxt[200001];
int root[200001];
int st[19 * 200001], l[19 * 200001], r[19 * 200001];
ll ans[100001];
int stamp[200001];
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
void cnt_sort(int len){
	int i;
	memset(tmp, 0, sizeof(tmp));
	
	for (i = 0; i < len; i++)
		cnt[g[min(len, s_ix[i] + d)]]++;
	for (i = 1; i < len || i <= 'z';i++)
		cnt[i]+=cnt[i - 1];
	for (i = len - 1; i >= 0; i--)
		tmp[--cnt[g[min(len, s_ix[i] + d)]]] = s_ix[i];
	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < len; i++)
		cnt[g[tmp[i]]]++;
	for (i = 1; i < len || i <= 'z'; i++)
		cnt[i] += cnt[i - 1];
	for (i = len - 1; i >= 0; i--)
		s_ix[--cnt[g[tmp[i]]]] = tmp[i];
	memset(cnt, 0, sizeof(cnt));
}
int make_tree(int pre, int s, int e, int pos, int val){
	if (e < pos || pos < s) return pre;
	int ix = ++leaf;
	if (e == pos&&s == pos){
		st[ix] += val;
	}
	else{
		l[ix] = make_tree(l[pre], s, (s + e) >> 1, pos, val);
		r[ix] = make_tree(r[pre], 1+((s + e) >> 1),e, pos, val);
		st[ix] = st[l[ix]] + st[r[ix]];
	}
	return ix;
}
int query(int ix,int s,int e,int low){
	if (e <= low) return 0;
	if (low < s) return st[ix];
	return query(l[ix], s, (s + e) >> 1, low) + query(r[ix], 1+((s + e) >> 1),e, low);
}
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void join(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	
	p[b] = a;
	if (low[a] > low[b]) low[a] = low[b];
	if (high[a] < high[b]) high[a] = high[b];
}
int main(){
	int i, j,m;
	int n, k;
	int left, right;
	ll sum=0;
	vector<pii > v;
	set<int> histo;
	string s="", a;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (i = 0; i < n; i++){
		cin >> a;
		s += a+"#";
	}
	if (k == 1){
		for (i = 0; i < s.size(); i++){
			if (s[i] == '#') cout << sum<<" ",cnt[0]=sum=0;
			else sum += (++cnt[0]);
		}
		return 0;
	}
	if (n < k){
		for (i = 0; i < n; i++) cout << "0" << " ";
		return 0;
	}
	for (i = 0; i < s.size(); i++){
		s_ix[i] = i;
		g[i] = s[i];
		p[i] = i;
		low[i] = high[i] = i;
		histo.insert(i);
	}
	histo.insert(i);
	d = 1;
	do{
		cnt_sort(s.size());
		tmp[s_ix[0]] = 1;
		for (i = 1; i < s.size(); i++)
			tmp[s_ix[i]] = tmp[s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
		for (i = 0; i < s.size(); i++)
			g[i] = tmp[i];
		d <<= 1;
	} while (s.size() != g[s_ix[s.size() - 1]]);
	for (i = 0; i < s.size(); i++) g[i]--;
	d = 0;
	for (i = 0; i < s.size(); i++){
		if (g[i] == 0) continue;
		if (s[i] == '#') continue;
		j = s_ix[g[i] - 1];
		d = max(d - 1, 0);
		while (i + d < s.size() && j + d < s.size() && s[i + d] == s[j + d]&&s[i+d]!='#')
			lcp[g[i]] = ++d;
		if (lcp[g[i]] > 0) v.push_back({lcp[g[i]],g[i]});
		d = lcp[g[i]] - 1;
	}
	//assign g's party
	sum = 1;
	for (i = 0; i < s.size(); i++){
		if (s[i] == '#') sum++;
		else a_ix[g[i]] = sum;
	}
	//nxt
	for (i = s.size() - 1; i >= 0; i--){
		nxt[i] = cnt[a_ix[i]] == 0 ? s.size() + 1 : cnt[a_ix[i]];
		cnt[a_ix[i]] = i;
	}
	//make tree by g
	sum = 0;
	for (i = 1; i < s.size(); i++){		//lcp[0] is always 0
		if (s[s_ix[i]] == '#') root[i] = root[i-1];
		else if (nxt[i] > s.size()){
			sum++;
			root[i] = make_tree(root[i - 1], 0, LEAF - 1, nxt[i], sum);
		}
		else
			root[i] = make_tree(root[i - 1], 0, LEAF - 1, nxt[i], 1);
	}


	sort(v.begin(), v.end());
	i = v.size() - 1;
	sum = 1;
	while (i >= 0){
		d = v[i].first;
		//cout << v[i].second << endl;
		while (i >= 0 && v[i].first == d){
			if (lcp[v[i].second] <= lcp[v[i].second + 1])
				join(v[i].second, v[i].second + 1);// , printf("join%d,%d\n", v[i].second, v[i].second + 1);
			if (lcp[v[i].second] <= lcp[v[i].second - 1])
				join(v[i].second - 1, v[i].second);// , printf("join%d,%d\n", v[i].second - 1, v[i].second);
			i--;
		}
		j = i+1;
		while (j!=v.size()){
			m = v.back().second;
			left = low[find(m)];
			right = high[find(m)];
			//cout << m << endl;
			//cout <<","<<m<<","<<find(m)<<","<<left<< "," << right << endl;
			v.pop_back();
			//if (stamp[m] == sum&&stamp[m-1]==sum) continue;
			if (k <= query(root[right], 0, LEAF - 1, right) - query(root[left - 2], 0, LEAF - 1, right)){
				//cout << query(root[right], 0, LEAF - 1, right) - query(root[left - 2], 0, LEAF - 1, right) << endl;
				
				//cout << query(root[right], 0, LEAF - 1, right) - query(root[left - 2], 0, LEAF - 1, right) << endl;
				

				for (auto it = histo.lower_bound(left - 1); *it <= right;){
					//cout << *it << endl;
					ans[a_ix[*it]] += d;
					histo.erase(it++);
				}
				/*for (m = left-1; m <= right; m++){
					if (stamp[m] != sum){
						ans[a_ix[m]]+=d;
						stamp[m] = sum;
						cout << m <<","<<d<< endl;
					}
				}*/
			}			
		}

		//sum++;
	}
	
	for (i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}
