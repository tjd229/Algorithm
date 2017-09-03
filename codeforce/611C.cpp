//category : dp



#include <iostream>
#include <string>
using namespace std;
string map[500];
bool visit[1000][1000];
int d[1000][1000];

int domino(int r,int c){
	if (r < 0 || c < 0) return 0;
	if (r == 0 && c == 0) return 0;

	if (visit[r][c]){
		return d[r][c];
	}
	visit[r][c] = true;
	d[r][c] = domino(r - 1, c) + domino(r, c - 1) - domino(r-1,c-1);
	if (r & 1 && !(c & 1)){
		d[r][c] += map[r >> 1][c >> 1] == '.'&&map[(r>>1)+1][c >> 1] == '.';
	}
	if (c & 1 && !(r & 1)){
		d[r][c] += map[r >> 1][c >> 1] == '.'&&map[r >> 1][(c >> 1)+1] == '.';
	}
	
	return d[r][c];
}

int main(){
	int i;
	int h, w;
	int q;
	int r1, c1, r2, c2;
	int ans;
	cin >> h >> w;
	for (i = 0; i < h; i++){
		cin >> map[i];
	}
	cin >> q;
	for (i = 0; i < q; i++){
		cin >> r1 >> c1 >> r2 >> c2;
		r1 -= 1;
		r2 -= 1;
		c1 -= 1;
		c2 -= 1;
		r1 <<= 1;
		r2 <<= 1;
		c1 <<= 1;
		c2 <<= 1;
		ans = domino(r2, c2) + domino(r1 - 1, c1 - 1) - domino(r1 - 1, c2) - domino(r2, c1 - 1);
		cout << ans << "\n";
	}
	return 0;
}