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
                if (map[i][j] == 2) cx = j, cy = i;
            }
        }
        while (cy > 1){
            if (map[cy][cx - 1] == 1){
                while (map[cy][cx - 1] == 1) --cx;
            }
            else if (map[cy][cx + 1] == 1){
                while (map[cy][cx + 1] == 1) ++cx;
            }
            --cy;
        }
        printf("#%d %d\n",tc,cx-1);
    }
 
    return 0;
}
