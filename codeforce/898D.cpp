//category : greedy
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int a[200001];

deque<int> dq;
int main(){
	int i, j;
	int n, m, k;
	int cnt = 0;
	scanf("%d%d%d",&n,&m,&k);
	for (i = 1; i <= n; i++){
		scanf("%d",a+i);
	}
	sort(a + 1, a + 1 + n);
	for (i = 1; i <= n; i++){
		while (!dq.empty() && dq.front() <= a[i] - m) dq.pop_front();
		/*dq.push_back(a[i]);
		while (dq.size() >= k){
			printf("!%d,%d\n",i,dq.front());
			dq.pop_front();
			cnt++;
		}*/
		if (dq.size() + 1 < k){
			dq.push_back(a[i]);
		}
		else cnt++;// , printf("%d!\n", i);
	}
	printf("%d",cnt);

	return 0;
}
