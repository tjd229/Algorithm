//graph

#include <stdio.h>
#include <vector>
using namespace std;
int p[10001];
int visit[10001];
vector<int> edge[10001];
int dfs(int x){
    int res = 1;
    for (auto v : edge[x]) res += dfs(v);
    return res;
}
int main(){
    int i;
    int x, T;
    int V, E, n1, n2;
    int u, v;
    for (scanf("%d", &T), x = 1; x <= T; x++){
        for (scanf("%d%d%d%d", &V, &E, &n1, &n2),i=1; i <=V; i++){
            edge[i].clear();
        }
        for (i = 0; i < E; i++){
            scanf("%d%d",&u,&v);
            p[v] = u;
            edge[u].push_back(v);
        }
        while (n1){
            visit[n1] = x;
            n1 = p[n1];
        }
        while (visit[n2] != x) n2 = p[n2];
        printf("#%d %d %d\n",x,n2,dfs(n2));
    }
     
 
    return 0;
}
