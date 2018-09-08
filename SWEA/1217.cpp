//math

#include <stdio.h>
int pow(int n,int e){
    if (e == 0) return 1;
    else if (e & 1) return n*pow(n, e-1);
    int half = pow(n, e >> 1);
    return half*half;
}
int main(){
    int tc;
    int n, e;
    for (tc = 1; tc <= 10; tc++){
        scanf("%d%d%d",&tc,&n,&e);
        printf("#%d %d\n",tc,pow(n,e));
    }
 
    return 0;
}
