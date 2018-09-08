//string

#include <iostream>
#include <string>
using namespace std;
string map[100];
bool palindrome(int sx,int sy,int ex,int ey){
    if (ex >= 100 || ey >= 100) return false;
    if (ey == sy){
        while (sx <= ex){
            if (map[sy][sx] != map[sy][ex]) return false;
            ++sx;
            --ex;
        }
    }
    else{
        while (sy <= ey){
            if (map[sy][sx] != map[ey][sx]) return false;
            ++sy;
            --ey;
        }
    }
    return true;
}
int main(){
    int i,j;
    int tc;
    int N;
    for (tc = 1; tc <= 10; tc++){
        N = 100;
        cin >> tc;
        for (i = 0; i < 100; i++) cin >> map[i];
 
        int cnt = 1;
        while (N > 1){
            for (i = 0; i < 100; i++){
                for (j = 0; j < 100; j++){
                     
                    if (palindrome(j, i, j + N - 1, i) || palindrome(j, i, j, i + N - 1)){
                        cnt = N;
                        i = 10000;
                        N = -1;
                        break;
                    }
                }
            }
            --N;
        }
        cout << "#" << tc << " " << cnt << "\n";
    }
    return 0;
}
