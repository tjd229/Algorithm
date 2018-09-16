//dp
//ref : http://hrothgar.tistory.com/37


#include <stdio.h>
int j[(int)1e7+1];
int main(){
    int i;
    int tc, T;
    int N;
    long long K;
    for (scanf("%d", &T), tc = 1; tc <= T; tc++){
        scanf("%d%lld",&N,&K);
        j[1] = 1;
        ++K;
        for (i = 2; i <= N; i++) j[i] = (j[i - 1] + K - 1) % i + 1;
        printf("#%d %d\n",tc,j[N]);
    }
 
    return 0;
}
