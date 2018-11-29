//https://www.welcomekakao.com/learn/courses/30/lessons/42890
//string

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> candi;
bool can(int stat, vector<vector<string>> &r) {
	for (auto c : candi) {
		if ((c&stat) == c) return false;
	}
	unordered_map<string, int> mp;
	for (auto row : r) {
		string key = "";
		for (int i = 0; i < row.size(); ++i) {
			if ((1 << i)&stat) {
				for (auto c : row[i]) key += c;
				key += '#';
			}
		}
		if (++mp[key] > 1) return false;
	}
	return true;
}
int solution(vector<vector<string>> relation) {
	int N = relation[0].size();
	int bnd = 1 << N;
	for (int i = 1; i <= bnd; ++i) {
		if (can(i, relation)) candi.push_back(i);
	}
	return candi.size();
}