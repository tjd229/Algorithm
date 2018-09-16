//math

#include <stdio.h>
int y[10001], x[10001];
int main(){
    int i, j;
    int col = 1;
    for (i = j = 1; i <= 10000; i++){
        x[i] = col++;
        y[i] = j;
        if (j < col) col = 1, ++j;
    }
    int tc, T;
    int a, b;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        scanf("%d%d",&a,&b);
        if (a>b) a ^= b ^= a ^= b;
        printf("#%d ",tc);
        if (y[a] == y[b]) printf("%d\n",x[b]-x[a]);
        else if (x[a] > x[b]){
            printf("%d\n", x[a] - x[b]+y[b]-y[a]);
        }
        else{
            col = x[a] + y[b] - y[a];
            //printf("%d\n", col >= x[b] ? y[b] - y[a] : x[b] - col + y[b] - y[a]);
            printf("%d\n", col >= x[b] ? y[b] - y[a] : x[b] - x[a]);
        }
    }
 
    return 0;
}
