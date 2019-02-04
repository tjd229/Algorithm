//greedy
#include <iostream>
#include <string>
using namespace std;
string Nucleotide = "ACGT";
int cnt[50][4];
inline int c2i(char c) {
	for (int i = 0; i < 4; ++i) if (c == Nucleotide[i]) return i;
	return -1;
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string DNA;
		cin >> DNA;
		for (int j = 0; j < M; ++j) ++cnt[j][c2i(DNA[j])];
	}
	int dist = 0;
	for (int j = 0; j < M; ++j) {
		int mx = 0;
		int ix = -1;
		for (int i = 0; i < 4; ++i) {
			if (mx < cnt[j][i]) {
				mx = cnt[j][i];
				ix = i;
			}
		}
		dist += N - mx;
		cout << Nucleotide[ix];
	}
	cout << "\n" << dist;
	return 0;
}
