//greedy

#include <stdio.h>
#include <algorithm>
using namespace std;
int c[100000];
int main(){
    int i, j;
    int tc, T;
    int N;
    for (scanf("%d", &T), tc = 1; tc <= T; ++tc){
        for (scanf("%d", &N), i = 0; i < N; i++) scanf("%d",c+i);
        sort(c, c + N);
        long long ans = 0;
        for (i = N-1,j=0; i >=0; i--,j=(j+1)%3){
            if (j!=2)
                ans += c[i];
        }
        printf("#%d %lld\n",tc,ans);
    }
 
    return 0;
}
