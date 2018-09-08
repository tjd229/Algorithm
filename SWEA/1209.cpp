//implementation
#include <stdio.h>
int map[100][100];
int ysum[100];
int main(){
    int i, j;
    int tc;
    for (tc = 1; tc <= 10; ++tc){
        scanf("%d",&tc);
        int ans = 0;
        for (i = 0; i < 100; i++){
            int xsum = 0;
            for (j = 0; j < 100; j++){
                scanf("%d",&map[i][j]);
                ysum[j]+=map[i][j];
                xsum += map[i][j];
            }
            if (ans < xsum) ans = xsum;
        }
        for (i = 0; i < 100; i++){
            if (ans < ysum[i]) ans = ysum[i];
            ysum[i] = 0;
        }
        int csum = 0;
        for (i = 0; i < 100; i++) csum += map[i][j];
        if (ans < csum) ans = csum;
        csum = 0;
        for (i = 0; i < 100; i++) csum += map[99-i][j];
        if (ans < csum) ans = csum;
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}
