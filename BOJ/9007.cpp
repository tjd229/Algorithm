//category : MITM

#include <stdio.h>
#include <algorithm>
using namespace std;
int kss[4][1000];
int p1[1000 * 1000+1];
int main(){
	int i,j,l;
	int T;
	int n, k;
	int p2;
	int d,ans;
	for (scanf("%d", &T); T--;){
		scanf("%d%d",&k,&n);
		d = 80000000;
		ans = 80000000;
		for (i = 0; i < 4; i++){
			for (j = 0; j < n; j++)
				scanf("%d",&kss[i][j]);
		}
		l = 0;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++)
				p1[l++] = kss[0][i] + kss[1][j];
		}
		
		sort(p1, p1 + l);
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				p2 = kss[2][i] + kss[3][j];
				int *it = lower_bound(p1,p1+l,k-p2);
				if (it != &p1[l]){
					int c = *it + p2;
					int t = abs(k-c);
					if (d > t){
						d = t;
						ans = c;
					}
					else if (d == t){
						if (ans > c) ans = c;
					}
					//printf("%d:%d,%d->%d,%d\n",c,p2,k-p2,it,&p1[l+1]);
				}
				//it = lower_bound(p1, p1 + l, k - p2-1);
				if (it != &p1[0]){
					it--;
					int c = *it + p2;
					int t = abs(k - c);
					if (d > t){
						d = t;
						ans = c;
					}
					else if (d == t){
						if (ans > c) ans = c;
					}
					//printf("%d:%d,%d->%d,%d\n",c,p2,k-p2,it,&p1[l+1]);
				}
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}