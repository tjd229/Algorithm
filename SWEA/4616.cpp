//graph, tp sort, dp

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int ind[300001];
int edge[300001][2];  //-,|
int m[300001][2], e[300001];
int x[300001], y[300001], f[300001];
vector<int> col[100001], row[100001];
int N, K;
void tp_sort(){
    queue<int> q;
    e[1] = f[1];
    q.push(1);
    while (q.size()){
        int curr = q.front();
 
        q.pop();
        for (int i = 0; i < 2; ++i){
            if (edge[curr][i]){
                int to = edge[curr][i];
                m[to][i] = m[curr][i];
                if (e[curr] >= K){
                    e[to] = max(e[to], e[curr] + f[to] - K);
                    m[to][i] = max(e[curr] - K, m[to][i]);
                }
                e[to] = max(e[to], m[curr][i] + f[to]);
                if (0 == (--ind[to])) q.push(to);
            }
        }
    }
}
int main(){
    int i, j;
    int tc, T;
    for (scanf("%d", &T), tc = 1; tc <= T; ++tc){
        for (scanf("%d%d", &N, &K), i = 1; i <= N; i++){
            scanf("%d%d%d", x + i, y + i, f + i);
            edge[i][0] = edge[i][1] = 0;
            m[i][0] = m[i][1] = -2e9;
            e[i] = -2e9;
            ind[i] = 0;
            col[x[i]].push_back(i);
            row[y[i]].push_back(i);
             
        }
        int sx = x[1];
        int sy = y[1];
        for (i = 0; i <= 100000; i++){
            if (col[i].size()){
                sort(col[i].begin(), col[i].end(), [](int a, int b){
                    return y[a] < y[b];
                });
                for (j = 1; j < col[i].size(); j++){
                    if (i>=sx && y[col[i][j - 1]] >= sy ){
                        edge[col[i][j - 1]][1] = col[i][j];
                        ind[col[i][j]]++;
                    }
                }
                col[i].clear();
            }
 
            if (row[i].size()){
                sort(row[i].begin(), row[i].end(), [](int a, int b){
                    return x[a] < x[b];
                });
                for (j = 1; j < row[i].size(); j++){
                    if (i >= sy && x[row[i][j - 1]] >= sx){
                        edge[row[i][j - 1]][0] = row[i][j];
                        ind[row[i][j]]++;
                    }
                }
                row[i].clear();
            }
 
        }
        tp_sort();
        printf("#%d %d\n", tc, e[N]);
 
    }
 
 
    return 0;
}
