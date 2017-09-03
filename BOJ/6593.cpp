//category : graph

#include <iostream>
#include <string>
#include <queue>
using namespace std;
string map[30][30];
bool visit[30][30][30];
int L, R, C;
struct Location{
	int i, j, k;
	int depth;
	Location next(int di, int dj, int dk){
		Location l;
		l.i = i + di;
		l.j = j + dj;
		l.k = k + dk;
		l.depth = depth + 1;
		return l;
	}
};
bool isRoad(int i, int j, int k){
	if (i < 0 || j < 0 || k < 0 || i >= L || j >= R || k >= C) return false;
	return !visit[i][j][k] && map[i][j][k] != '#';
}
int main(){
	int i, j,k;
	Location s;
	Location l;
	int ans;
	cin >> L >> R >> C;
	while (L != 0 && R != 0 && C != 0){
		for (i = 0; i < L; i++){
			for (j = 0; j < R; j++){
				cin >> map[i][j];
				for (k = 0; k < C; k++){
					visit[i][j][k] = false;
					if (map[i][j][k] == 'S'){
						s.i = i;
						s.j = j;
						s.k = k;
						s.depth = 0;
						visit[i][j][k] = true;
					}
				}
			}
		}
		ans = -1;
		queue<Location> q;
		q.push(s);
		while (!q.empty()){
			l = q.front();
			q.pop();
			if (isRoad(l.i+1, l.j, l.k)){
				if (map[l.i + 1][l.j][l.k] == 'E'){
					ans = l.depth + 1;
					break;
				}
				visit[l.i + 1][l.j][l.k] = true;
				q.push(l.next(1, 0, 0));
			}if (isRoad(l.i-1, l.j, l.k)){
				if (map[l.i - 1][l.j][l.k] == 'E'){
					ans = l.depth + 1;
					break;
				}
				visit[l.i - 1][l.j][l.k] = true;
				q.push(l.next(-1, 0, 0));
			}
			if (isRoad(l.i, l.j + 1, l.k)){
				if (map[l.i][l.j + 1][l.k] == 'E'){
					ans = l.depth + 1;
					break;
				}
				visit[l.i][l.j + 1][l.k] = true;
				q.push(l.next(0, 1, 0));
			}if (isRoad(l.i, l.j - 1, l.k)){
				if (map[l.i][l.j - 1][l.k] == 'E'){
					ans = l.depth + 1;
					break;
				}
				visit[l.i][l.j - 1][l.k] = true;
				q.push(l.next(0, -1, 0));
			}
			if (isRoad(l.i, l.j,l.k + 1)){
				if (map[l.i][l.j][l.k + 1] == 'E'){
					ans = l.depth + 1;
					break;
				}
				visit[l.i][l.j][l.k + 1] = true;
				q.push(l.next(0, 0, 1));

			}if (isRoad(l.i, l.j, l.k - 1)){
				if (map[l.i][l.j][l.k - 1] == 'E'){
					ans = l.depth + 1;
					break;
				}
				visit[l.i][l.j][l.k - 1] = true;
				q.push(l.next(0, 0, -1));
			}
		}
		if (ans == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
		cin >> L >> R >> C;
	}

	return 0;
}

