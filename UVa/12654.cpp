//Patches
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=602&page=show_problem&problem=4383
//category : dp


#include <stdio.h>
#define MIN(a,b) a<b? a:b
int F[3000];
int d[2][2000];
int N, C, T1, T2;

int main(){
   int i,j,k;
   int ans;
   int NN;
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
   while (scanf("%d%d%d%d",&N,&C,&T1,&T2)==4){
      ans = C+C;
      NN = N + N;
      for (i = 0; i < N; i++){
         scanf("%d", F + i), F[N + i] = F[i] + C;
         F[N + N + i] = F[i] + C + C;
         d[0][i] = d[1][i] = i+1;
      }
      for (; i < NN; i++) d[0][i] = d[1][i] = i + 1;
      j = 0;
      for (i = j = k = 0; i < NN; i++){
         while (F[i] + T1 >= F[j])j++;
         while (F[i] + T2 >= F[k])k++;
         d[0][i] = j;
         d[1][i] = k;
      }
      
      for (i = 0; i < N; i++){
         int dp[3000] = { 0 };
         
         for (j = N - 1+i; j >= i; j--){
            
            dp[j] = MIN(dp[d[0][j]] + T1, dp[d[1][j]] + T2);
         }
         ans = MIN(ans, dp[i]);
      }
      printf("%d\n",ans);

   }

   return 0;
}