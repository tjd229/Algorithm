//implementation
//https://programmers.co.kr/learn/courses/30/lessons/70130
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
using namespace std;
vector<int> pos[500000];
int solution(std::vector<int> a) {
    int ans = 0;
    set<int> chk;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        chk.insert(a[i]);
        pos[a[i]].push_back(i + 1);
    }
    if (chk.size() == 1) return 0;
    //if (chk.size() == 2) return 2;

    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        l = r = 0;
        int len = 0;
        int last = 0;
        //printf("%d start\n",i);
        for (int j = 0; j < pos[i].size(); ++j) {
            l = r;
            r = 1;
            int cnt = pos[i][j] - last - 1;
            //printf("%d~%d:%d\n", last+1,-1+pos[i][j], cnt);

            if (l && cnt > 0) {
                ++len;
                --cnt;
            }
            if (r&& cnt > 0) {
                ++len;
                --cnt;
                r = 0;
            }

            last = pos[i][j];
        }
        if (r) {
            int cnt = n + 1 - last - 1;
            if (cnt > 0) {
                ++len;
            }
        }
        if (ans < len + len) ans = len + len;
    }

    return ans;
}