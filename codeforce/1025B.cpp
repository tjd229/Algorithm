//math, greedy

#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <vector>
#define pii pair<int,int>
#define ll long long
using namespace std;
pii p[150000];
vector<int> candi;
int gcd(int a, int b){
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main(){
	int i;
	int n;
	int a, b;
	bool flag = true;
	for (scanf("%d", &n), i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		p[i] = { a, b };
		flag &= (a % 2 == 0) || (b % 2 == 0);
	}
	if (flag){
		printf("2");
		return 0;
	}
	int ans = -1;

	for (i = 0; i < n; i++){
		a = p[i].first;
		b = p[i].second;
		if ((a & 1) && (b & 1)){
			for (ll num = 1; num*num <= a; num++){
				if (a%num == 0){
					candi.push_back(num);
					candi.push_back(a / num);
				}
			}
			for (ll num = 1; num*num <= b; num++){
				if (b%num == 0){
					candi.push_back(num);
					candi.push_back(b / num);
				}
			}
			break;
		}

	}
	sort(candi.begin(), candi.end());
	candi.resize(unique(candi.begin(), candi.end()) - candi.begin());
	for (auto num : candi){
		if (num == 1) continue;
		flag = true;
		for (i = 0; i < n; i++){
			a = p[i].first;
			b = p[i].second;
			flag &= (a % num == 0) || (b % num == 0);
		}
		if (flag){
			printf("%d", num);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
