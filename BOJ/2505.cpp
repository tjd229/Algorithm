//implementation
#include <stdio.h>
int num[10001];
int pos(int x, int N) {
	for (int i = 1; i <= N; ++i)
		if (num[i] == x) return i;
	return 0;
}
void _rev(int s, int e) {
	while (s < e) {
		num[s] ^= num[e] ^= num[s] ^= num[e];
		++s; --e;
	}
}
int main() {
	int i, N;
	for (scanf("%d", &N), i = 1; i <= N; ++i) scanf("%d",num+i);
	int order = 0;
	for (i = 1; i <= N && order==0; ++i) {
		if (i != num[i]) 
			order = i;
		
	}
	if (order == 0) printf("1 1\n1 1");
	else {
		int s1 = order, e1 = pos(order,N);
		int s2, e2;
		_rev(s1, e1);
		int order2 = 0;
		for (i = 1; i <= N && order2 == 0; ++i) {
			if (i != num[i]) order2 = i;
		}
		if (order2 == 0) s2 = e2 = 1;
		else {
			s2 = order2; e2 = pos(order2,N);
			_rev(s2, e2);
			int order3 = 0;
			for (i = 1; i <= N && order3 == 0; ++i) {
				if (i != num[i]) order3 = i;
			}
			if (order3) {
				_rev(s2, e2); _rev(s1, e1);
				order = 0;
				for (i = N; i >0 && order == 0; --i) {
					if (i != num[i])
						order = i;
				}
				e1 = order; s1 = pos(order, N);
				_rev(s1, e1);
				order = 0;
				for (i = N; i > 0 && order == 0; --i) {
					if (i != num[i])
						order = i;
				}
				e2 = order, s2 = pos(order, N);
			}
		}
		printf("%d %d\n%d %d",s1,e1,s2,e2);
	}

	return 0;
}