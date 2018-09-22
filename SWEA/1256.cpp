//string, SA, cnt sort

#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
int g[402];
int six[401], cnt[401];
int tmp[401];
int d;
bool cmp(int a, int b){
    if (g[a] == g[b]) return g[a + d] < g[b + d];
    return g[a] < g[b];
}
void cnt_sort(int len){
    int i;
    memset(cnt, 0, sizeof(cnt));
    memset(tmp, 0, sizeof(tmp));
    for (i = 0; i < len; i++) cnt[g[min(len, six[i] + d)]]++;
    for (i = 1; i < len || i < 256; i++) cnt[i] += cnt[i - 1];
    for (i = len - 1; i >= 0; i--) tmp[--cnt[g[min(len, six[i] + d)]]] = six[i];
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < len; i++) cnt[g[tmp[i]]]++;
    for (i = 1; i < len || i < 256; i++) cnt[i] += cnt[i - 1];
    for (i = len - 1; i >= 0; i--) six[--cnt[g[tmp[i]]]] = tmp[i];
}
int main(){
    int i;
    int C, T;
    cin >> T;
    for (C = 1; C <= T; ++C){
        cout << "#" << C<<" ";
        int K;
        string s;
        cin >> K >> s;
        if (K > s.size()) cout << "none\n";
        else{
            for (i = 0; i < s.size(); i++){
                six[i] = i;
                g[i] = s[i];
            }
 
            g[i] = 0;
            d = 1;
            do{
                cnt_sort(s.size());
                tmp[six[0]] = 1;
                for (i = 1; i < s.size(); i++)
                    tmp[six[i]] = tmp[six[i - 1]] + cmp(six[i - 1], six[i]);
                for (i = 0; i < s.size(); i++) g[i] = tmp[i];
                 
                d <<= 1;
                //cout << d << endl;
            } while (g[six[s.size() - 1]] != s.size());
            for (i = six[K-1]; i < s.size(); i++) cout << s[i];
            cout << "\n";
        }
    }
 
    return 0;
}

