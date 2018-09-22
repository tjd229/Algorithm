//string

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int main(){
    int i,j;
    int C, T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (C = 1; C <= T; C++){
        int K;
        string s;
        set<string> st;
        cin >> K >> s;
        for (i = 0; i < s.size(); i++){
            string sub = { s[i] };
            st.insert(sub);
            for (j = i + 1; j < s.size(); j++){
                sub += s[j];
                st.insert(sub);
            }
        }
        cout << "#" << C << " ";
        if (K > st.size()) cout << "none\n";
        else{
            auto it = st.begin();
            while (--K) ++it;
            cout << *it<<"\n";
        }
    }
 
    return 0;
}
