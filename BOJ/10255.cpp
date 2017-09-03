//category : geometry, ccw, math

#include <stdio.h>

struct Point{
	int x, y;
	bool operator <(Point p){
		if (p.x == x) return y < p.y;
		return x<p.x;
	}
	bool operator ==(Point p){
		return x == p.x&&y == p.y;
	}
	bool operator <=(Point p){
		
		return *this==p || *this<p;
	}
};
struct Rect{
	Point ldP,rtP;
	Point leftBottom, rightTop, leftTop, rightBottom;
	Rect(int xmin,int ymin,int xmax,int ymax){
		leftBottom.x = leftTop.x=xmin;
		leftBottom.y = rightBottom.y=ymin;
		rightTop.x = rightBottom.x=xmax;
		rightTop.y = leftTop.y=ymax;
	}
};
int ccw(Point p1, Point p2, Point p3) {
	long long temp = (long long)(p2.x - p1.x)*(long long)(p3.y - p1.y) - (long long)(p3.x - p1.x)*(long long)(p2.y - p1.y);
	if (temp > 0) {
		return 1;
	}
	else if (temp < 0) {
		return -1;
	}
	else {
		return 0;
	}
}
int innerLine(Point p1, Point p2, Point p3, Point p4){
	Point min1, min2, max1, max2;
	if (p1 < p2) min1 = p1, max1 = p2;
	else min1 = p2, max1 = p1;
	if (p3 < p4) min2 = p3, max2 = p4;
	else min2 = p4, max2 = p3;
	if (max2 < min1 || max1 < min2) return 0;
	if (max2 == min1 || max1 == min2) return 1;
	return 8;

}

int check(Point r1,Point r2,Point p1,Point p2){
	if (ccw(r1, r2, p1) == 0 && ccw(r1, r2, p2) == 0){
		//if (!innerLine(r1, r2, p1, p2)) return 0;

		return innerLine(r1, r2, p1, p2);
	}
	else if (ccw(r1, r2, p1) == ccw(r1, r2, p2) ){
		return 0;
	}
	else{
		int t= ccw(p1, p2, r1) + ccw(p1, p2, r2);
		if (t == 0) return 2;
		if (t == 1 || t == -1) return 1;
		return 0;
	}
}
int intersection(Rect r,Point p1,Point p2){
	int res = 0;
	res += check(r.leftBottom, r.leftTop, p1, p2);				
	res += check(r.leftTop, r.rightTop, p1, p2);				
	res += check(r.rightTop, r.rightBottom, p1, p2);			
	res += check(r.rightBottom, r.leftBottom, p1, p2);			
	res /= 2;
	if (res > 4) res = 4;
	return res;
}
int main(){
	int T;
	int xmin, xmax, ymin, ymax;
	int x1, x2, y1, y2;
	Point p1, p2;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
		scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);
		
		printf("%d\n",intersection(Rect(xmin,ymin,xmax,ymax),p1,p2));
		
	}

	return 0;
}


