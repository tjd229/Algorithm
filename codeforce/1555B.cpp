//geometry
#include <stdio.h>
int W, H;
double _min(double a, double b) {
	if (a < 0) return b;
	if (b < 0) return a;
	return a < b ? a : b;
}
double sim(int x1,int y1,int x2,int y2,int w,int h) {
	double ans = -1;
	int dx, dy;
	int X = w, Y = h;
	dx = dy = 0;
	if (x1 < X) dx = X - x1;
	if (x2 + dx <= W && y2 + dy <= H) ans = dx;
	dx = dy = 0;
	if (y1 < Y) dy = Y - y1;
	if (x2 + dx <= W && y2 + dy <= H)
		ans = _min(ans, dy);
	dx = dy = 0;
	return ans;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		
		int x1, y1, x2, y2,w,h;
		int dx, dy;
		scanf("%d%d%d%d%d%d%d%d",&W,&H,&x1,&y1,&x2,&y2,&w,&h);
		double ans = -1;
		ans = _min(ans, sim(x1, y1, x2, y2, w, h));
		ans = _min(ans, sim(W-x2, y1, W-x1, y2, w, h));
		ans = _min(ans, sim(x1, H-y2, x2, H-y1, w, h));
		ans = _min(ans, sim(W-x2, H - y2, W-x1, H - y1, w, h));
		printf("%lf\n",ans);
		
	}
 
	return 0;
}