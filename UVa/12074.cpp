//category : pst

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
const int maxy = 1 << 22;
const int maxn = 1e5;
const int depth = 23;
struct Forest{
	int X, Y, W, L;
	bool operator<(const Forest f){
		return W < f.W;
	}
}f[maxn];
int st[maxn*depth + 1], qr[4][maxn*depth + 1];
int root[maxn+1];
int cnt;
int make_tree(int pre,int sx,int sy,int ex,int ey,int x,int y,int val){
	
	if (sx>x || ex<x || sy>y || ey < y) return pre;
	int ix = ++cnt;
	if (sx == ex && sy == ey) st[ix] = max(st[ix], val);
	else{
		int mx = (sx + ex) >> 1;
		int my = (sy + ey) >> 1;
		qr[0][ix] = make_tree(qr[0][pre], mx + 1, my + 1, ex, ey,x,y, val);
		qr[1][ix] = make_tree(qr[1][pre], sx, my + 1, mx, ey, x, y, val);
		qr[2][ix] = make_tree(qr[2][pre], mx + 1, sy, ex, my, x, y, val);
		qr[3][ix] = make_tree(qr[3][pre], sx,sy, mx, my, x, y, val);
		for (int i = 0; i < 4; i++) st[ix] = max(st[ix], st[qr[i][ix]]);
	}
	return ix;
}
int query(int ix,int sx,int sy,int ex,int ey, int fromx,int fromy,int tox,int toy){

	if (ix == 0) return 0;
	if (ex < fromx || tox < sx || ey < fromy || toy < sy) return 0;
	if (fromx <= sx && fromy <= sy && ex <= tox && ey <= toy){

		return st[ix];
	}
	int mx = (sx + ex) >> 1;
	int my = (sy + ey) >> 1;
	int res = query(qr[0][ix], mx + 1, my + 1, ex, ey, fromx,fromy,tox,toy);
	res = max(res,query(qr[1][ix], sx, my + 1, mx, ey, fromx, fromy, tox, toy));
	res = max(res,query(qr[2][ix], mx + 1, sy, ex, my, fromx, fromy, tox, toy));
	res = max(res,query(qr[3][ix], sx, sy, mx, my, fromx, fromy, tox, toy));
	return res;
}
int main(){
	int tc = 1;
	int t;
	int n;
	int X, Y, W, L;
	int i;

	//freopen("i.txt", "r", stdin);

	for (scanf("%d", &t); tc <= t; tc++){
		memset(st,0,sizeof(st));
		cnt = 0;
		int minxy = maxy;
		int ans = 0;
		for (scanf("%d", &n), i = 0; i < n; i++){
			scanf("%d%d%d%d", &X, &Y, &W, &L);

			if (minxy > X-Y) minxy = X-Y;
			f[i] = { X-Y, Y+X, W, L };
		}
		for (i = 0; i < n && minxy < 0; i++) f[i].X -= minxy;// , f[i].Y -= minxy;
		sort(f, f + n);

		for (i = 0; i < n; i++){
			int fromx = max(0, f[i].X - f[i].L);
			int fromy = max(0, f[i].Y - f[i].L);
			int tox = min(maxy, f[i].X + f[i].L);
			int toy = min(maxy, f[i].Y + f[i].L);
			int res = query(root[i], 0, 0, maxy - 1, maxy - 1, fromx, fromy, tox, toy)+1;
			if (ans < res) ans = res;

			root[i + 1] = make_tree(root[i], 0, 0, maxy - 1, maxy - 1, f[i].X, f[i].Y, res);

		}
		printf("Case %d: %d\n",tc,ans);
	}
	
	return 0;
}
