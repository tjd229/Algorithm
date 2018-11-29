//implementation, math

#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
double ans[4];
ll h[4];
struct Prob{
	int A, B;
	double W, D, L;
}p[6];
void sim(int round,double prob,int pt[4]){

	if (round >= 6){
		pair<int, int> res[4];
		int cnt[10] = { 0 };
		for (int i = 0; i < 4; ++i) res[i] = {pt[i],i}, cnt[pt[i]]++;
		sort(res, res + 4);
		if (cnt[res[3].first] > 1) prob += prob;
		for (int i = 3; i >= 0; --i){
			if (i < 2 && res[i].first<res[i+1].first) break;
			ans[res[i].second] += prob / cnt[res[i].first];
		}
		return;
	}
	if (prob == 0.0) return;
	int l = p[round].A;
	int r = p[round].B;
	pt[l] += 3;
	sim(round + 1, prob*p[round].W, pt);
	pt[l] -= 2;
	pt[r] += 1;
	sim(round + 1, prob*p[round].D, pt);
	pt[l] -= 1;
	pt[r] += 2;
	sim(round + 1, prob*p[round].L, pt);
	pt[r] -= 3;
}
int main(){
	int i,j;
	for (i = 0; i < 4; i++){
		string nation;
		cin >> nation;
		for (j = 0; j < nation.size(); ++j){
			h[i] = h[i] * 26 + nation[j] - 'A';
		}
	}
	for (i = 0; i < 6; ++i){
		string A, B;
		ll hA, hB;
		cin >> A >> B >> p[i].W >> p[i].D >> p[i].L;
		for (j = hA = 0; j < A.size(); ++j)
			hA = hA * 26 + A[j] - 'A';
		for (j = hB = 0; j < B.size(); ++j)
			hB = hB * 26 + B[j] - 'A';
		for (j = 0; j < 4; j++){
			if (hB == h[j]) p[i].B = j;
			if (hA == h[j]) p[i].A = j;
		}
	}
	int pt[4] = { 0 };
	sim(0, 1, pt);
	cout.precision(10);
	cout << fixed;
	for (i = 0; i < 4; ++i) cout<<ans[i] << "\n";
	return 0;
}
