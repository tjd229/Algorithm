//category : ft

#include <stdio.h>
#define BI (1<<10)
int ft[BI + 1][BI+1];
void update(int x,int y,int diff){
	int y_;
	while (x <= BI){
		y_ = y;
		while (y_ <= BI){
			ft[x][y_] += diff;
			y_ += (y_&-y_);
		}
		x += (x&-x);
	}
}
int rangeSum(int x,int y){
	int s = 0;
	int y_;
	while (x != 0){
		y_ = y;
		while (y_ != 0){
			s += ft[x][y_];
			y_ -= (y_&-y_);
		}
		x -= (x&-x);
	}
	return s;
}
int sum(int x1, int y1, int x2, int y2){
	return rangeSum(x2, y2) + rangeSum(x1, y1) - rangeSum(x2, y1) - rangeSum(x1, y2);
}
int main(){
	int N, M;
	int i, j;
	int w, x, y, c;
	scanf("%d%d",&N,&M);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++) scanf("%d",&w),update(i,j,w);
	}
	
	do{
		scanf("%d",&w);
		if (w == 1){
			scanf("%d%d%d%d", &x, &y, &c,&w);
			printf("%d\n",sum(x-1,y-1,c,w));
		}
		else if (w == 0){
			scanf("%d%d%d",&x,&y,&c);
			update(x, y, c - sum(x-1,y-1,x,y));
		}
	} while (--M);
	return 0;
}
