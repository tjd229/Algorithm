//greedy

#include <set>
#include <stdio.h>
using namespace std;
int main(){
    int tc;
    int i;
    for (tc = 1; tc <= 10; ++tc){
        int h,cnt;
        multiset<int> ms;
        for (scanf("%d",&cnt),i = 0; i < 100; i++){
            scanf("%d",&h);
            ms.insert(h);
        }
        while (cnt--){
            auto l = ms.begin();
            auto r = --ms.end();
            int d = *r - *l;
            if (d < 2) break;
            int dump1 = *r - 1;
            int dump2 = *l + 1;
            ms.erase(l);
            ms.erase(r);
            ms.insert(dump1);
            ms.insert(dump2);
        }
        auto l = ms.begin();
        auto r = --ms.end();
        printf("#%d %d\n",tc,*r-*l);
    }
 
    return 0;
}
