//implementation
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
const int ori = 123456;
int a[20], b[20];
int to[7];
void swap(int &a, int &b){ a ^= b ^= a ^= b; }
int main(){
    int i;
    int tc, T;
    int M;
    ll K;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        int card[7][2];
        vector<int> v;
        v.push_back(ori);
        scanf("%d%lld", &M, &K);
        for (i = 0; i < 7; i++) card[i][0] = i;
        for (i = 0; i < M; i++){
            scanf("%d%d", a + i, b + i);
            --a[i];
            --b[i];
            swap(card[a[i]][0],card[b[i]][0]);
        }
        int perm = 0;
        for (i = 0; i < 7; i++){
            to[card[i][0]] = i;
            perm *= 10;
            perm += card[i][0];
        }
        int t = 0;
        while (perm!=ori){
            v.push_back(perm);
            for (perm = 0, i = 0; i < 7; i++)
                card[to[i]][t ^ 1] = card[i][t];
            for (t^=1,i = 0; i < 7; i++){
                perm *= 10;
                perm += card[i][t];
            }
        }
        ll k = K / M;
        perm = v[k%v.size()];
        K %= M;
        for (i = 6; i>=0; --i, perm /= 10) card[i][0] = perm % 10;
        for (i = 0; i < K; i++) swap(card[a[i]][0],card[b[i]][0]);
        printf("#%d ",tc);
        for (i = 0; i < 7; i++) printf("%d",card[i][0]);
        puts("");
    }
 
    return 0;
}
