//hashing

#include <string>
#include <iostream>
#define ll long long
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = mod1 + 2;
const int base = 256;
ll roll(ll h,int val,int mod){
    h = h*base%mod;
    h = (h + val)%mod;
    return h;
}
ll subtract(ll h1, ll h2,int mod){
    ll res = h1 - h2;
    while (res < 0) res += mod;
    return res;
}
int main(){
    int i;
    int tc;
    string t, s;
    ll t1, t2;
    ll l1, l2;
    ll h1, h2;
    int cnt = 0;
    //freopen("input.txt","r",stdin);
    for (tc = 1; tc <= 10; tc++){
        cin >> tc >> t >> s;
        t1 = t2 = l1 = l2 = h1 = h2 = 0;
        cnt = 0;
        l1 = l2 = 1;
        for (i = 0; i < t.size(); i++){
            t1 = roll(t1,t[i],mod1);
            t2 = roll(t2, t[i], mod2);
            l1 = roll(l1, 0, mod1);
            l2 = roll(l2, 0, mod2);
            h1 = roll(h1, s[i], mod1);
            h2 = roll(h2, s[i], mod2);
        }
        //cout << l1 << "," << l2 << endl;
        cnt += (t1 == h1 && t2 == h2);
        for (i = t.size(); i < s.size(); i++){
            h1 = roll(h1, s[i], mod1);
            h1 = subtract(h1, l1*(ll)s[i - t.size()] % mod1, mod1);
            h2 = roll(h2, s[i], mod2);
            h2 = subtract(h2, l2*(ll)s[i - t.size()] % mod2, mod2);
            cnt += (t1 == h1 && t2 == h2);
        }
        cout << '#' << tc << " " << cnt << "\n";
    }
    return 0;
     
 
 
}
