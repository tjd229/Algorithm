//category : geometry


#include <stdio.h>
#include <memory.h>

int s[2001][2001];
int dx, dy, n, q;
int bound;
int range_sum(int x1,int y1,int x2,int y2){
	if (x1 < 1) x1 = 1;
	if (y1 < 1) y1 = 1;
	if (x2 > bound) x2 = bound;
	if (y2 > bound) y2 = bound;
	x1--; y1--;
	return s[y2][x2] - s[y2][x1] - s[y1][x2] + s[y1][x1];
}
int main(){
	int i, j;
	int tc = 1;
	int x, y;
	int m;
	int ans[3] = { 0 };
	int res;
	while (scanf("%d%d%d%d", &dx, &dy, &n, &q)){
		if (dx + dy + n + q == 0) break;
		memset(s,0,sizeof(s));
		while (n--){
			scanf("%d%d",&x,&y);
			s[x + y][x - y + dy]++;
		}
		bound = dx + dy;
		for (i = 1; i <= bound; i++){
			for (j = 1; j <= bound; j++){
				s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			}
		}
		printf("Case %d:\n",tc++);
		while (q--){
			scanf("%d",&m);
			ans[0] = 0;
			ans[1] = ans[2] = 1;
			for (i = 1; i <= dy; i++){
				for (j = 1; j <= dx; j++){
					y = i + j;
					x = j - i + dy;
					res = range_sum(x-m,y-m,x+m,y+m);
					if (ans[0] < res){
						ans[0]=res;
						ans[1] = j;
						ans[2] = i;
					}
				}
			}
			printf("%d (%d,%d)\n",ans[0],ans[1],ans[2]);
		}

	}
	return 0;
}