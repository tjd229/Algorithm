//category : math

#include <stdio.h>
#define ll long long
int cnt[1000001];
int main(){
   ll min, max;
   ll i,j;
   
   int ans=0;
   scanf("%lld%lld",&min,&max);
   
   for (i = 2; i*i <= max; i++){
      j = i*i - min % (i*i);
      if (j == i*i) j = 0;
      for (ll n = max - min; j <= n; j += i*i)
         cnt[j] = 1;
   }
   for (ll n = max - min, i = 0; i <= n; i++)
      ans += (cnt[i] == 0);
   printf("%d",ans);
   return 0;
}
