//greedy

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<char> order[100001];
void print_vec(vector<char> &v) {
	for (auto c : v)
		cout << c;
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, t;
	cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<char > v;
		for (auto c : s) v.push_back(c);
		sort(v.begin(), v.end());
		//order
		for (i = 1; i <= k; ++i) order[i].clear();
		for (i = 0; i < v.size();) {
			for (int j = 1; j <= k && i < v.size(); ++i, ++j)
				order[j].push_back(v[i]);
		}
		
		int mx_len = 0;
		int pick = 0;
		for (i = 1; i <= k; ++i) {
			if (mx_len <= order[i].size()) {
				mx_len = order[i].size();
				pick = i;//default
			}
		}
		for (i = 0; i < order[k].size(); ++i) {
			if (order[k][i] != order[pick][i]) {
				pick = k;
				break;
			}
		}
		//vector<char> order = order[pick];
		//all
		//printf("pick:%d\n",pick);
		vector<char> take = {v[k-1]};
		for (i = k; v[0]==v[k-1] && i < v.size(); ++i)
			take.push_back(v[i]);
		
 
		bool g=1;
		mx_len = order[pick].size();
		if (mx_len < take.size()) mx_len = take.size();
		for (i = 0; i < mx_len; ++i) {
			if (take.size() <= i) {
				g = 1;
				break;
			}
			if (order[pick].size() <= i) {
				g = 0;
				break;
			}
			if (take[i]>order[pick][i]) {
				g = 0;
				break;
			}
			if (take[i] < order[pick][i])  {
				g = 1;
				break;
			}
		}
		print_vec(g ? take : order[pick]);
		//print_vec(order[pick]);
		//print_vec(take);
		
	}
 
	return 0;
}
