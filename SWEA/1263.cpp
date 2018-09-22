//graph

#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
int inq[1000];
int stamp=1;
int main(){
    int i,j;
    int x, T;
    int N;
    for (scanf("%d", &T), x = 1; x <= T; ++x){
        int e;
        vector<int> edge[1000];
        for (scanf("%d", &N), i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                scanf("%d",&e);
                if (e) edge[i].push_back(j);
            }
        }
        int ans = 1000 * 1000;
        for (i = 0; i < N; i++,++stamp){
            int dist = 0;
            queue<pii > q;
            q.push({i,0});
            inq[i] = stamp;
            while (q.size()){
                int curr = q.front().first;
                int d= q.front().second;
                dist += d;
                q.pop();
                for (auto to : edge[curr]){
                    if (inq[to] != stamp){
                        inq[to] = stamp;
                        q.push({to,d+1});
                    }
                }
            }
            if (ans > dist) ans = dist;
        }
        printf("#%d %d\n",x,ans);
    }
    return 0;
}
