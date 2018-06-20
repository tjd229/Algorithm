//category : st, lazy propagation

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int LEAF = 1 << 20;
vector<int> comp;
int decomp[(int)9e5+5];
int st[LEAF + LEAF];
int lazy[LEAF + LEAF];

struct Order{
   int l, r, k;
}o[(int)3e5];

void propagate(int ix,int s,int e){
   
   st[ix] = lazy[ix]-1? decomp[e + 1] - decomp[s]:0;
   if (ix < LEAF) lazy[ix + ix] = lazy[ix + ix + 1] = lazy[ix];
   lazy[ix] = 0;
}
void update(int ix, int s, int e, int from, int to, int on){
	if (lazy[ix]) propagate(ix, s, e);
   if (e < from || to < s){
	   return;
   }
   else if (s >= from && e <= to){
      lazy[ix] = on;
	  propagate(ix, s, e);
   }
   else{
      update(ix + ix, s, (s + e) >> 1, from, to, on);
      update(ix + ix+1, 1+((s + e) >> 1),e, from, to, on);
      st[ix] = st[ix + ix] + st[ix + ix + 1];
   }
   
}
int main(){
   int i;
   int n, m;
   int l, r, k;
   comp.push_back(1);
   for (scanf("%d%d", &n, &m), i = 0; i < m; i++){
      scanf("%d%d%d", &l,&r,&k);
      comp.push_back(l);
      comp.push_back(r);
      comp.push_back(r+1);
      o[i] = { l, r, k };
   }
   comp.push_back(n+1);
   
   sort(comp.begin(), comp.end());   
   comp.resize(unique(comp.begin(),comp.end())-comp.begin());
   
   for (i = 0; i < comp.size(); i++)
	   decomp[i] = comp[i];// , printf("%d ", decomp[i]);
      
   update(1,0,LEAF-1,0,comp.size()-2,2);
   
   for (i = 0; i < m; i++){
      l = lower_bound(comp.begin(), comp.end(), o[i].l) - comp.begin();
      r = lower_bound(comp.begin(), comp.end(), o[i].r) - comp.begin();
      update(1,0,LEAF-1,l,r,o[i].k);
      printf("%d\n", st[1]);
   }

   return 0;
}
