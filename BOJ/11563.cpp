//math, geometry, ccw
#include <stdio.h>
#include <math.h>
struct Road {
	double xs, ys, xe, ye;
}r1[2000],r2[2000];
double min(double a, double b) { return a < b ? a : b; }
double dist(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx*dx + dy * dy);
}
double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	double t1 = (x2 - x1)*(y3 - y1);
	double t2 = (x3 - x1)*(y2 - y1);
	return t1 - t2;
}
double dot(double x1, double y1, double x2, double y2, double x3, double y3) {
	return (x2 - x1)*(x3 - x2) + (y2 - y1)*(y3 - y2);
}
double foot(Road &r,double x,double y) {
	double in1 = dot(r.xs, r.ys, r.xe, r.ye, x, y);
	double in2 = dot(r.xe, r.ye, r.xs, r.ys, x, y);
	if (in1 >= 0 || in2 >= 0) return 1e9;
	double sq = ccw(r.xs, r.ys, r.xe, r.ye, x,y);
	double res = sq / dist(r.xs, r.ys, r.xe, r.ye);
	if (res < 0) res = -res;
	return res;
}
int main() {
	int i, j, n, m;
	double ans = 1e9;
	for (scanf("%d%d", &n, &m), i = 0; i < n; ++i) 
		scanf("%lf%lf%lf%lf", &r1[i].xs, &r1[i].ys, &r1[i].xe, &r1[i].ye);

	for (i = 0; i < m; ++i) {
		scanf("%lf%lf%lf%lf", &r2[i].xs, &r2[i].ys, &r2[i].xe, &r2[i].ye);
		for (j = 0; j < n; ++j) {
			ans = min(dist(r2[i].xs, r2[i].ys, r1[j].xs, r1[j].ys), ans);
			ans = min(dist(r2[i].xs, r2[i].ys, r1[j].xe, r1[j].ye), ans);
			ans = min(dist(r2[i].xe, r2[i].ye, r1[j].xs, r1[j].ys), ans);
			ans = min(dist(r2[i].xe, r2[i].ye, r1[j].xe, r1[j].ye), ans);

			ans = min(foot(r2[i], r1[j].xs, r1[j].ys), ans);
			ans = min(foot(r2[i], r1[j].xe, r1[j].ye), ans);
			ans = min(foot(r1[j], r2[i].xs, r2[i].ys), ans);
			ans = min(foot(r1[j], r2[i].xe, r2[i].ye), ans);
		}
	}
	printf("%lf",ans);
	return 0;
}
