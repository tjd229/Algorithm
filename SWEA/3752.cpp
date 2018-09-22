//dp

#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
bool d[10001][101];
int visit[10001][101];
int pt[101];
int cnt[101];
int tc;
vector<int> card;
bool test(int p,int cix){
    if (p == 0) return true;
    else if (p < 0 || cix<0) return false;
    if (visit[p][cix] == tc) return d[p][cix];
    visit[p][cix] = tc;
 
    d[p][cix] = false;
    for (int i = 0; i <= cnt[card[cix]] && !d[p][cix]; i++) d[p][cix] |= test(p - i*card[cix], cix - 1);
     
    return d[p][cix];
     
}
int main(){
    int i;
    int T;
    int N;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        memset(d, 0, sizeof(d));
        memset(cnt, 0, sizeof(cnt));
        card.clear();
        int tot = 0;
        int mx = 0;
        int mn = 101;
        int ans = 1;
        for (scanf("%d", &N), i = 0; i < N; i++){
            scanf("%d",pt+i);
            tot += pt[i];
            cnt[pt[i]]++;
            if (mx < pt[i]) mx = pt[i];
            if (mn > pt[i]) mn = pt[i];
        }
        for (i = mn; i <= mx; ++i){
            if (cnt[i]) card.push_back(i);
        }
        for (; tot>=mn; --tot) ans += test(tot, card.size()-1);
        printf("#%d %d\n",tc,ans);
    }
 
    return 0;
}
