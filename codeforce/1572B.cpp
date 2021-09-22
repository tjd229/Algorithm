//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[200001];
void op(int i) {
	int res = a[i] ^ a[i + 1] ^ a[i + 2];
	a[i] = a[i + 1] = a[i + 2] = res;
}
vector<int> push_left(int i) {
	vector<int> v;
	while (i-2>=1 &&a[i] == 0 && a[i - 1] == 1 && a[i - 2] == 1) {
		op(i - 2); v.push_back(i - 2);
		i -= 2;
	}
	return v;
}
vector<int> push_right(int i,int n) {
	vector<int> v;
	while (i+2<=n && a[i] == 0 && a[i +1] == 1 && a[i + 2] == 1) {
		op(i); v.push_back(i);
		i += 2;
	}
	return v;
}
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n;
		vector<int> v,ans;
		int cum = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", a + i); cum += a[i];
		}
		if (cum == 0) {
			printf("YES\n0\n");
			continue;
		}
		else if ((cum & 1) || cum==n) {
			printf("NO\n");
			continue;
		}
		int cur = 1;
		if (a[1]) {
			cum = a[1];
			cur = 2;
			while (cur <= n && a[cur])cum+=a[cur],++cur;
			if (cum & 1) {
				--cur;
				bool y = 1;
				while (cur<=n && a[cur]) {
					if (cur + 2 <= n) {
						if (a[cur] + a[cur + 1] + a[cur + 2] == 3) {
							cur += 2;
						}
						else if (a[cur + 1] + a[cur+2] == 0) {
							ans.push_back(cur); op(cur);
							cur += 2;
						}
						else if (a[cur+1] == 0 && a[cur + 2] == 1) {
							ans.push_back(cur ); op(cur);
							auto push_vec = push_left(cur);
							ans.insert(ans.end(), push_vec.begin(), push_vec.end());
							cur += 3;
							break;
						}
						else {//110
							auto push_vec = push_left(cur+2);
							ans.insert(ans.end(), push_vec.begin(), push_vec.end());
							cur += 3;
							break;
						}
					}
					else {
						y = 0;
						break;
					}
				}
				if (y == 0) {
					printf("NO\n");
					continue;
				}
			}
			else {
				ans = push_left(cur);
			}
			
		}
		cur = 1;
		while (cur+2 <= n) {
			if (a[cur]==0 && a[cur + 1] + a[cur + 2] == 2) {//011
				op(cur); ans.push_back(cur);
				cur += 2;
			}
			else if (a[cur]) {//1??
				int st = cur - 1;
				while (1) {
					if (cur+2<=n &&a[cur + 1] + a[cur + 2] == 2)//111{
						cur += 2;
					else if (cur + 2 <= n && a[cur + 1] + a[cur + 2] == 0) {//100
						op(cur); ans.push_back(cur);
						cur += 2;
					}
					else if (cur + 2 <= n && a[cur + 1]==0 && a[cur + 2] == 1) {//101
						op(cur); ans.push_back(cur);
						break;
					}
					else {//110 -> even 
						break;
					}
				}
				auto push_vec = push_right(st, n);
				ans.insert(ans.end(), push_vec.begin(), push_vec.end());
			}
			else ++cur;
 
		}
		cum = 0;
		for (i = 1; i <= n; ++i) cum += a[i];
		if (cum==0) {
			printf("YES\n%d\n",ans.size());
			for (auto x : ans) printf("%d ",x);
			puts("");
		}
		else printf("NO\n");
	}
 
	return 0;
}