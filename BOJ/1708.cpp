//category : ccw, geometry, convex hull

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int sx, sy;
long long dist(pair<int, int> p1, pair<int, int> p2){
	return (long long)(p1.first - p2.first)*(long long)(p1.first - p2.first) 
		+ (long long)(p1.second - p2.second)*(long long)(p1.second - p2.second);
}
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	long long res1 = (long long)(p2.first - p1.first)*(long long)(p3.second - p1.second);
	long long res2 = (long long)(p3.first - p1.first)*(long long)(p2.second - p1.second);
	if (res1 < res2) return -1;
	if (res1 > res2) return 1;
	return 0;
}
bool cmp(pair<int,int> p1,pair<int,int> p2){
	if (p1.first == sx&&p1.second == sy) return true;
	if (p2.first == sx&&p2.second == sy) return false;
	int res = ccw(make_pair(sx, sy), p1, p2);
	if (res == 0) return dist(make_pair(sx, sy), p1) < dist(make_pair(sx, sy), p2);
	return res>0;
}
int main(){
	int N;
	int x, y;
	sx = sy = 40001;
	int i;
	vector<pair<int, int> > v;
	vector<pair<int, int> > hull;
	scanf("%d",&N);
	for (i = 0; i < N; i++){
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(x,y));
		if (sy > y) sx = x, sy = y;
		else if (sy == y&&sx>x) sx = x, sy = y;
	}
	sort(v.begin(), v.end(), cmp);
	hull.push_back(v[0]);
	hull.push_back(v[1]);

	for (i = 2; i < N;){
		y = hull.size();
		x = ccw(hull[y - 2], hull[y - 1], v[i]);
		if (x <= 0)
			hull.pop_back();		
		if(x>=0){
			hull.push_back(v[i]);
			i++;
		}
		
	}
	printf("%d",hull.size());
	return 0;
}