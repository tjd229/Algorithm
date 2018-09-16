//math

#include <stdio.h>
#define ll long long
ll combi[13][13];
ll p9[13];
ll f4[13];
ll nCk(int n, int k){
    if (n == 1 || k == 0 || k==n) return 1;
    if (combi[n][k] == 0){
        combi[n][k] = nCk(n - 1, k) + nCk(n - 1, k - 1);
    }
    return combi[n][k];
}
ll to1(ll f){
    if (f < 0) f = -f;
    if (f < 4) return 0;
    else if (f < 10) return 1;
    int b = 0;
    ll d = 1;
    ll last = f;
    ll r = f % 10;
    ll res = 0;
    f /= 10;
    while (f){
        res += to1(r*d);
        last = f;
        ++b;
        d *= 10;
        r = f % 10;
        f /= 10;
    }
    while (last > 0){
        if (last == 5) res += d;
        else res+= f4[b];
        --last;
    }
    return res;
}
int main(){
    int i,j;
    int tc, T;
    ll A, B;
     
    for (p9[0] = i = 1; i <= 12; i++) p9[i] = p9[i - 1] * 9;
    for (i = 1; i <= 12; i++){
        f4[i] = 1;
        for (j = 1; j < i; j++) f4[i] += nCk(i,j) * p9[i-j];
    }
    //printf("%lld\n",to1(400));
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        scanf("%lld%lld",&A,&B);
        ll cnta = to1(A);
        ll cntb = to1(B);
        printf("#%d ",tc);
        if (B < 0) printf("%lld\n",B-A-(cnta-cntb));
        else if (A>0) printf("%lld\n",B-A-(cntb-cnta));
        else printf("%lld\n",B-1-cntb-1-A-cnta+1);
    }
 
    return 0;
}
