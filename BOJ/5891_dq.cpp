//category : line sweeping

#include <stdio.h>
#include <vector>
#include <deque>
#include <algorithm>
#define MAX 1000001
using namespace std;
int main(){
	int i,j;
	int N, D;
	int x, y;
	int l, r;
	int w;
	int ans = MAX;
	vector<pair<int, int> > pt;
	deque<pair<int, int> > ldq,udq;
	scanf("%d%d",&N,&D);
	for (i = 0; i < N; i++){
		scanf("%d%d",&x,&y);
		pt.push_back(make_pair(x,y));
	}
	sort(pt.begin(), pt.end());
	l = 0;
	r = 0;
	ldq.push_back(make_pair(pt[r].second, r));
	udq.push_back(make_pair(pt[r].second, r));
	while (r<pt.size()){
		
		while (ldq.front().second < l) ldq.pop_front();
		while (udq.front().second < l) udq.pop_front();
		i = ldq.front().first;
		j = udq.front().first;
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
				while (!ldq.empty() && ldq.back().first > pt[r].second) ldq.pop_back();
				ldq.push_back(make_pair(pt[r].second, r));
				while (!udq.empty() && udq.back().first < pt[r].second) udq.pop_back();
				udq.push_back(make_pair(pt[r].second, r));
			}
		}
	}
	printf("%d",ans==MAX? -1:ans);


	return 0;
}