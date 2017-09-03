//category : ccw, geometry



#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<long long, long long> > v;
int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
	long long res1 = (p2.first - p1.first)*(p3.second - p1.second);
	long long res2 = (p3.first - p1.first)*(p2.second - p1.second);
	if (res1 < res2) return -1;
	if (res1 > res2) return 1;
	return 0;
}
bool cross(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3, pair<long long, long long> p4){
	return ccw(p1, p2, p3) != ccw(p1, p2, p4) && ccw(p3, p4, p2) != ccw(p3, p4, p1);
}
int main(){
	int N;
	int x, y;
	int i,j;
	int cnt;
	scanf("%d",&N);
	for (i = 0; i < N; i++){
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(x, y));
	}
	for (i = 0; i < 3; i++){
		cnt = 0;
		scanf("%d%d", &x, &y);
		if (N < 3){
			printf("0\n");
			continue;
		}
		for (j = 0; j < N-1; j++){
			if (ccw(v[j],make_pair(x,y),make_pair(-1,-1))!=0
				&&cross(v[j], v[j + 1], make_pair(x, y), make_pair(-1, -1))) cnt++;
		}
		if (ccw(v[j], make_pair(x, y), make_pair(-1, -1)) != 0
			&&cross(v[j], v[0], make_pair(x, y), make_pair(-1, -1))) cnt++;
		printf("%d\n",cnt&1);
	}
	return 0;
}