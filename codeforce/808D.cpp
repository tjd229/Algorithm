//category : implementation

#include <stdio.h>
#include <set>
#define ll long long
using namespace std;
int a[100001];
ll sum[100001];
int main(){
	int n;
	int i;
	ll lsum, rsum,d;
	multiset<ll> l, r;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d",a+i);
		sum[i] = sum[i - 1] + a[i];
		r.insert(a[i]);
	}
	if (sum[n]&1){
		printf("NO");
		return 0;
	}
	for (i = 0; i < n; i++){
		lsum = sum[i];
		rsum = sum[n] - lsum;
		if (lsum > rsum){
			d = lsum - rsum;
			if ((d & 1) == 0){
				d >>= 1;
				if (l.find(d)!=l.end()){
					printf("YES");
					return 0;
				}
			}
		}
		else if (lsum < rsum){
			d = rsum - lsum;
			if ((d & 1) == 0){
				d >>= 1;
				auto it = r.find(d);
				if (r.find(d)!=r.end()){
					printf("YES");
					return 0;
				}
			}
		}
		else{
			printf("YES");
			return 0;
		}

		r.erase(r.find(a[i+1]));
		l.insert(a[i+1]);
	}
	printf("NO");
	

	return 0;
}
