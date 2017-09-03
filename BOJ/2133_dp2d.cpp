//category : dp

#include <stdio.h>
int d[31][8];

int main(){
    int n;
    int i;
    scanf("%d",&n);
    if(n&1) return printf("0");
    d[1][0]=d[1][3]=d[1][6]=1;
    for(i=2;i<=n;i++){
        d[i][0]=d[i-1][7];
        d[i][1]=d[i-1][6];
        d[i][2]=d[i-1][5];
        d[i][3]=d[i-1][4]+d[i-1][7];
        d[i][4]=d[i-1][3];
        d[i][5]=d[i-1][2];
        d[i][6]=d[i-1][1]+d[i-1][7];
        d[i][7]=d[i-1][0]+d[i-1][3]+d[i-1][6];
    }
    printf("%d",d[n][7]);
    return 0;
}