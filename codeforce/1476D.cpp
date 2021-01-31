//greedy

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int r[300001], l[300001];
int vis[300001];
char s[300001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf(" %c",s+i);
		for (i = 0; i <= n; ++i) r[i] = l[i] =vis[i]= 0;
		for (i = 0; i <= n; ++i) {
			if (vis[i] == 1) continue;
			int j = i + 1;
			char tgt = 'R';
			while (j <= n && s[j] == tgt) {
				++j;
				tgt = tgt == 'R' ? 'L' : 'R';
			}
			int cnt = j - i - 1;
			
			int k = i;
			while (k<=n &&cnt > 0) {
				vis[k] = 1;
				r[k] = cnt;
				cnt -= 2; k+=2;
			}
		}
		for (i = n; i >= 0; --i) {
			if (vis[i] == 2) continue;
			int j = i;
			char tgt = 'L';
			while (j >=0 && s[j] == tgt) {
				--j;
				tgt = tgt == 'R' ? 'L' : 'R';
			}
			int cnt = i - j;
			int k = i;
			while (k >=0 && cnt > 0) {
				vis[k] = 2;
				l[k] = cnt;
				cnt -= 2; k-=2;
			}
		}
		/*for (i = 0; i <= n; ++i) printf("%d ",l[i] );
		puts(""); 
		for (i = 0; i <= n; ++i) printf("%d ",  r[i]);
		puts("");*/
		for (i = 0; i <= n; ++i) printf("%d ",1+l[i]+r[i]);
		puts("");
	}
	
 
	return 0;
}