//math
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000877ba5/0000000000aa8fc1
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<int> v;
vector<int> b[100];
void print(vector<int> &v) {
	for (auto x : v) printf("%d ",x);
	printf("\n"); fflush(stdout);
}
int main() {
	int T,i;
	for (i = 0; i < 30; ++i) v.push_back(1 << i);
	int c = 1e9;
	ll B = 1LL << 30;
	b[30].push_back(--c);
	b[30].push_back(B-c);
	B = 1LL << 31; 
	b[31].push_back(--c); B -= c; 
	b[31].push_back(--c); B -= c; 
	b[31].push_back(B); 
	B = 1LL << 32;
	b[32].push_back(--c); B -= c;
	b[32].push_back(--c); B -= c;
	b[32].push_back(--c); B -= c;
	b[32].push_back(--c); B -= c;
	b[32].push_back(B);
	B = 1LL << 33;
	for (int i = 0; i < 8; ++i)
		b[33].push_back(--c), B -= c;
	b[33].push_back(B);
	B = 1LL << 34;
	for (int i = 0; i < 17; ++i)
		b[34].push_back(--c), B -= c;
	b[34].push_back(B);
	
	vector<int> A = v;
	for (int i = 30; i < 35; ++i) {
		for (auto x : b[i]) A.push_back(x);
	}
	while (A.size() < 100) A.push_back(--c);
	//A.resize(unique(A.begin(), A.end()) - A.begin());
	//printf("%d", A.size());
	
	for (scanf("%d", &T); T--;) {
		int N; scanf("%d",&N);
		print(A);
		vector<int> ans,B;
		ll sum = 0;
		for (auto x : A) sum += x;
		for (i = 0; i < N; ++i) {
			int _B;
			scanf("%d", &_B); sum += _B;
			B.push_back(_B);
		}
		sort(B.begin(), B.end()); reverse(B.begin(), B.end());
		ll tgt = sum >> 1;
		ll mx = 1LL << 35;
		while (tgt >= mx) {
			ans.push_back(B.back());
			tgt -= B.back(); B.pop_back();
		}
		int bix = 0;
		while (tgt) {
			if (tgt & 1) {
				if (bix < 30) ans.push_back(v[bix]);
				
				else {
					for (auto x : b[bix]) ans.push_back(x);
				}
			}
			tgt >>= 1;
			++bix;
		}
		print(ans);
	}

	return 0;
}