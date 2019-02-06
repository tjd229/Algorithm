//implementation
#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
int family[3][3];
int row[9];
int col[9];
int board[9][9];
vector<pii > v;
void print() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%d ", board[i][j]);
		}puts("");
	}
}
bool bf(int ix) {
	if (ix == v.size()) {
		print();
		return 1;
	}
	int y = v[ix].second;
	int x = v[ix].first;
	int X = x / 3;
	int Y = y / 3;
	for (int i = 1; i < 10; ++i) {
		if (0 == (family[Y][X] & (1 << i))
			&& 0 == (row[y] & (1 << i)) && 0 == (col[x] & (1 << i))) {
			board[y][x] = i;
			family[Y][X] |= (1 << i);
			row[y] |= (1 << i);
			col[x] |= (1 << i);
			if (bf(ix + 1)) return 1;
			family[Y][X] -= (1 << i);
			row[y] -= (1 << i);
			col[x] -= (1 << i);
			board[y][x] = 0;
		}
	}
	return 0;
}
int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%d",board[i]+j);
			if (board[i][j]) {
				row[i] |= 1 << board[i][j];
				col[j] |= 1 << board[i][j];
				family[i / 3][j / 3] |= 1 << board[i][j];
			}
			else v.push_back({j,i});
		}
	}
	bf(0);
	return 0;
}