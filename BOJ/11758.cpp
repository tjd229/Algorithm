//category : ccw, geometry

#include <stdio.h>
#include <utility>
using namespace std;
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	int res = (p2.first - p1.first)*(p3.second - p1.second) - (p3.first - p1.first)*(p2.second - p1.second);
	if (res < 0) return -1;
	if (res > 0) return 1;
	return 0;
}
int main(){
	pair<int, int> p1, p2, p3;
	scanf("%d%d", &p1.first, &p1.second);
	scanf("%d%d", &p2.first, &p2.second);
	scanf("%d%d", &p3.first, &p3.second);
	printf("%d",ccw(p1,p2,p3));
	return 0;
}

