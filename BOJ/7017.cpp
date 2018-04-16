//category : implementation

#include <stdio.h>
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int side[6][4] = {
	{ 2, 3, 5, 4 },
	{ 1, 4, 6, 3 },
	{ 1, 2, 6, 5 },
	{ 1, 5, 6, 2 },
	{ 1, 3, 6, 4 },
	{ 2, 4, 5, 3 },
};


int main(){
	int i,j;
	int n;
	int cx, cy;
	scanf("%d",&n);
	while (n){
		int t, f;
		int h[200][200] = { 0 };
		int d[200][200][100] = { 0 };
		int counts[7] = { 0 };
		while (n--){
			scanf("%d%d",&t,&f);

			cx = cy = 100;
			d[cy][cx][h[cy][cx]++] = t;
			bool flag = true;
			while (flag){
				flag = false;
				int s = 0;
				while (side[t-1][s] != f) s++;
				for (i = 6; i > 3; --i){
					if (i == t || 7 - i == t) continue;
					j = 0;
					while (side[t-1][(s + j) % 4] != i) j++;
					if (h[cy][cx] - 1 > h[cy + dy[j]][cx + dx[j]]){
						if (0==(j & 1) )
							f = j ? 7 - t : t;
						t = 7 - i;
						h[cy][cx]--;

						cy += dy[j];
						cx += dx[j];
						int &up = h[cy][cx];
						d[cy][cx][up++] = t;
						flag = true;
						break;						
					}
				}
			}
			/*printf("%d,%d,%d,%d\n", cx, cy, d[cy][cx][h[cy][cx] - 1], h[cy][cx] - 1);*/
		}
		for (i = 0; i < 200; i++){
			for (j = 0; j < 200; j++){
				counts[d[j][i][h[j][i] - 1]]++;
			}
		}
		for (i = 1; i <= 6; i++) printf("%d ",counts[i]);
		printf("\n");
		scanf("%d",&n);
	}

	return 0;
}
