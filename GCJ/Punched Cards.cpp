//implementation
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
void draw(vector<char> &v,char fi,char se, int c) {
	for (int i = 0; i < c; ++i) {
		v.push_back(fi);
		v.push_back(se);
	}
	v.push_back(fi);
}
int main() {
	int T,tc;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		int i, j, R, C;
		scanf("%d%d",&R,&C);
		vector<vector<char> > lines(R+R+1);
		for (i = 0; i < R+R ; i+=2) {
			draw(lines[i], '+', '-', C);
			draw(lines[i+1], '|', '.', C);
		}
		draw(lines[R+R], '+', '-', C);
		lines[0][0] = lines[0][1] = lines[1][0] = '.';

		

		printf("Case #%d:\n", tc);
		for (i = 0; i < R + R + 1; ++i) {
			for (auto c : lines[i]) printf("%c",c);
			printf("\n");
		}
	}

	return 0;
}
	