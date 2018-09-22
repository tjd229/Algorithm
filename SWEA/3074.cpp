//bs

#include <stdio.h>
#define ll long long
int t[100000];
int main(){
    int i;
    int tc, T;
    int N, M;
    for (scanf("%d", &T), tc = 1; tc <= T; ++tc){
        for (scanf("%d%d", &N, &M), i = 0; i < N; i++)
            scanf("%d", t + i);
        ll l = 1;
        ll r = 1e18;
        while (l <= r){
            ll pass = 0;
            ll m = (l + r)/2;
            for (i = 0; i < N; i++) pass += m / t[i];
            if (pass >= M) r = m - 1;
            else l = m + 1;
        }
        printf("#%d %lld\n", tc, r + 1);
    }
 
    return 0;
}
