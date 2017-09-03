//category : graph

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int w, h;
string map[1000];
bool visit[1000][1000];
int ans;
int level;
bool ff(int i,int j){
	if (i < 0 || j < 0 || j >= w || i >= h) return false;
	if (map[i][j] == '#'||map[i][j]=='*') return false;
	map[i][j] = '*';
	return true;
}
bool move(int i, int j){
	if (i < 0 || j < 0 || j >= w || i >= h){
		ans = level;
		return false;
	}
	if (map[i][j] != '.') return false;
	if (visit[i][j]) return false;
	visit[i][j] = true;
	return true;
}
int main(){
	int T;
	int i, j;
	int end;
	int currf, curri;
	cin >> T;
	while (T--){
		cin >> w >> h;
		vector < pair<int, int> >fire;
		vector < pair<int, int> >me;
		for (i = 0; i < h; i++){
			cin >> map[i];
			for (j = 0; j < w; j++){
				visit[i][j] = false;
				if (map[i][j] == '@') me.push_back(make_pair(i, j));
				if (map[i][j] == '*') fire.push_back(make_pair(i, j));
			}
		}
		currf = curri = 0;
		level = 1;
		end = 0;
		ans = -1;
		while (end!=me.size()){
			end = fire.size();
			for (currf; currf < end; currf++){
				if (ff(fire[currf].first, fire[currf].second + 1))
					fire.push_back(make_pair(fire[currf].first, fire[currf].second + 1));
				if (ff(fire[currf].first, fire[currf].second - 1))
					fire.push_back(make_pair(fire[currf].first, fire[currf].second - 1));
				if (ff(fire[currf].first + 1, fire[currf].second))
					fire.push_back(make_pair(fire[currf].first + 1, fire[currf].second));
				if (ff(fire[currf].first - 1, fire[currf].second))
					fire.push_back(make_pair(fire[currf].first - 1, fire[currf].second));


			}
			end = me.size();
			for (curri; curri < end; curri++){
				if (move(me[curri].first, me[curri].second + 1))
					me.push_back(make_pair(me[curri].first, me[curri].second + 1));
				if (move(me[curri].first, me[curri].second - 1))
					me.push_back(make_pair(me[curri].first, me[curri].second - 1));
				if (move(me[curri].first + 1, me[curri].second))
					me.push_back(make_pair(me[curri].first + 1, me[curri].second));
				if (move(me[curri].first - 1, me[curri].second))
					me.push_back(make_pair(me[curri].first - 1, me[curri].second));
			}
			if (ans > 0) break;
			level++;
		}
		if (ans<0)	cout <<"IMPOSSIBLE\n";
		else cout << ans << "\n";
	}

	return 0;
}