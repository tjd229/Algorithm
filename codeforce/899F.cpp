//category : st, string

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
const int LEAF = 1 << 18;
int st[LEAF + LEAF];
set<int> pos[10 + 26 + 26];
int c2i(char c){
	if ('0' <= c&&c <= '9') return c - '0';
	if ('A' <= c&&c <= 'Z') return c - 'A' + 10;
	//if ('a' <= c&&c <= 'z') 
	return c - 'a' + 10+26;
}
void update(int ix, int val){
	st[ix] += val;
	ix >>= 1;
	while (ix != 0){
		st[ix] += val;
		ix >>= 1;
	}
}
int kth(int ix, int s, int e, int k){
	if (s == e) return ix - LEAF;
	if (st[ix + ix] < k) return kth(ix + ix + 1, 1 + ((s + e) >> 1), e, k-st[ix+ix]);
	return kth(ix + ix, s, (s + e) >> 1, k);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	int n, m;
	string s;
	int l, r;
	char c;
	cin >> n >> m>>s;
	
	for (i = 0; i < n; i++){
		update(LEAF+i+1,1);
		pos[c2i(s[i])].insert(i + 1);
	}
	while (m--){
		cin >> l >> r >> c;
		l = kth(1, 0, LEAF - 1, l);
		r = kth(1, 0, LEAF - 1, r);
		i = c2i(c);
		auto it = pos[i].lower_bound(l);
		while (it != pos[i].end() && *it <= r){
			update(LEAF+*it,-1);
			pos[i].erase(it++);			
		}
	}
	for (i = 0; i < n; i++)
		if (st[LEAF + 1 + i]) cout << s[i];
	cout << "\n";

}
