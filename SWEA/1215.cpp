//string

#include <iostream>
#include <string>
using namespace std;
string map[8];
bool palindrome(int sx,int sy,int ex,int ey){
    if (ex >= 8 || ey >= 8) return false;
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
        cin >> N;
        for (i = 0; i < 8; i++) cin >> map[i];
        int cnt = 0;
        for (i = 0; i < 8; i++){
            for (j = 0; j < 8; j++){
                cnt += palindrome(j, i, j + N - 1, i);
                cnt += palindrome(j, i, j, i + N - 1);
            }
        }
        cout << "#" << tc << " " << cnt << "\n";
    }
    return 0;
}
