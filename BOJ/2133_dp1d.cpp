//category : dp



#include <stdio.h>
int d[31];
int main(){
    int n;
    int i;
    scanf("%d",&n);
    if(n&1) return printf("0");
    d[2]=3;
    d[4]=11;
    for(i=6;i<=n;i+=2) d[i]=4*d[i-2]-d[i-4];
    printf("%d",d[n]);
    return 0;
}