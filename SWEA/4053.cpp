//greedy

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define pli pair<ll, int>
using namespace std;
int c[100001];
ll make[100001];
ll A[100001];
int D[100001];
int main(){
    int i;
    int TC, tc;
    int N, Q;
    ll T;
    //freopen("i.txt","r",stdin);
    for (scanf("%d", &TC), tc = 1; tc <= TC; tc++){
        vector<ll> g;
        for (scanf("%d%lld%d", &N, &T, &Q), i = 1; i <= N;i++){
            scanf("%lld%d",A+i,D+i);
            make[i] = 0;
        }
        for (i = 2; i <= N; i++){
            if (D[i - 1] == 1 && D[i] == 2){
                ll l = A[i - 1] + T;
                ll r = A[i] - T;
                if (l >= r){
                    c[i - 1] = c[i] = tc;
                    make[i - 1] = make[i] = (A[i - 1] + A[i]) >> 1;
                    g.push_back(make[i]);
                }
            }
        }
        for (i = 1; i <= N; i++){
            if (c[i] !=tc){
                if (D[i] == 1){
                    auto it = lower_bound(g.begin(),g.end(),A[i]);
                    if (it!=g.end()&&*it <= A[i] + T) make[i] = *it,c[i]=tc;
                }
                else{
                    auto it = lower_bound(g.begin(), g.end(), A[i]);
                    if (g.begin() !=it){
                        ll pos = *(--it);
                        if (pos >= A[i] - T) make[i] = pos,c[i]=tc;
                    }
                }
            }
        }
        printf("#%d",tc);
        while (Q--){
            int X;
            scanf("%d",&X);
            if (tc==c[X]) printf(" %lld",make[X]);
            else printf(" %lld",D[X]==1? A[X]+T:A[X]-T);
        }puts("");
    }
 
    return 0;
}
