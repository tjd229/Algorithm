//https://www.welcomekakao.com/learn/courses/30/lessons/42893
//string, hashing

#include <string>
#include <vector>
#define ll long long
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const string content = "<meta property=\"og:url\" content=";
ll h1[20], h2[20];
int base[20];
double mp[20];
vector<int> link[20];
int bfsearch(ll hash1, ll hash2) {
	for (int i = 0; i < 20; ++i) {
		if (h1[i] + h2[i] == 0) return -1;
		else if (h1[i] == hash1 && h2[i] == hash2) return i;
	}
	return -1;
}
int solution(string word, vector<string> pages) {
	int answer = 0;
	for (int i = 0; i < word.size(); ++i) {
		if (word[i] >= 'A'&&word[i] <= 'Z') word[i] += 'a' - 'A';
	}
	for (int i = 0; i < pages.size(); ++i) {
		int s = pages[i].find("<head>");
		int e = pages[i].find("</head>");
		int ls = s;
		for (; ls < e; ++ls) {
			int lix = 0;
			while (lix < content.size() && pages[i][ls + lix] == content[lix]) ++lix;

			if (lix == content.size()) {
				ls += lix+7;
				ll &ref1 = h1[i];
				ll &ref2 = h2[i];
				while (pages[i][ls] != '\"') {
					ref1 <<= 8; ref1 %= mod1;
					ref2 <<= 8; ref2 %= mod2;
					ref1 = (ref1 + pages[i][ls]) % mod1;
					ref2 = (ref2 + pages[i][ls]) % mod2;
					++ls;
				}
				break;
			}
		}
	}
	for (int i = 0; i < pages.size(); ++i) {
		int s = pages[i].find("<body>") + 6;
		int e = pages[i].find("</body>")+1;
		while (s < e) {
			if (pages[i][s - 1] == '<' && pages[i][s] == 'a') {

				int ls = s + 14;
				ll hash1 = 0;
				ll hash2 = 0;
				while (pages[i][ls] != '\"') {
					hash1 <<= 8; hash1 %= mod1;
					hash2 <<= 8; hash2 %= mod2;
					hash1 = (hash1 + pages[i][ls]) % mod1;
					hash2 = (hash2 + pages[i][ls]) % mod2;
					++ls;
				}
				link[i].push_back(bfsearch(hash1, hash2));
				s = ls + 2;
				while (pages[i][s] != 'a' || pages[i][s + 1] != '>')++s;
			}
			else if (pages[i][s - 1] == '<') {
				while (pages[i][s] != '>')++s;
			}
			else {
				int wix = 0;
				while (wix < word.size()) {
					if (pages[i][s] >= 'A' && pages[i][s] <= 'Z')
						pages[i][s] += 'a' - 'A';
					if (word[wix] != pages[i][s]) break;
					++s;
					++wix;
				}
				if (pages[i][s] >= 'A' && pages[i][s] <= 'Z')
					pages[i][s] += 'a' - 'A';
				if (wix == word.size() && (pages[i][s]<'a' || pages[i][s]>'z'))
					++base[i];
				else {
					while (1) {
						if (pages[i][s] >= 'A' && pages[i][s] <= 'Z')
							pages[i][s] += 'a' - 'A';
						if (pages[i][s]<'a' || pages[i][s]>'z') break;
						++s;
					}

				}
			}
			++s;
		}
		mp[i] += base[i];
		for (auto ref : link[i]) {
			if (ref >= 0) mp[ref] += (double)base[i] / link[i].size();

		}
	}
	double mx = 0.0;
	for (int i = 0; i < pages.size(); ++i) {
		if (mx < mp[i]) {
			mx = mp[i];
			answer = i;
		}
	}

	return answer;
}
