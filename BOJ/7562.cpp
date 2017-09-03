//category : graph


#include <stdio.h>
#include <vector>
using namespace std;
int map[300][300];
int level = 1;
int l;
int x, y;
int ans;
int depth;
bool move(int x_, int y_){
	if (x_ < 0 || y_ < 0 || x_ >= l || y_ >= l) return false;
	if (x_ == x&&y_ == y){
		ans = depth;
		return false;
	}
	if (map[y_][x_] == level) return false;
	map[y_][x_] = level;
	return true;
}
int main(){
	int T;
	int end;
	int i;
	for (scanf("%d", &T); level <= T; level++){
		vector<pair<int, int>  > v;
		scanf("%d", &l);
		scanf("%d%d", &x,&y);
		v.push_back(make_pair(x, y));
		//map[y][x] = level;
		ans = -1;
		depth = 0;		
		scanf("%d%d", &x, &y);
		move(v[0].first, v[0].second);
		if (ans >= 0){
			printf("%d\n",ans);
			continue;
		}
		end = 0;
		i = 0;
		while (v.size() != end){
			end = v.size();
			depth++;
			for (; i < end; i++){
				if (move(v[i].first + 2, v[i].second + 1))
					v.push_back(make_pair(v[i].first + 2, v[i].second + 1));
				if (move(v[i].first + 2, v[i].second - 1))
					v.push_back(make_pair(v[i].first + 2, v[i].second - 1));
				if (move(v[i].first - 2, v[i].second + 1))
					v.push_back(make_pair(v[i].first - 2, v[i].second + 1));
				if (move(v[i].first - 2, v[i].second - 1))
					v.push_back(make_pair(v[i].first - 2, v[i].second - 1));
				if (move(v[i].first + 1, v[i].second + 2))
					v.push_back(make_pair(v[i].first + 1, v[i].second + 2));
				if (move(v[i].first + 1, v[i].second - 2))
					v.push_back(make_pair(v[i].first + 1, v[i].second - 2));
				if (move(v[i].first - 1, v[i].second + 2))
					v.push_back(make_pair(v[i].first - 1, v[i].second + 2));
				if (move(v[i].first - 1, v[i].second - 2))
					v.push_back(make_pair(v[i].first - 1, v[i].second - 2));
			}
			if (ans > 0) break;
			//depth++;
		}
		printf("%d\n",ans);
	}
	return 0;
}