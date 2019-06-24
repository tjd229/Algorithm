//d&c
#include <vector>
#include <string>

#include "messy.h"
std::string o;
void push(int s,int e) {
   if (s == e) return;
   std::string x = o;
   for (int i = s; i <= e; ++i) --x[i];
   int m = (s + e) >> 1;
   for (int i = s; i <= m; ++i) {
      ++x[i]; add_element(x);
      --x[i];
   }
   push(s, m); push(1+m,e);
}
void perm(int s,int e,std::vector<int> seat, std::vector<int> &p) {
   if (s == e) {
      p[seat[0]] = s;
      return;
   }
   std::string x= o;
   std::vector<int> l, r;
   for (auto i : seat) --x[i];
   for (auto i : seat) {
      ++x[i];
      if (check_element(x)) l.push_back(i);
      else r.push_back(i);
      --x[i];
   }
   perm(s, (s + e) >> 1, l,p);
   perm(1 + ((s + e) >> 1), e, r,p);
}
std::vector<int> restore_permutation(int n, int w, int r) {
   o.resize(n);
   for (int i = 0; i < n; ++i) o[i]='1';
   std::vector<int> p(n,0);
   std::vector<int> seat(n, 0);
   for (int i = 0; i < n; ++i) seat[i] = i;
   push(0,n-1);
    compile_set();
   perm(0,n-1,seat,p);
   return p;
}
