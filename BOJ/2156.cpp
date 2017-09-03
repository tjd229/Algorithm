//category : dp



#include <stdio.h>

int wine[10001];
int D[10001][3];
int max(int a,int b){return a<b? b:a;}
int main(){
    int n;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&wine[i]);
    D[1][1]=wine[1];
    for(i=2;i<=n;i++){
        D[i][0]=max(D[i-1][0],max(D[i-1][1],D[i-1][2]));
        D[i][1]=D[i-1][0]+wine[i];
        D[i][2]=D[i-1][1]+wine[i];
    }
    printf("%d\n",max(D[n][0],max(D[n][1],D[n][2])));
    return 0;
}