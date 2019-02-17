//graph
#include <stdio.h>
#include <stack>
using namespace std;
int l[1001], r[1001];
int pre[1001], in[1001];
int pos[1001];
void dfs(int x) {
	if (l[x] > 0) dfs(l[x]);
	if (r[x] > 0) dfs(r[x]);
	printf("%d ",x);
}
int main() {
	int i, T;
	for (scanf("%d", &T); T--;) {
		int N;
		stack<int> st;
		for (scanf("%d", &N), i = 1; i <= N; ++i) {
			scanf("%d",pre+i);
			l[i] = r[i] = -1;
		}
		for (i = 1; i <= N; ++i) scanf("%d", in + i),pos[in[i]]=i;
		int root = pre[1];
		int u, v;
		st.push(root);
		for (i = 2; i <= N; ++i) {
			u = st.top();
			v = pre[i];
			if (pos[v] < pos[u]) {
				l[u] = v, st.push(v);
				u = v;
			}
			else {
				while (st.size() && pos[st.top()] < pos[v]) {
					u = st.top();
					st.pop();
				}
				r[u] = v;
				st.push(v);
			}
		}
		dfs(root);
		puts("");
	}
	return 0;
}