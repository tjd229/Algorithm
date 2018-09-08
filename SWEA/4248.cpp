//line sweeping

#include <stdio.h>
#define ll long long
int a[100002];
int N,K;
int main(){
    setbuf(stdout, NULL);
    int i;
    int tc;
    int T;
    int l, r;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        ll ans = 0;
        l = 1e6;
        int len=1;
        scanf("%d%d",&N,&K);
        for (i = 1; i <= N; i++) scanf("%d", a + i);
        for (i = 1; i <= N+1; i++){          
            if (l < a[i]) len++;
            else{
                ll cnt = len - K + 1;
                if (cnt> 0) ans += (cnt*cnt+cnt)>>1;
                len = 1;
            }
            l = a[i];
             
        }
        for (i = 1; i <= N; i++){
            len = 1;
            l = i - 1;
            r = i + 1;
            if (a[l] > a[i]){
                len++;
                //--l;
                while (l>1 && a[l-1] < a[l]) --l,++len;
                if (len - K + 1 > 0) ans += len - K + 1;
                //printf("%d~%d:%lld\n",a[l],a[i],ans);
                if (r <= N && a[r] > a[i-1]){
                    int k = l;
                    while (k < i-1 && r - k + 1 > K) k++;
                    if (r - k + 1 >= K) ans += k-l+1;
                    ++r;
                    //printf("!%lld\n",ans);
                    //printf("k,l:%d,%d\n",k,l);
                    while (r <= N && a[r] > a[r - 1]){
                         
                        while (k < i-1 && r - k + 1 > K) k++;
                        //printf("r,k,l,d:%d,%d,%d,%d\n", r, k,l,k-l+1);
                        if (r - l+1 >= K) ans += k - l+1;
                        ++r;
                        //printf("!%lld\n",ans);
                    }
                }
            }
            //printf("!!%lld\n", ans);
        }
        printf("#%d %lld\n",tc,ans);
 
    }
 
 
    return 0;
}
