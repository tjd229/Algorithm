//category : graph, LCA

#include <stdio.h>
#include <vector>
using namespace std;
int depth[100001];
int p[100001][18];
bool visit[100001];
vector<int> edge[100001];
void dfs(int ix){
    visit[ix] = true;
    for (int i = 0; i < edge[ix].size(); i++){
        if (!visit[edge[ix][i]]){
            depth[edge[ix][i]] = depth[ix] + 1;
            p[edge[ix][i]][0] = ix;
            dfs(edge[ix][i]);
        }
    }
}
int search(int a,int b){
    if (a == b) return a;
    int k = 1 << 17;
    int j = 17;
    for (; j >= 0; j--, k >>= 1){
        //if (depth[a] < k) continue;
        if (p[a][j] != p[b][j]){
            a = p[a][j];
            b = p[b][j];
        }
    }
    a = p[a][0];
    
    
    return a;
}
int climb(int n,int d){
    int k = 0;
    while (d != 0){
        if (d & 1) n = p[n][k];
        k++;
        d >>= 1;
    }
    return n;
}
int main(){
    int i,j,k;
    int N, M;
    int u, v;
    scanf("%d",&N);
    for (i = 0; i < N - 1; i++){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1);
    for (j = 1, k = 2; j < 18; j++, k <<= 1){
        for (i = 1; i <= N; i++){
            //if (depth[i] < k) break;
            p[i][j] = p[p[i][j-1]][j - 1];
        }
    }
    for (scanf("%d", &M); M--;){
        scanf("%d%d", &u, &v);
        if (depth[u] < depth[v]) v = climb(v, depth[v] - depth[u]);
        if (depth[u] > depth[v]) u = climb(u, depth[u] - depth[v]);
        printf("%d\n",search(u,v));
    }
    
    
    
    return 0;
}
