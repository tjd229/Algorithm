//math

#include <vector>
#include <stdio.h>
using namespace std;
vector<int> prime = {2,3,5,7,11,13,17};
int nCk[19][19];
int pt(int n, int k){
    if (k == 0 || n == k) nCk[n][k] = 1;
    if (nCk[n][k]) return nCk[n][k];
    nCk[n][k] = pt(n - 1, k) + pt(n - 1, k - 1);
    return nCk[n][k];
}
int main(){
    int i;
    int x, T;
    double somA, somB;
    for (scanf("%d", &T), x = 1; x <= T; x++){
        int a, b;
        scanf("%d%d",&a,&b);
        somA = a / 100.0;
        somB = b / 100.0;
        double pa = 0.0;
        double pb = 0.0;
        for (auto p : prime){
            double stk = 1;
            for (i = 0; i < p; i++) stk *= somA;
            for (i = 0; i < 18 - p; i++) stk *= (1 - somA);
            pa += stk*pt(18, p);
            stk = 1;
            for (i = 0; i < p; i++) stk *= somB;
            for (i = 0; i < 18 - p; i++) stk *= (1 - somB);
            pb += stk*pt(18, p);
 
        }
        printf("#%d %.6f\n",x,pa+pb-pa*pb);
    }
 
    return 0;
}
