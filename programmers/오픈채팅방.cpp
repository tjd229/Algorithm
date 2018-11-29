//https://www.welcomekakao.com/learn/courses/30/lessons/42888
//implementation, string, hashing

#include <string>
#include <vector>
#include <map>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
//const int base = 128;
pll get_id(string &q) {
	ll h1 = 0;
	ll h2 = 0;
	int s;
	for (s = 0; q[s] != ' '; ++s);
	for (++s; s<q.size()&&q[s] != ' '; ++s) {
		h1 <<= 7; h1 %= mod1;
		h2 <<= 7; h2 %= mod2;
		h1 = (h1+q[s])%mod1;
		h2 = (h2+q[s])%mod2;
	}
	return {h1,h2};
}
vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<pll, string> mp;
	int i;
	for (i = record.size() - 1; i >= 0; --i) {
		if (record[i][0] == 'L') continue;
		pll h = get_id(record[i]);
		if (mp.find(h) == mp.end()) {
			int s;
			string nid = "";
			for (s = 0; record[i][s] != ' '; ++s);
			for (++s; record[i][s] != ' '; ++s);
			for (++s; s < record[i].size(); ++s)
				nid += record[i][s];
			mp[h] = nid;
		}
	}
	for (auto s : record) {
		if (s[0] == 'E') {
			pll h = get_id(s);
			string ans = mp[h]+"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			answer.push_back(ans);
		}
		else if (s[0] == 'L') {
			pll h = get_id(s);
			string ans = mp[h] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			answer.push_back(ans);
		}
		
	}
	return answer;
}
#include <iostream>
int main() {
	vector<string> q;
	q.push_back("Enter uid1234 Muzi");
	q.push_back("Enter uid4567 Prodo");
	q.push_back("Leave uid1234");
	q.push_back("Enter uid1234 Prodo");
	q.push_back("Change uid4567 Ryan");
	vector<string> ans = solution(q);
	for (auto s : ans) {
		cout << s << endl;
	}
	return 0;
}