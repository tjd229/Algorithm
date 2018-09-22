//math, line sweeping

#include <stdio.h>
#define ll long long
ll sigma(ll x){
    if (x <= 0) return 0;
    ll res = x*(x + 1);
    //printf("%lld\n",res>>1);
    return res >> 1;
}
int main(){
    int i;
    int tc, T;
    int P, Q, B, G, W;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        scanf("%d%d%d%d%d",&P,&Q,&B,&G,&W);
 
        ll ans = -1;
        int l = 0;
        int r = G - 1;
        while (l < G){
            ll cnt = sigma(l) + sigma(r);
            if (r >= Q){
                cnt += (r - Q + 1LL) * W;
                cnt += sigma(W - 1);
            }
            else{
                int half = W - (W >> 1) - 1;
                if (half > Q - r - 1) half = Q - r - 1;
                cnt += sigma(half) + sigma(W - half - 1);
            }
            if (l >= P){
                cnt += (l - P + 1LL)*B;
                cnt += sigma(B - 1);
            }
            else{
                int half = B - (B >> 1) - 1;
                if (half > P - l - 1) half = P - l - 1;
                cnt += sigma(half) + sigma(B - half - 1);
            }
            if (ans<0 || ans>cnt) ans = cnt;
            ++l;
            --r;
        }
        l = 0;
        r = B - 1;
        while (l < B){
            ll cnt = sigma(l) + sigma(r);
            int cpos = 0;
            if (r >= P){
                cnt += (r - P + 1LL)*G;
                cnt += sigma(G - 1);
                cpos = r - P + G;
            }
            else{
                int half = G - (G >> 1) - 1;
                if (half > P - r - 1) half = P - r - 1;
                cnt += sigma(half) + sigma(G - half - 1);
                cpos = G - half - 1;
            }
            if (cpos >= Q){
                cnt += (cpos - Q + 1LL) * W;
                cnt += sigma(W - 1);
            }
            else{
                int half = W - (W >> 1) - 1;
                if (half > Q - cpos - 1) half = Q - cpos - 1;
                cnt += sigma(half) + sigma(W - half - 1);
            }
            if (ans<0 || ans>cnt) ans = cnt;
            ++l;
            --r;
        }
        l = 0;
        r = W - 1;
        while (l < W){
            ll cnt = sigma(l) + sigma(r);
            int cpos = 0;
            if (l >= Q){
                cnt += (l - Q + 1LL)*G;
                cnt += sigma(G - 1);
                cpos = l - Q + G;
            }
            else{
                int half = G - (G >> 1) - 1;
                if (half > Q - l - 1) half = Q - l - 1;
                cnt += sigma(half) + sigma(G - half - 1);
                cpos = G - half - 1;
            }
            if (cpos >= P){
                cnt += (cpos - P + 1LL) * B;
                cnt += sigma(B - 1);
            }
            else{
                int half = B - (B >> 1) - 1;
                if (half > P - cpos - 1) half = P - cpos - 1;
                cnt += sigma(half) + sigma(B - half - 1);
            }
            if (ans<0 || ans>cnt) ans = cnt;
            ++l;
            --r;
        }
        printf("#%d %lld\n",tc,ans);
         
    }
 
    return 0;
}
