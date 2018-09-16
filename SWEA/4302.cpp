//line sweeping

#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int x[100000], y[100000], nx[100000], ny[100000];
int d[100000];
vector<pii > e[100000]; //ix,effect
int dist(int a, int b){
    int dx = x[a] - x[b];
    if (dx < 0) dx = -dx;
    int dy = y[a] - y[b];
    if (dy < 0) dy = -dy;
    return dx + dy;
}
int main(){
    int i;
    int tc, T;
    int N, W, K;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        vector<int> c;
        vector<pii > v;// nx,ix;
        set<pii > st;// ny,ix
        for (scanf("%d%d%d", &N, &W, &K), i = 0; i < N; i++){
            scanf("%d%d%d",x+i,y+i,d+i);
            e[i].clear();
            nx[i] = x[i] - y[i];
            ny[i] = x[i] + y[i];
            v.push_back({nx[i],i});
        }
        sort(v.begin(), v.end());
        for (auto p : v){
            int r = p.second;
            auto it = st.lower_bound({ ny[r]-10, 0 });
            while (it != st.end()){
                int l = it->second;
                if (ny[l] > ny[r] + 10) break;
                if (nx[l] < nx[r] - 10){
                    st.erase(it++);
                }
                else{
                    int eft = 10/dist(l,r);
                    e[l].push_back({r,eft});
                    e[r].push_back({ l, eft });
                    ++it;
                }
            }
            st.insert({ny[r],r});
            if (d[r] > 0 && d[r] - K <= 0) c.push_back(r);
            d[r] -= K;
        }
        for (i = 0; i < c.size();i++){
            int b = c[i];
            for (auto p : e[b]){
                int adj = p.first;
                int eft = p.second;
                if (d[adj] > 0 && d[adj] - eft <= 0)
                    c.push_back(adj);
                d[adj] -= eft;
            }
        }
        printf("#%d %d\n",tc,N-c.size());
    }
 
 
    return 0;
}
