//implementation

#include <stdio.h>
int map[102][102];
int main(){
    int i, j;
    int tc;
    int cx, cy;
    for (tc = 1; tc <= 10; tc++){
        for (scanf("%d", &tc), i = 1; i <= 100; i++){
            for (j = 1; j <= 100; j++){
                scanf("%d",&map[i][j]);
            }
        }
        int mn = 1e9;
        int ans = 0;
        for (i = 1; i <= 100; i++){
            if (map[1][i]){
                cx = i;
                cy = 1;
                int len = 1;
                while (cy < 100){
                    if (map[cy][cx - 1] == 1){
                        while (map[cy][cx - 1] == 1) --cx,++len;
                    }
                    else if (map[cy][cx + 1] == 1){
                        while (map[cy][cx + 1] == 1) ++cx,++len;
                    }
                    ++cy;
                    ++len;
                }
                if (mn > len) mn = len, ans = i - 1;
                 
            }
        }
        printf("#%d %d\n",tc,ans);
    }
 
    return 0;
}
