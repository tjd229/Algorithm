//category : greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[200001];
vector<int> sq;
//is sq
int dist(int n){
	if (n == 0) return 0;
	auto it = lower_bound(sq.begin(),sq.end(),n);
	int res=*it-n;
	it--;
	if (res > n-*it) res = n-*it;
	return res;
}
int main(){
	//freopen("ii.txt", "r", stdin);
	int i, j;
	int n;
	int d;
	int A, B;
	long long ans = 0;
	vector<int> cb,ca;
	A = B = 0;
	scanf("%d",&n);
	for (i = 0; i*i<1e9; i++){
		sq.push_back(i*i);		
	}
	sq.push_back(i*i);
	/*printf("!!%d\n", i*i-(int)1e9);
	i--;
	printf("!!%d\n",(int)1e9-i*i);*/
	for (i = 1; i <= n; i++){
		scanf("%d", a + i);
		d = dist(a[i]);
		if (d == 0){ //sq
			A++;
			ca.push_back(-a[i]);
		}
		else{
			B++;
			cb.push_back(d);
		}
	}
	sort(cb.begin(), cb.end());
	sort(ca.begin(), ca.end());
	if (A == B) printf("0");
	else if (A < B){
		j = B - A;
		j /= 2;
		for (i = 0; i < j; i++) ans += cb[i];
		printf("%I64d",ans);
	}
	else{
		j = A-B;
		j /= 2;
		for (i = 0; i < j; i++) ans += ca[i] == 0 ? 2 : 1;
		printf("%I64d", ans);
	}

	



	return 0;
}
