//graph, greedy

#include <stdio.h>
#include <vector>
#include <deque>
using namespace std;
int cnt[1001];
int main() {
	int n, i;
	int a, b;
	int e = 0;
	bool flag = 1;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		scanf("%d%d",&a,&b);
		flag &= (a == n || b == n);
		++cnt[a];
		++cnt[b];
	}
	if (!flag) printf("NO");
	else {
		deque<int> r;
		vector<int> order;
		for (i = 1; i < n && flag; ++i) {
			if (cnt[i]) {
				order.push_back(i);
				while (--cnt[i]) {
					if (r.empty()) {
						flag = 0;
						break;
					}
					order.push_back(r.front());
					r.pop_front();					
				}
			}
			else r.push_back(i);
		}
		printf("%s",flag? "YES\n":"NO");
		if (flag) {
			for (i = 1; i < order.size(); ++i) printf("%d %d\n",order[i-1],order[i]);
			printf("%d %d",order.back(), n);
		}
	}

	return 0;
}
