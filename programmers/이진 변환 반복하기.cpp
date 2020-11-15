//implementation
//https://programmers.co.kr/learn/courses/30/lessons/70129
#include <string>
#include <vector>

using namespace std;
int deform(string &s) {
    int zero = 0;
    for (auto x : s) {
        if (x == '0') ++zero;
    }
    return zero;
}
vector<int> solution(string s) {
    int cnt = 0;
    int op = 0;
    while (1) {
        if (s.size() == 1) break;
        int zero = deform(s);
        int n = s.size() - zero;
        cnt += zero;
        ++op;
        vector<int> stk;
        while (n) {
            stk.push_back(n&1);
            n >>= 1;
        }
        string t(stk.size(),'0');
        int ix = 0;
        while (stk.size()) {
            t[ix++] = stk.back() + '0';
            stk.pop_back();
        }
        s = t;
    }
    return { op,cnt };

}