//implementation
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[6] = {4,8,15,16,23,42};
 
int main() {
	printf("? 1 2\n"); fflush(stdout);
	int a12; scanf("%d", &a12);
	printf("? 2 3\n"); fflush(stdout);
	int a23; scanf("%d", &a23);
	printf("? 4 5\n"); fflush(stdout);
	int a45; scanf("%d", &a45);
	printf("? 5 6\n"); fflush(stdout);
	int a56; scanf("%d", &a56);
	do {
		if (a12 == a[0] * a[1] && a23 == a[1] * a[2]
			&& a45 == a[3] * a[4] && a56 == a[4] * a[5]) {
			int it;
			for (printf("! "), it = 0; it < 6; ++it) printf("%d ", a[it]);
			fflush(stdout);
			break;
		}
	}while(next_permutation(a,a+6));
 
	
	return 0;
}