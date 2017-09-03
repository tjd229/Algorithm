//category : ccw, geometry

#include <stdio.h>
#include <utility>
using namespace std;
int cnt[3];
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	long long res1 = (long long)(p2.first - p1.first)*(long long)(p3.second - p1.second);
	long long res2 = (long long)(p3.first - p1.first)*(long long)(p2.second - p1.second);
	if (res1 < res2) return -1;
	if (res1 > res2) return 1;
	return 0;
}
int main(){
	int n;
	pair<int, int> last, llast,curr;
	scanf("%d", &n);
	scanf("%d%d", &last.first, &last.second);
	scanf("%d%d", &curr.first, &curr.second);
	for (int i = 2; i < n; i++){
		llast = last;
		last = curr;
		scanf("%d%d", &curr.first, &curr.second);
		cnt[ccw(llast,last,curr)+1]++;
	}
	printf("%d",cnt[0]<cnt[2]? cnt[0]:cnt[2]);

	return 0;
}