//string, trie

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int nxt[1000001][26];
int cnt,ans;
bool valid[1000001];
vector<int> key[10];
void make_trie( string &s){
    int i, j;
    int curr = 0;
    for (i = 0; i < s.size(); i++){
        if (nxt[curr][s[i] - 'a'] == 0){
            nxt[curr][s[i] - 'a'] = ++cnt;
            for (j = 0; j < 26; j++) nxt[cnt][j] = 0;
            valid[cnt] = false;
        }
        curr = nxt[curr][s[i] - 'a'];
    }
    valid[curr] = true;
}
void search(int ix,int curr,string &s){
    ans += valid[ix];
    if (curr == s.size()) return;
    for (auto c : key[s[curr] - '0']){
        int to = nxt[ix][c];
        if (to) search(to, curr + 1, s);
    }
}
int main(){
    int i;
    int tc, T;
    int N;
    key[2] = {0,1,2};
    key[3] = { 3, 4, 5 };
    key[4] = { 6, 7, 8 };
    key[5] = { 9, 10, 11 };
    key[6] = { 12, 13, 14 };
    key[7] = { 15, 16, 17, 18 };
    key[8] = { 19, 20, 21 };
    key[9] = { 22, 23, 24, 25 };
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (tc = 1; tc <= T; tc++){
        cnt = ans = 0;
        for (i = 0; i < 26; i++) nxt[0][i] = 0;
        string S;
        cin >> S >> N;
        while (N--){
            string dic;
            cin >> dic;
            make_trie(dic);
        }
        search(0, 0, S);
        cout << "#" << tc << " " << ans << "\n";
    }
 
    return 0;
}
