//implementation

#include <string>
#include <iostream>
using namespace std;
int main(){
    int i;
    int tc;
    for (tc = 1; tc <= 10; ++tc){
        int len;
        string eqn;
        cin >> len >> eqn;
        bool flag = false;
        int ans = 0;
        int n = 0;
        for (i = 0; i < len; i++){
            if (eqn[i] != '+'){
                n *= 10;
                n += eqn[i] - '0';
            }
            else{
                //cout << n << endl;
                if (!flag) ans+=n,n = 0;
                flag = false;
            }
        }
        cout << "#" << tc << " " << ans+n << "\n";
    }
 
    return 0;
}
