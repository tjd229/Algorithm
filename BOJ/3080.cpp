//category : math
#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
string name[3001];
int lcp[3001];
ll facto[3001];
const int mod = 1e9 + 7;
void cnt_lcp(int ix){
	int i, j;
	i = j = 0;
	while (name[ix][i] == name[ix - 1][j]){
		lcp[ix]++;
		i++; j++;
		if (name[ix].size() == i || name[ix - 1].size() == j) break;
	}
}
ll factorial(int n){
	if (n <= 1) return 1;
	if (facto[n] == 0){
		facto[n] = factorial(n - 1);
		facto[n] *= n;
		if (facto[n] >= mod) facto[n] %= mod;
	}
	return facto[n];
}
ll order(int s,int e,int level){
	if (s == e) return 2;
	ll ans = 1;
	int l = s-1;
	int f = 0;
	int i;
	//cout << "level:" << level << endl;
	for (i = s; i <= e; i++){
		//cout << lcp[i] << endl;
		if (lcp[i] == level){
			if (l + 1 != i){
				ans *= order(l+1,i-1,level+1);
				if (ans >= mod) ans %= mod;
				//f++;
			}
			f++;
			l = i;			
		}
	}
	if (l!= e){
		ans *= order(l + 1, e, level + 1);
		if (ans >= mod) ans %= mod;
		//f++;
	}f++;
	//cout << level << "," << f << ","<<s<<","<<e<< ","<<l<<endl;
	ans *= factorial(f);
	if (ans >= mod) ans %= mod;
	return ans;
}
int main(){
	int i, j;
	int N;
	cin >> N;
	for (i = 1; i <= N; i++){
		cin >> name[i];
	}
	sort(name + 1, name + 1 + N);
	for (i = 2; i <= N; i++){
		cnt_lcp(i);
	}
	cout << order(2,N,0);
	

	return 0;
}