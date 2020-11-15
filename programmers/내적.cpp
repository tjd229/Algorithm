//math
//https://programmers.co.kr/learn/courses/30/lessons/70128
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    long long ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        ans += a[i] * b[i];
    }
    return ans;
}