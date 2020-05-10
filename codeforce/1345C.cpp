//math
#include <stdio.h>
#include <set>
using namespace std;
int a[200001];
int n;
int mymod(int x) {
	int res = x % n;
	if (res < 0) res += n;
	return res;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i;
		for (scanf("%d", &n), i = 0; i < n; ++i) scanf("%d",a+i);
		set<int> st;
		bool flag = 1;
		for (i = 0; i < n && flag; ++i) {
			int nxt = mymod(i + a[i]);
			
			if (st.find(nxt) != st.end())
				flag = 0;
			else st.insert(nxt);
			
		}
		printf("%s\n",flag? "YES":"NO");
	}
	return 0;
}
