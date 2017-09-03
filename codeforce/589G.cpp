//category : ft

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int BI = 1 << 18;
ll time_tree[BI];
ll office_tree[BI];
pair<int, int> candidate[1000001];
int day[1000001];
void update(int ix,ll diff,ll ft[BI]){
	while (ix <= BI){
		ft[ix] += diff;
		ix += (ix&-ix);
	}
}
ll sum(int ix, ll ft[BI]){
	ll res = 0;
	while (ix > 0){
		res += ft[ix];
		ix -= (ix&-ix);
	}
	return res;
}
bool work(int ix,int m){
	ll pre = sum(m, time_tree) - sum(m, office_tree)*candidate[ix].first;
	//if (pre < 0) return false;
	return (pre - candidate[ix].second) >= 0;
}
int main(){
	int i;
	int n, m;
	int b;
	int l, r;
	int mid;
	vector<pair<int, int> > e;
	scanf("%d%d",&n,&m);
	for (i = 1; i <= m; i++){
		scanf("%d",&b);
		update(i, 1, office_tree);
		update(i, b, time_tree);
		e.push_back(make_pair(b,-i));
	}
	for (i = 1; i <= n; i++){
		scanf("%d%d", &candidate[i].first, &candidate[i].second);
		e.push_back(make_pair(candidate[i].first, i));
	}
	sort(e.begin(), e.end());
	for (i = 0; i < e.size(); i++){
		if (e[i].second < 0){
			e[i].second = -e[i].second;
			update(e[i].second, -1, office_tree);
			update(e[i].second, -e[i].first, time_tree);
		}
		else{
			l = 1;
			r = m;
			while(l <= r){
				mid = (l + r) / 2;
				if (work(e[i].second, mid)){
					day[e[i].second] = mid;
					r = mid - 1;
				}
				else
					l = mid + 1;
			}
		}

	}
	for (i = 1; i <= n; i++) printf("%d ",day[i]);

	return 0;
}