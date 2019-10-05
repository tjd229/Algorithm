//https://programmers.co.kr/learn/courses/30/lessons/60060
//trie, string

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;
int edge[3000001][26];
int sum[3000001];
int len_root[1000001];
void make_trie(int src,string &s) {
	int curr = src;
	for (int i = 0; i < s.size();++i) {
		int c = s[i] - 'a';
		if (edge[curr][c] == 0) 
			edge[curr][c] = ++cnt;
		curr = edge[curr][c];
	}
	sum[curr] = 1;
}
int search(int src,string &s) {
	if (src == 0) return 0;
	int curr = src;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '?') return sum[curr];
		curr =edge[curr][s[i] - 'a'];
	}
	return 0;
}
int dfs(int x) {
	for (int i = 0; i < 26; ++i) {
		int nxt = edge[x][i];
		if (nxt) sum[x] += dfs(nxt);
	}
	return sum[x];
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer(queries.size());
	int bnd = 0;
	for (int i = 0; i < words.size(); ++i) {
		int len = words[i].size();
		if (bnd < len) bnd = len;
		if (len_root[len] == 0) {
			len_root[len] = ++cnt;
			++cnt;//for reverse
		}
		make_trie(len_root[len],words[i]);
		reverse(words[i].begin(),words[i].end());
		make_trie(len_root[len]+1, words[i]);
	}
	for (int i = 1; i <= bnd; ++i) {
		if (len_root[i]) {
			dfs(len_root[i]);
			dfs(len_root[i]+1);
		}
	}
	for (int i = 0; i < queries.size(); ++i) {
		int len = queries[i].size();
		if (queries[i][0] == '?') {
			reverse(queries[i].begin(), queries[i].end());
			answer[i] = search(len_root[len]+ (len_root[len]>0), queries[i]);
		}
		else answer[i] = search(len_root[len], queries[i]);
	}

	return answer;
}