//greedy

#include <stdio.h>
#include <algorithm>
using namespace std;
int h[10001], nh[10001];
int main(){
    int i;
    int tc, T;
    int N;
    for (scanf("%d", &T), tc = 1; tc <= T; ++tc){
        for (scanf("%d", &N), i = 1; i <= N; i++) scanf("%d",h+i);
        sort(h + 1, h + 1 + N);
        int l = 1;
        int r = N;
        int t = 0;
        for (i = 1; i <= N; i++){
            if (i & 1) nh[l++] = h[i];
            else nh[r--] = h[i];
        }
        int ans = nh[N] - nh[1];
        for (i = 2; i <= N; i++){
            int d = nh[i] - nh[i - 1];
            if (d < 0) d = -d;
            if (ans < d) ans = d;
        }
        printf("#%d %d\n",tc,ans);
    }
 
    return 0;
}
