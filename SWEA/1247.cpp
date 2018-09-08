//dp

#include <stdio.h>
int d[1 << 10][10];
int cx, cy, hx, hy;
int x[10], y[10];
int dist(int x1, int y1, int x2, int y2){
    int dx = x1 - x2;
    int dy = y1 - y2;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    return dx + dy;
}
int min(int a, int b){ return a < b ? a : b; }
int main(){
    int i,j,k;
    int tc, T;
    int N;
    for (scanf("%d", &T), tc= 1; tc <= T;tc++){
        for (scanf("%d%d%d%d%d", &N, &cx, &cy, &hx, &hy), i = 0; i < N; i++)
            scanf("%d%d",x+i,y+i);
        int bnd = 1 << N;
        for (i = 0; i < bnd; i++) for (j = 0; j < N; j++) d[i][j] = 1e9;
        for (i = 0, j = 1; i < N; i++,j<<=1) d[j][i] = dist(cx, cy, x[i], y[i]);
        for (i = 0; i < bnd; i++){
            for (j = 0; j < N; j++){
                if ((i & (1 << j)) == 0) continue;
                for (k = 0; k < N; k++){
                    if ((i&(1 << k))==0){
                        int nxt = i + (1 << k);
                        d[nxt][k] = min(d[nxt][k], d[i][j] + dist(x[j], y[j], x[k], y[k]));
                    }
                }
            }
        }
        int ans = 1e9;
        for (i = 0; i < N; i++) ans = min(ans, d[bnd - 1][i] + dist(x[i], y[i], hx, hy));
        printf("#%d %d\n",tc,ans);
    }
 
    return 0;
}
