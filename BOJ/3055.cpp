//category : graph

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int R, C;
string map[50];
bool visit[50][50];
int ans;
int level;
bool flow(int i,int j){
	if (i < 0 || j < 0 || j >= C || i >= R) return false;
	if (map[i][j] != '.') return false;
	map[i][j] = '*';
	return true;
}
bool move(int i, int j){
	if (i < 0 || j < 0 || j >= C || i >= R){
		return false;
	}
	if (map[i][j] == 'D'){
		ans = level;
		return false;
	}
	if (map[i][j] != '.') return false;
	if (visit[i][j]) return false;
	visit[i][j] = true;
	return true;
}
int main(){
	int i, j;
	int end;
	int currw, curri;


	cin >> R >> C;
	vector < pair<int, int> >water;
	vector < pair<int, int> >me;
	for (i = 0; i < R; i++){
		cin >> map[i];
		for (j = 0; j < C; j++){
			visit[i][j] = false;
			if (map[i][j] == 'S') me.push_back(make_pair(i, j)),map[i][j]='.';
			if (map[i][j] == '*') water.push_back(make_pair(i, j));
		}
	}
	currw = curri = 0;
	level = 1;
	end = 0;
	ans = -1;
	while (end!=me.size()){
		end = water.size();
		for (currw; currw < end; currw++){
			if (flow(water[currw].first, water[currw].second + 1))
				water.push_back(make_pair(water[currw].first, water[currw].second + 1));
			if (flow(water[currw].first, water[currw].second - 1))
				water.push_back(make_pair(water[currw].first, water[currw].second - 1));
			if (flow(water[currw].first + 1, water[currw].second))
				water.push_back(make_pair(water[currw].first + 1, water[currw].second));
			if (flow(water[currw].first - 1, water[currw].second))
				water.push_back(make_pair(water[currw].first - 1, water[currw].second));


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
	if (ans<0)	cout <<"KAKTUS\n";
	else cout << ans << "\n";


	return 0;
}

