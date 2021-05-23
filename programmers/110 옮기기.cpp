//https://programmers.co.kr/learn/courses/30/lessons/77886
//greedy
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int nxt[1000010],pre[1000010];
int val[1000010];
int cnt = 0;
void node(int left,int ix,int x) {
	val[ix] = x;
	nxt[left] = ix;
	pre[ix] = left;
	nxt[ix] = -1;

}
bool chk(int cur) {
	if (cur < 0) return 0;
	if (val[cur] != 1) return 0;
	cur = nxt[cur];
	if (cur < 0) return 0;
	if (val[cur] != 1) return 0;
	cur = nxt[cur];
	if (cur < 0) return 0;
	if (val[cur] != 0) return 0;
	return 1;
}
vector<string> solution(vector<string> s) {
	vector<string> answer;
	for (auto ss : s) {
		if (ss.size() < 4) answer.push_back(ss);
		else {
			int st = -1;
			
				cnt = 0;
				val[cnt] = -1; pre[cnt] = -1;
				int cur = cnt;
				for (int i = 0; i < ss.size(); ++i) {
					node(cur, ++cnt, ss[i] - '0');
					cur = cnt;
				}

				cur=0;//head
				int mv = 0;
				while (nxt[cur]!=-1) {
					cur = nxt[cur];
					if (chk(cur)) {
						int left = pre[cur];
						int right = nxt[cur];
						right = nxt[right];
						right = nxt[right];
						nxt[cur] = nxt[nxt[cur]];
						nxt[cur] = nxt[nxt[cur]];
						
						nxt[left] = right;
						if(right!=-1) pre[right] = left;
						++mv;
						cur = left;
						if (val[cur] != -1) cur = pre[cur];
						if (val[cur] != -1) cur = pre[cur];
					}
				}
				string res = "";
				
				
				cur = 0;
				while (nxt[cur] != -1) {
					cur = nxt[cur];
					char c = '0' + val[cur];
					res += c;
				}

				if (mv == 0) answer.push_back(res);
				else {
					st=res.size();
					int ed = res.size();
					res += "110";
					for (int i = 0; i + 2 < res.size(); ++i) {
						if (res[i] == '1' && res[i + 1] == '1' && res[i + 2] == '1') {
							st = i;
							break;
						}
					}
					string res2 = "";
					for (int i = 0; i < st; ++i) res2 += res[i];
					while (mv--) {
						res2 += "110";
					}
					for (int i = st; i < ed; ++i) res2 += res[i];
					answer.push_back(res2);
				}
				
			
		}
	}
	return answer;
}