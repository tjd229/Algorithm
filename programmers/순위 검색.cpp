//https://programmers.co.kr/learn/courses/30/lessons/72412
//string, implementation, bs
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
vector<int> v[3][2][2][2];
inline void parse_next(string &str, int &ix) {
	while (str[ix] != ' ') ++ix;
	++ix;
	if (str[ix] == 'a') {
		while (str[ix] != ' ') ++ix;
		++ix;
	}
}
int parse(string &str, int &lang, int &pos, int &lev, int &food) {
	int ix = 0;
	if (str[ix] == 'c') lang = 0;
	else if (str[ix] == 'j') lang = 1;
	else if (str[ix] == 'p') lang = 2;
	else lang = -1;
	parse_next(str, ix);
	if (str[ix] == 'b') pos = 0;
	else if (str[ix] == 'f') pos = 1;
	else pos = -1;
	parse_next(str, ix);
	
	if (str[ix] == 'j') lev = 0;
	else if (str[ix] == 's') lev = 1;
	else lev = -1;
	parse_next(str, ix);

	if (str[ix] == 'c') food = 0;
	else if (str[ix] == 'p') food = 1;
	else food = -1;
	parse_next(str, ix);
	int pt = 0;
	while (ix < str.size()) {
		pt = pt * 10 + str[ix] - '0';
		++ix;
	}
	return pt;
}
int moreX(vector<int> &v,int X) {
	return v.size()-(lower_bound(v.begin(), v.end(), X) - v.begin());
}
int dfs3(vector<int> &condi) {
	int X = condi.back();
	int a = condi[0], b = condi[1], c = condi[2], d = condi[3];
	if (d == -1) {
		int ans = 0;
		for (int i = 0; i < 2; ++i) {
			d = i;
			ans += moreX(v[a][b][c][d], X);
		}
		return ans;
	}
	return  moreX(v[a][b][c][d], X);
}
int dfs2(vector<int> &condi) {
	if (condi[2] == -1) {
		int ans = 0;
		for (int i = 0; i < 2; ++i) {
			condi[2] = i;
			ans += dfs3(condi);
		}
		condi[2] = -1;
		return ans;
	}
	return dfs3(condi);
}
int dfs1(vector<int> &condi) {
	if (condi[1] == -1) {
		int ans = 0;
		for (int i = 0; i < 2; ++i) {
			condi[1] = i;
			ans += dfs2(condi);
		}
		condi[1] = -1;
		return ans;
	}
	return dfs2(condi);
}
int dfs0(vector<int> condi) {
	if (condi[0] == -1) {
		int ans = 0;
		for (int i = 0; i < 3; ++i) {
			condi[0] = i;
			ans += dfs1(condi);
		}
		return ans;
	}
	return dfs1(condi);
}
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	int lang, pos, lev, food, pt;
	for (auto str : info) {
		pt = parse(str, lang, pos, lev, food);
		v[lang][pos][lev][food].push_back(pt);
		//printf("%d %d %d %d %d\n",lang,pos,lev,food,pt);
	}
	for (int i = 0; i < 3; ++i) for (int j = 0; j < 2; ++j)
		for (int k = 0; k < 2; ++k) for (int l = 0; l < 2; ++l) sort(v[i][j][k][l].begin(), v[i][j][k][l].end());
	for (auto str : query) {
		pt = parse(str, lang, pos, lev, food);
		//printf("! %d %d %d %d %d\n", lang, pos, lev, food, pt);
		answer.push_back(dfs0({ lang,pos,lev,food,pt }));
	}

	return answer;
}