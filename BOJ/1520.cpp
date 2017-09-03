//category : graph

#include <stdio.h>

int map[501][501];
int d[501][501];
int c[501][501];
int N,M;
int path(int x,int y){
    if(c[y][x]==1) return d[y][x];
    if(x==N&&y==M) return 1;
    c[y][x]=1;
    if(x>1&&map[y][x]>map[y][x-1]) d[y][x]+=path(x-1,y);
    if(x<N&&map[y][x]>map[y][x+1]) d[y][x]+=path(x+1,y);
    if(y>1&&map[y][x]>map[y-1][x]) d[y][x]+=path(x,y-1);
    if(y<M&&map[y][x]>map[y+1][x]) d[y][x]+=path(x,y+1);
    return d[y][x];
}
int main(){
    int i,j;
    scanf("%d%d",&M,&N);
    for(i=1;i<=M;i++) for(j=1;j<=N;j++) scanf("%d",&map[i][j]);
    printf("%d",path(1,1));
    return 0;
}