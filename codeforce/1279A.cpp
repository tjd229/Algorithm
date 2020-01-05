//math
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int clr[3]; scanf("%d%d%d",clr,clr+1,clr+2);//r>g>b
		sort(clr, clr + 3);
		clr[2] -= clr[0];
		if (clr[2] > clr[1] + 1) printf("NO\n");
		else printf("YES\n");		
		
	}
	return 0;
}