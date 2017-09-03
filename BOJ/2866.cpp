//category : string, hashing

#include <string>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
string mat[1000];
ll rc1[1000];
ll rc2[1000];
int R, C;
const int e=27;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
void init_col(int c){
	int i;
	for (i = R-1; i >=0; i--){
		rc1[c] *= e;
		rc2[c] *= e;
		if (rc1[c] >= mod1) rc1[c] %= mod1;
		if (rc2[c] >= mod2) rc2[c] %= mod2;
		rc1[c] += (ll)(mat[i][c] - 'a' + 1);
		rc2[c] += (ll)(mat[i][c] - 'a' + 1);
		if (rc1[c] >= mod1) rc1[c] %= mod1;
		if (rc2[c] >= mod2) rc2[c] %= mod2;
	}
}

int main(){
	int i,j;
	int count = 0;
	ll mul1 = 1;
	ll mul2 = 1;
	ll subtract1, subtract2;
	cin >> R >> C;
	for (i = 0; i < R; i++) cin >> mat[i];
	for (i = 0; i < C; i++) init_col(i);
	for (i = 1; i < R; i++){
		set<pair<ll,ll>> s;
		for (j = 0; j < C; j++){
			subtract1 = mul1*(ll)(mat[i - 1][j] - 'a' + 1);
			subtract2 = mul2*(ll)(mat[i - 1][j] - 'a' + 1);
			//subtract(rc[j], (mul*(ll)(mat[i-1][j] - 'a'+1))%mod);
			rc1[j] += mod1;
			rc1[j] -= subtract1%mod1;
			rc2[j] += mod2;
			rc2[j] -= subtract2%mod2;
			if (rc1[j] >= mod1) rc1[j] %= mod1;
			if (rc2[j] >= mod2) rc2[j] %= mod2;

			if (s.find(make_pair(rc1[j],rc2[j])) != s.end()){
				cout << count;
				return 0;
			}
			s.insert(make_pair(rc1[j], rc2[j]));
		}

		mul1 *= e;
		mul2 *= e;
		if (mul1 >= mod1) mul1 %= mod1;
		if (mul2 >= mod2) mul2 %= mod2;
		count++;
	}
	cout << count;
	return 0;
}