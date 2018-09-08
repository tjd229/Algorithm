//graph

#include <stdio.h>
#include <memory.h>
const int dest = 99;
int edge[100][2];
int visit[100];
void dfs(int x,int stamp){
    if (visit[x] == stamp) return;
    visit[x] = stamp;
    for (int i = 0; i < 2; i++) if (edge[x][i]) dfs(edge[x][i], stamp);
}
int main(){
    int i,j;
    int tc;
    int E;
    int u, v;
    while (scanf("%d%d",&tc,&E) == 2){
        for (i = 0; i < E; i++){
            scanf("%d%d",&u,&v);
            j = 0;
            while (edge[u][j])++j;
            edge[u][j] = v;
        }
        dfs(0, tc);
        printf("#%d %d\n",tc,visit[dest]==tc);
        memset(edge, 0, sizeof(edge));
    }
    return 0;
}
