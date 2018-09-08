//graph, dp

#include <vector>
#include <stdio.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
vector<int> edge[100001];
ll d[100001][2];//w,b
 
void dfs(int x, int from){
 
    d[x][0] = d[x][1] = 1;
    if (x != 1 && edge[x].size() == 1)
        return;
 
    int i;
    for (auto to : edge[x]) if (from != to) dfs(to, x);
    for (auto to : edge[x]){
        if (from != to){
            d[x][0] = d[x][0] * (d[to][1] + d[to][0]) % mod;
            d[x][1] = d[x][1] * d[to][0] % mod;
        }
    }
}
int main(){
    int i;
    int tc, T;
    int N;
    int x, y;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        for (scanf("%d", &N), i = 1; i <= N; i++)
            edge[i].clear();
        for (i = 1; i < N; i++){
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        dfs(1, 0);
        printf("#%d %lld\n", tc, (d[1][0] + d[1][1]) % mod);
    }
 
    return 0;
}
