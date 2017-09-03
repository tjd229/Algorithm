//category : string, ft

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int BI = 1 << 17;
int ft[BI];
void update(int ix,int diff){
	while (ix < BI){
		ft[ix] += diff;
		ix += (ix&-ix);
	}
}
long long sum(int ix){
	long long res = 0;
	while (ix != 0){
		res += ft[ix];
		ix -= (ix&-ix);
	}
	return res;
}
int main(){
	int i;
	int ix;
	int N;
	long long ans = 0;
	cin >> N;
	string s;
	vector<string> v,rev;
	for (i = 0; i < N; i++){
		cin >> s;
		v.push_back(s);
		reverse(s.begin(), s.end());
		rev.push_back(s);
		
	}
	sort(v.begin(), v.end());
	sort(rev.begin(), rev.end());

	for (i = 0; i < N; i++){
		s = v[i];
		reverse(s.begin(), s.end());
		ix = upper_bound(rev.begin(), rev.end(), s) - rev.begin() + 1;
		ans += i - sum(ix);
		update(ix+1, 1);
	}
	cout << ans;


	return 0;
}