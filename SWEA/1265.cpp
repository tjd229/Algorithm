//math

#include <stdio.h>
 
int main(){
    int i;
    int x, T;
    for (scanf("%d", &T), x = 1; x <= T; ++x){
        int N, P;
        scanf("%d%d",&N,&P);
        int d = N / P;
        int r = N%P;
        long long ans = 1;
        for (i = 0; i < r; i++) ans *= d + 1;
        for (i = 0; i < P - r; i++) ans *= d;
        printf("#%d %lld\n",x,ans);
    }
    return 0;
}
