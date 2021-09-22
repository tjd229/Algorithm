//math
#include <stdio.h>
#include <set>
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int a, b; scanf("%d%d",&a,&b);
		if (a > b) a ^= b ^= a ^= b;
		int ba, bb; int ab = a + b;
		set<int> st;
		ba = ab >> 1; bb = ab - ba;
		int s = ba - a;
		int num_pair = a < b ? a : b;
		for (int i = 0; i <= num_pair; ++i,s+=2) {
			st.insert(s); st.insert(ab - s);
		}
		printf("%d\n",st.size());
		for (auto it : st)
			printf("%d ",it);
		puts("");
	}
 
	return 0;
}