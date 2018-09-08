//graph, MST, djs

#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
double E;
int N;
int p[1001];
int X[1001], Y[1001];
struct Edge{
    int u, v;
    double cost;
    bool operator<(Edge e) const{
        return cost < e.cost;
    }
}edge[1000*1000];
int find(int a){
    if (a != p[a])p[a] = find(p[a]);
    return p[a];
}
bool join(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    p[b] = a;
    return true;
}
int main(){
    int i,j;
    int C, T;
    //freopen("input.txt","r",stdin);
    for (scanf("%d", &T), C = 1; C <= T; C++){
        for (scanf("%d", &N), i = 1; i <= N; i++){
            scanf("%d",X+i);
            p[i] = i;
        }
        for (i = 1; i <= N; i++) scanf("%d",Y+i);
        int cnt = 0;
        int num_e = 0;
        double ans = 0;
        for (scanf("%lf", &E), i = 1; i <= N; ++i){
            for (j = i + 1; j <= N; j++){
                ll dx = X[i] - X[j];
                ll dy = Y[i] - Y[j];
                edge[num_e++] = { i, j, E*(dx*dx + dy*dy) };
            }
        }
        sort(edge, edge + num_e);
        for (i = 0; i < num_e; i++){
             
            if (cnt == N - 1) break;
            if (join(edge[i].u, edge[i].v)){
                ++cnt;
                ans += edge[i].cost;
            }
        }
        //return 0;
        printf("#%d %.0f\n",C,ans);
    }
 
    return 0;
}
