//implementation

#include <string>
#include <vector>
#include <iostream>
using namespace std;
 
int main(){
    int i;
    int tc;
    for (tc = 1; tc <= 10; ++tc){
        int len;
        string eqn;
        cin >> len >> eqn;
        vector<int> v(len);
        int ans = 0;
        for (i = 0; i < len; ++i){
            if (eqn[i] == '*'){
                int l = v[i-1] ? v[i-1]: eqn[i - 1] - '0';
                int r = eqn[i + 1] - '0';
                v[i - 1] = 0;
                v[i] = -1;
                v[i + 1] = l*r;
                ++i;
            }
            else if (eqn[i] == '+') v[i] = -1;
            else v[i] = eqn[i] - '0';
        }
        for (i = 0; i < len; i++){
            if (v[i] != -1) ans += v[i];
        }
        cout << "#" << tc << " " << ans << "\n";
    }
 
    return 0;
}
