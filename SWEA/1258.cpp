//implementation

#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Mat{
    int r,c, rc;
    bool operator<(const Mat &m)const{
        if (m.rc == rc) return r < m.r;
        return rc < m.rc;
    }
};
int e[102][102];
int main(){
    int i, j;
    int x, T;
    int n;
    for (scanf("%d", &T), x = 1; x <= T; ++x){
        memset(e, 0, sizeof(e));
        vector<Mat> ans;
        for (scanf("%d", &n), i = 1; i <= n; i++){
            for (j = 1; j <= n; j++) scanf("%d",&e[i][j]);
        }
        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                if (e[i][j]){
                    int r, c;
                    for (r = 0; e[i + r][j]; r++){
                        for (c = 0; e[i + r][j + c]; c++){
                            e[i + r][j + c] = 0;
                        }
                    }
                    ans.push_back({r,c,r*c});
                }
            }
        }
        sort(ans.begin(), ans.end());
        printf("#%d %d",x,ans.size());
        for (auto m : ans) printf(" %d %d",m.r,m.c);
        puts("");
    }
 
    return 0;
}
