//dp

#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
int fix[100001], var[100001];
ll d[100001][3]; //0: fix, 1:var, 2:var[-1]
int main(){
    int i;
    int tc, T;
    int N;
    d[0][0] = 1;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        for (scanf("%d", &N), i = 1; i <= N; i++) scanf("%d", fix + i), d[i][0] = d[i][1] = d[i][2] = 0;
        for (i = 1; i < N; i++) scanf("%d", var + i);
        var[N] = 0;
        for (i = 1; i <= N; i++){
            d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) * fix[i] % mod;
            d[i][1] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) * var[i] % mod;
            d[i][2] = (d[i - 1][0] + d[i - 1][2])*var[i - 1] % mod;
             
            if (var[i - 1]>1)
                d[i][2] += (d[i - 1][1]) * (var[i - 1] - 1) % mod;
            d[i][2] %= mod;
        }
        printf("#%d %lld\n", tc, (d[N][0] + d[N][1] + d[N][2]) % mod);
    }
 
    return 0;
}
