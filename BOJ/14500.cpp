//category : implementation

#include <stdio.h>
struct Tetro{
	int w, h;
	int block[4][4];
}t;
int map[500+4][500+4];
int N, M;
int X[19][5] = {
	{4, 0, 1, 2, 3 },
	{1, 0, 0, 0, 0 },
	{2, 0, 1, 0, 1 },

	{2, 0, 0, 0, 1 },
	{3, 0, 1, 2, 0 },
	{2, 0, 1, 1, 1 },
	{3, 2, 0, 1, 2 },
	{2, 1, 1, 1, 0 },
	{3, 0, 1, 2, 2 },
	{2, 0,1,0,0 },
	{3, 0, 0, 1, 2 },

	{2, 0, 0, 1, 1 },
	{3, 1, 2, 0, 1 },
	{2, 1, 0, 1, 0 },
	{3, 0, 1, 1, 2 },

	{3, 0, 1, 2, 1 },
	{2, 1, 0, 1, 1 },
	{3, 1, 0, 1, 2 },
	{2, 0, 0, 1, 0 },

};
int Y[19][5] = {
	{1, 0, 0,0,0 },
	{4, 0, 1,2,3 },
	{2, 0, 0,1,1 },

	{3, 0,1,2,2 },
	{2, 0, 0,0,1 },
	{3, 0, 0,1,2 },
	{2, 0,1,1,1 },
	{3,0,1,2,2 },
	{2, 0, 0,0,1 },
	{3, 0, 0, 1,2 },
	{2, 0, 1,1,1 },

	{3, 0, 1,1,2 },
	{2, 0,0,1,1 },
	{3, 0,1,1,2},
	{2, 0, 0,1,1 },

	{2, 0, 0,0,1 },
	{3, 0,1,1,2 },
	{2, 0,1,1,1 },
	{3, 0, 1,1,2 },

};
int search(Tetro t){
	int i, j,k,l;
	int res = 0;
	int curr;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			curr = 0;
			for (k = 0; k < t.h; k++){
				for (l = 0; l < t.w; l++){
					curr += t.block[k][l] * map[i+k][j+l];
				}
			}
			if (res < curr) res = curr;
		}
	}
	return res;
}
int main(){
	int i, j;
	for (scanf("%d%d", &N, &M), i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			scanf("%d",&map[i][j]);
		}
	}
	int ans=0;
	int s;
	
	for (i = 0; i < 19; i++){
		t.w = X[i][0];
		t.h = Y[i][0];
		for (j = 1; j < 5; j++)
			t.block[Y[i][j]][X[i][j]] = 1;
		s = search(t);
		if (ans < s) ans = s;
		for (j = 1; j < 5; j++)
			t.block[Y[i][j]][X[i][j]] = 0;
	}
	printf("%d",ans);
	return 0;
}
