//implementation

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int stk[4];
bool pushpop(char c){
    switch (c){
    case '(':
        stk[0]++;
        break;
    case ')':
        if (stk[0] == 0) return false;
        --stk[0];
        break;
    case '[':
        stk[1]++;
        break;
    case ']':
        if (stk[1] == 0) return false;
        --stk[1];
        break;
    case '{':
        stk[2]++;
        break;
    case '}':
        if (stk[2] == 0) return false;
        --stk[2];
        break;
    case '<':
        stk[3]++;
        break;
    case '>':
        if (stk[3] == 0) return false;
        --stk[3];
        break;
    }
    return true;
}
int main(){
    int i;
    int tc;
    int len;
    string s;
    for (tc = 1; tc <= 10; tc++){
        int ans = true;
        for (i = 0; i < 4; i++) stk[i] = 0;
        cin >> len >> s;
        for (i = 0; i < s.size(); i++){
            if (pushpop(s[i]) == false){
                ans = false;
                break;
            }
        }
        ans &= (stk[0] + stk[1] + stk[2] + stk[3] == 0);
        cout << '#' << tc << " " << ans << "\n";
    }
 
    return 0;
}
