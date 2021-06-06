//st
#include <stdio.h>
#include <queue>
using namespace std;
const int LEAF = 1 << 18;
int st[LEAF + LEAF];
int op[LEAF + LEAF];
int to_node[LEAF];
int k,len;
char s[LEAF];
inline int cmd(int op,int a,int b) {
	if (op == 0) return a;
	else if (op == 1) return b;
	return a + b;
}
void upd(int ix) {
	while (ix) {
		st[ix] = cmd(op[ix], st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
int main() {
	queue<int> q;
	int i; scanf("%d", &k); len = 1 << k;
	for (i = 0; i < len-1; ++i) scanf(" %c",s+i);
	for (i = 0; i < len; ++i) st[len + i] = 1,q.push(len+i);
	i = 0;
	while (q.size() > 1) {
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		int p = a >> 1;
		to_node[i] = p;
		if (s[i] == '?') op[p] = 2;
		else op[p] = s[i] - '0';
		st[p] = cmd(op[p], st[a], st[b]);
		q.push(p); ++i;
	}
	int Q;
	for (scanf("%d", &Q); Q--;) {
		int p;char c; scanf("%d %c", &p, &c);
		--p;
		if (c == '?') op[to_node[p]] = 2;
		else op[to_node[p]] = c-'0';
		upd(to_node[p]);
		printf("%d\n",st[1]);
	}
	
 
 
	return 0;
}