//implementation

#include <stdio.h>
int cnt[101];
int main(){
    int i;
    int tc, T;
    for (scanf("%d", &T), tc = 1; tc <= T; ++tc){
        int mx = 0;
        int ans = 0;
        for (scanf("%d", &tc), i = 0; i < 1000; i++){
            int p;
            scanf("%d",&p);
            cnt[p]++;
        }
        for (i = 100; i; --i){
            if (mx < cnt[i]) mx = cnt[i], ans = i;
            cnt[i] = 0;
        }
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}
