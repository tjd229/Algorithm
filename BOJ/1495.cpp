//category : dp

#include <stdio.h>

int S,N,M;
int v[101];
int d[101][1001];
int c[101][1001];
void play(int n,int p){
    if(p<0||p>M) return;
    if(c[n][p]==1) return;
    if(n<N){
        play(n+1,p+v[n+1]);
        play(n+1,p-v[n+1]);
    }
    c[n][p]=1;
    d[n][p]=1;
}
int main(){
    
    int i;
    int ans;
    scanf("%d%d%d",&N,&S,&M);
    for(i=1;i<=N;i++) scanf("%d",&v[i]);
    
    play(0,S);
   
    ans=-1;
    for(i=0;i<=M;i++)
        if(d[N][i]==1) ans=i;
    printf("%d",ans);
    
    
    return 0;
}

