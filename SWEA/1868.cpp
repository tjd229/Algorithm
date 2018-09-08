//graph

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#define pii pair<int,int>
using namespace std;
string map[302];
int cnt[302][302];
int visit[302][302];
void dfs(int i,int j,int stamp){
    if (visit[i][j] == stamp) return;
    visit[i][j] = stamp;
    if (map[i][j] == '.' && cnt[i][j] == 0){
        dfs(i + 1, j, stamp);
        dfs(i - 1, j, stamp);
        dfs(i, j-1, stamp);
        dfs(i, j+1, stamp);
        dfs(i + 1, j + 1, stamp);
        dfs(i - 1, j - 1, stamp);
        dfs(i + 1, j - 1, stamp);
        dfs(i - 1, j + 1, stamp);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, T;
    int i, j;
    int N;
    string line;
    for (i = 0; i <= 301; i++) map[0] += '!';
    cin >> T;
    for (x = 1; x <= T; x++){
        vector<pii > safe, unk;
        int ans = 0;
        cin >> N;
        for (i = 1; i <= N; i++){
            cin >> line;
            map[i] = '!' + line+'!';
        }
        map[N + 1] = "";
        for (i = 0; i <= N + 1; i++) map[N + 1] += '!';
 
        for (i = 1; i <= N; i++){
            for (j = 1; j <= N; j++){
                cnt[i][j] = 0;
                if (map[i][j] == '.'){
                    for (int ii = -1; ii <= 1; ++ii){
                        for (int jj = -1; jj <= 1; ++jj)
                            cnt[i][j] += map[i + ii][j + jj] == '*';
                    }
                    if (cnt[i][j]) unk.push_back({i,j});
                    else safe.push_back({i,j});
                }
            }
        }
        for (auto p : safe){
            i = p.first;
            j = p.second;
            if (visit[i][j] != x){
                dfs(i, j, x);
                ++ans;
            }
        }
        for (auto p : unk){
            i = p.first;
            j = p.second;
            if (visit[i][j] != x){
                visit[i][j] = x;
                ++ans;
            }
        }
        cout << '#' << x << " " << ans << "\n";
    }
 
    return 0;
}
