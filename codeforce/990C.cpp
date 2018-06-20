//category : implementation

#include <iostream>
#include <string>
#define ll long long
using namespace std;
string bracket[(int)3e5];
ll l[(int)3e5+1], r[(int)3e5+1];
bool g[(int)3e5];
int right(int ix,int s,int e){
	int stk = 0;
	for (int i = s; i < e; i++){
		if (bracket[ix][i] == '(') stk++;
		else stk--;
		if (stk < 0) return false;
	}
	return stk == 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int i,j;
	long long ans = 0;
	long long ind = 0;

	cin >> n;
	for (i = 0; i < n; i++){
		cin >> bracket[i];
		g[i] = right(i, 0, bracket[i].size());
		ind += g[i];
	}
	for (i = 0; i < n; i++){
		if (g[i]) continue;
		int cntl = 0;
		int cntr = 0;
		//l
		for (j = 0; j < bracket[i].size(); j++){
			if (bracket[i][j] == '(') cntl++;
			else{
				if (cntl != 0) cntl--;
				else cntr++;
			}
		}
		if (cntl > 0 && cntr > 0) continue;
		l[cntl]++;
		r[cntr]++;
	}
	for (i = 1; i <= 3e5; i++) ans += l[i] * r[i];
	ans += ind*ind;
	
	cout << ans;
	return 0;
}
