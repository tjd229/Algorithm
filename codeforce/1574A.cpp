//greedy
#include <stdio.h>
int main() {
	int t; 
	for (scanf("%d", &t); t--;) {
		int i, n; scanf("%d",&n);
		int head = 1;
		for (i = 0; i < n; ++i) {
			for (int j = 0; j < head; ++j) printf("(");
			for (int j = 0; j < head; ++j) printf(")");
			int tail = n - head;
			for (int j = 0; j < tail; ++j)
				printf("()");
			++head; puts("");
			
		}
	}
 
	return 0;
}