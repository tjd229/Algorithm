//game
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> cnt;
int a[100000];
int main() {
	int i, n;
	long long sum = 0;
	for (scanf("%d", &n), i = 0; i < n; ++i) {
		scanf("%d", a + i); sum += a[i];
		++cnt[a[i]];
	}
	if(n==1) printf("%s", a[0] & 1 ? "sjfnb" : "cslnb");
	else if (sum == 0) printf("cslnb");
	else if (sum == 1) printf("cslnb");
	else if (cnt[0] > 1) printf("cslnb");
	else {
		int pair = 0; int st = -1;
		for (auto it : cnt) {
			if (it.second > 1) ++pair,st=it.first;
			if (it.second > 2) {
				printf("cslnb");
				return 0;
			}
			
		}
		if (pair > 1) printf("cslnb");
		else if (pair == 1 && cnt[st - 1]) printf("cslnb");
		else {
			sum = 0;
			sort(a, a + n);
			if (n>2 &&a[2] < 2) printf("cslnb");//011
			else {
				for (i = 0; i < n; ++i) sum += a[i] - i;
				printf("%s",sum&1? "sjfnb":"cslnb");
			}
		}
	}
	return 0;
}