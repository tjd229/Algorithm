//category : djs

#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int p[300000];
int pt[300000];
int line[300000];
int x[100000], y[100000];
ll sq[100002];
ll pw(int e){
	if (e == 0) return 1;
	if (e == 1) return 2;
	if (sq[e] != 0) return sq[e];
	if (e & 1){
		sq[e] = pw(e - 1) << 1;
	}
	else
		sq[e] = pw(e >> 1)*pw(e >> 1);
	if (sq[e] >= mod) sq[e] %= mod;
	return sq[e];
}
int find(int a){
	if (p[a] != a)
		p[a] = find(p[a]);
	return p[a];
}
void join(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b){
		line[b] += line[a];
		pt[b] += pt[a];
		p[a] = b;
	}
	else{
		line[a] += line[b];
		pt[a] += pt[b];
		p[b] = a;
	}
}
int compress(int p,vector<int> &v){
	return lower_bound(v.begin(),v.end(),p)-v.begin();
}
ll subtract(ll a, ll b){
	if (a < b) a += mod;
	a -= b;
	if (a >= mod) a -= mod;
	return a;
}
int main(){
	int i;
	int n;
	int cx, cy;
	ll ans = 1;
	vector<int> x_coord, y_coord;
	for (scanf("%d", &n), i = 0; i < n; i++){
		p[n + i] = n + i;
		line[n + i] = 1;
		pt[n + i] = 0;
		p[n+n + i] = n+n + i;
		line[n + n + i] = 1;
		pt[n+n + i] = 0;
		p[i] = i;
		line[i] = 0;
		pt[i] = 1;
		scanf("%d%d",x+i,y+i);
		x_coord.pb(x[i]);
		y_coord.pb(y[i]);		
	}
	sort(x_coord.begin(), x_coord.end());
	sort(y_coord.begin(), y_coord.end());
	x_coord.resize(unique(x_coord.begin(), x_coord.end()) - x_coord.begin());
	y_coord.resize(unique(y_coord.begin(), y_coord.end()) - y_coord.begin());
	for (i = 0; i < n; i++){
		cx = compress(x[i], x_coord);
		cy = compress(y[i], y_coord);
		join(n + cx, i);
		join(n+n + cy, i);
	}
	for (i = 0,cy=n+n; i < n; i++){
		if (p[cy + i] == cy + i){
			ans *= subtract(pw(line[cy + i]), (line[cy + i]>pt[cy + i]));
			//ans *= pw(line[cy+i])-(line[cy+i]>pt[cy+i]);
			if (ans >= mod) ans %= mod;
		
		}
	}

	printf("%I64d",ans);

	return 0;
}