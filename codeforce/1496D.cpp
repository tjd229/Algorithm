//game
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int p[100002];
int ru[100002], rd[100002], ld[100002], lu[100002];
int w[100002];
void print(int *a, int n) {
	for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
	puts("");
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d", p + i);
	for (i = 1; i <= n; ) {
		if (i + 1 > n) break;
		if (p[i + 1] > p[i]) {
			int j = i;
			while (j + 1 <= n && p[j + 1] > p[j]) ++j;
			ld[i] = 0; ru[j] = 0;
			for (int k = i + 1; k <= j; ++k) {
				ld[k] = ld[k - 1] + 1;
			}
			for (int k = j - 1; k >= i; --k) ru[k] = ru[k + 1] + 1;
			i = j;
		}
		else {
			int j = i;
			while (j + 1 <= n && p[j + 1] < p[j]) ++j;
			lu[i] = 0; rd[j] = 0;
			for (int k = i + 1; k <= j; ++k) {
				lu[k] = lu[k - 1] + 1;
			}
			for (int k = j - 1; k >= i; --k) rd[k] = rd[k + 1] + 1;
			i = j;
		}
	}
	for (i = 1; i <= n; ++i)
		w[i] = ld[i] > 0 && rd[i] > 0;
	int mx = 0;
	//print(w, n);
	for (i = 1; i <= n; ++i) {
		//if (mx < ru[i]) 
			//mx = ru[i];
		if (mx < lu[i]) mx = lu[i];
		if (ld[i]) {
			int D = i - ld[i];
			if ((ld[i] & 1) == 0) ++D;
			if (i - D >= rd[i]) w[i] = 0;
		}
		if (mx >= rd[i]) w[i] = 0;
		if (ld[i + 1] == 0 && mx < ld[i]) mx = ld[i];
	}
	//print(w, n);
	mx = 0;
	for (i = n; i > 0; --i) {
		if (mx < ru[i])
			mx = ru[i];
		if (rd[i]) {
			int D = i + rd[i];
			if ((rd[i] & 1) == 0) --D;
			if (D - i >= ld[i]) w[i] = 0;
		}
		if (mx >= ld[i]) w[i] = 0;
		if (rd[i - 1] == 0 && mx < rd[i]) mx = rd[i];
	}
	//print(w, n);
	int ans = 0;
	for (i = 1; i <= n; ++i) ans += w[i];
	printf("%d\n", ans);
 
	//print(ru, n); print(rd, n); print(ld, n); print(lu, n);
 
	return 0;
}