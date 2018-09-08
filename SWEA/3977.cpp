//math

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
bool prime[1000001];
bool bsq[1000001];
vector<int> candi;
vector<int> sq;
vector<int> fprime;
int main(){
    int i, j;
    for (i = 2; i <= 1000000; ++i) prime[i] = true;
    sq.push_back(1);
    bsq[1] = 1;
    for (i = 2; i <= 1000000; i++){
        ll sqv = (ll)i*i;
        if (sqv <= 1000000) sq.push_back(sqv), bsq[sqv] = 1;
        if (prime[i] == false) continue;
        //if (i%4==1)
            candi.push_back(i);
        for (j = (i<<1); j <= 1000000; j += i){
            prime[j] = false;
        }
    }
 
    for (auto p : candi){
        for (auto sqv : sq){
            if (p-sqv<sqv) break;
            if (bsq[p - sqv]){
                fprime.push_back(p);
                break;
            }
        }
    }
    int T, tc;
    int L, R;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        scanf("%d%d",&L,&R);
        printf("#%d %d\n",tc,upper_bound(fprime.begin(),fprime.end(),R)
            -lower_bound(fprime.begin(),fprime.end(),L));
    }
     
    return 0;
}
