//implementation
#include <stdio.h>
int grid[51][51];
int e[2];
int ask(int x1,int y1,int x2,int y2) {
	printf("? %d %d %d %d\n",x1,y1,x2,y2); fflush(stdout);
	int path; scanf("%d",&path);
	return path;
}
bool pattern_chk(int x1, int y1, int x2, int y2) {
	int pattern[6] = { grid[x1][y1],grid[x1 + 1][y1 + 1],0,
	grid[x1 + 1][y1],grid[x1][y1 + 1],grid[x2][y2] };
	if (x1 + 1 == x2)
		pattern[2] = grid[x1][y2];
	else pattern[2] = grid[x2][y1];
	if (pattern[0] == pattern[1] && pattern[2] == pattern[0]
		&& pattern[3] == pattern[4] && pattern[3] != pattern[5])
		return 0;
	if (pattern[3] == pattern[4] && pattern[4] == pattern[5]
		&& pattern[1] == pattern[2] && pattern[1] != pattern[0])
		return 0;
	int path = ask(x1, y1, x2, y2);
	if ((x1 + y1) & 1) {//even coord
		int tgt = grid[x1][y1];
		int src = grid[x2][y2];
		e[tgt] = path ? src : 1 - src;
		e[1 - tgt] = 1 - e[tgt];
	}
	else {
		int src = grid[x1][y1];
		int tgt = grid[x2][y2];
		e[tgt] = path ? src : 1 - src;
		e[1 - tgt] = 1 - e[tgt];
	}
	return 1;
}
int main() {
	int i, j;
	int n; scanf("%d",&n);
	grid[1][1] = 1;
	grid[2][2] = ask(1, 1, 2, 2);
	//even coord
	grid[3][2] = !ask(2, 1, 3, 2);// if(1) 0,0 else 0,1
	grid[1][2] = ask(1, 2, 3, 2) ? grid[3][2] : 1-grid[3][2];
	for (j = 3; j <= n; ++j)
		grid[j][1] = ask(j - 2, 1, j, 1) ? grid[j-2][1] : 1 - grid[j-2][1];
	for (j = 4; j <= n; ++j)
		grid[j][2] = ask(j - 2, 2, j, 2) ? grid[j-2][ 2] : 1 - grid[j-2][2];
	for (i = 3; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (i + j == n + n) continue;
			grid[j][i] = ask(j, i - 2, j, i) ? grid[j][i-2] : 1 - grid[j][i-2];
		}
	}
	
	for (i = 1; i <= n && e[1] + e[0] == 0; ++i) {
		for (j = 1; j <= n &&e[1]+e[0]==0; ++j) {
			if (i + 2 <= n && j + 1 <= n) {
				if (pattern_chk(i, j, i + 2, j + 1))
					break;
			}
			if (i + 1 <= n && j + 2 <= n)
				pattern_chk(i,j,i+1,j+2);			
		}
	}
	for (printf("!\n"), i = 1; i <= n; ++i) {//x
		for (j = 1; j <= n; ++j) {//y
			if ((i + j) & 1) grid[i][j] = e[grid[i][j]];
			printf("%d",grid[i][j]);
			//if (ans[i][j] != grid[i][j]) printf("xx");
		}printf("\n");
	}fflush(stdout);
	return 0;
}