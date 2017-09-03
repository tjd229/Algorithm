//category : bs, greedy

#include <stdio.h>
int R, C, A, B;
int cc[501][501];
int s[501][501];
int sum(int from_x, int from_y, int to_x, int to_y){
	return s[to_y][to_x] - s[to_y][from_x-1] - s[from_y-1][to_x] + s[from_y-1][from_x-1];
}
bool v_cut(int mine,int last_row,int row){
	int b = 0;
	int last_x = 1;
	int i;
	for (i = 1; i < C; i++){
		if (sum(last_x, last_row, i, row) >= mine){
			last_x = i+1;
			b++;
		}
		if (b == B-1) return sum(last_x,last_row,C,row)>=mine;
	}
	return false;
}
bool h_cut(int mine){
	int a = 0;
	int last_y = 1;
	int i;
	for (i = 1; i < R; i++){
		if (v_cut(mine, last_y, i)){
			last_y = i+1;
			a++;
		}
		if (a == A-1) return v_cut(mine,last_y,R);
	}
	return false;
}
int main(){
	int i, j;
	int l, r, m;
	int ans = 0;
	l = r = 0;
	//freopen("i.txt","r",stdin);
	scanf("%d%d%d%d",&R,&C,&A,&B);
	for (i = 1; i <= R; i++){
		for (j = 1; j <= C; j++){
			scanf("%d",&s[i][j]);
			s[i][j] += s[i][j] - sum(j , i, j, i);
		}
	}
	r = s[R][C];
	while (l<=r){
		m = (l + r) >> 1;
		if (h_cut(m)){
			ans = m;
			l = m + 1;
			
		}
		else r = m - 1;
	}
	printf("%d",ans);

	return 0;
}