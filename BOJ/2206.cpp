//category : graph

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string map[1000];
int visit[1000][1000][2];
int N, M;
int level;
int ans = -1;
struct Player{
	int i, j;
	int yellow;
};
bool move(int di, int dj, Player &p){
	int i = p.i + di;
	int j = p.j + dj;
	if (i == N - 1 && j == M - 1){
		ans = level;
		return false;
	}
	if (i < 0 || j < 0 || i >= N || j >= M) return false;
	if (map[i][j] != '0'){
		if (visit[i][j][1]) return false;
		if (p.yellow != 0) return false;
		visit[i][j][1] = true;
		p.yellow = 1;
	}
	else{
		if (visit[i][j][p.yellow]) return false;
		visit[i][j][p.yellow] = true;
	}
	return true;
}
int main(){
	int i, j;
	vector<Player> v;
	cin >> N >> M;
	for (i = 0; i < N; i++){
		cin >> map[i];
	}
	Player s, p;
	s.i = s.j = 0;
	s.yellow = 0;
	v.push_back(s);
	visit[0][0][0] = true;
	int end = 0;
	i = 0;
	level = 1;
	while (v.size() != end){

		end = v.size();
		level++;
		for (; i < end; i++){
			p = v[i];
			if (move(1, 0, p)){
				p.i += 1;
				v.push_back(p);
			}
			p = v[i];
			if (move(-1, 0, p)){
				p.i += -1;
				v.push_back(p);
			}
			p = v[i];
			if (move(0, 1, p)){
				p.j += 1;
				v.push_back(p);
			}
			p = v[i];
			if (move(0, -1, p)){
				p.j += -1;
				v.push_back(p);
			}
		}
		if (ans > 0) break;
	}
	if (N + M == 2) ans = 1;
	cout << ans;
	return 0;
}
