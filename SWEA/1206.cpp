//implementation
#include <stdio.h>
int b[1000];
int max(int a, int b){ return a < b ? b : a; }
int main(){
    int i;
    int tc;
     
    for (tc = 1; tc <= 10; tc++){
        int N;
        int ans = 0;
        for (scanf("%d", &N), i = 0; i < N; i++) scanf("%d",b+i);
        for (i = 0; i < N; i++){
            if (b[i]){
                int l = max(b[i - 1], b[i - 2]);
                int r = max(b[i + 1], b[i + 2]);
                int mx = max(l, r);
                if (mx < b[i]) ans += b[i] - mx;
            }
        }
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}
