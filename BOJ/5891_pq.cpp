//category : line sweeping

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000001
using namespace std;
int dq[MAX][2];
int main(){
	int i,j;
	int N, D;
	int x, y;
	int l, r;
	int w;
	int ans = MAX;
	vector<pair<int, int> > pt;
	priority_queue<pair<int, int> > lpq, upq;
	scanf("%d%d",&N,&D);
	for (i = 0; i < N; i++){
		scanf("%d%d",&x,&y);
		pt.push_back(make_pair(x,y));
	}
	sort(pt.begin(), pt.end());
	l = 0;
	r = 0;
	lpq.push(make_pair(-pt[0].second, 0));
	upq.push(make_pair(pt[0].second, 0));
	while (r<pt.size()){
		
		while (lpq.top().second < l) lpq.pop();
		while (upq.top().second < l) upq.pop();
		i = -lpq.top().first;
		j = upq.top().first;
		if (l!=r&&j - i >= D){
			if (ans > pt[r].first - pt[l].first){
				if (pt[r].first - pt[l].first == 0) ans = 1;
				else
					ans = pt[r].first - pt[l].first;
			}
			l++;
			
		}
		else{
			r++;
			if (r < pt.size()){
				lpq.push(make_pair(-pt[r].second, r));
				upq.push(make_pair(pt[r].second, r));
			}
		}
	}
	printf("%d",ans==MAX? -1:ans);


	return 0;
}