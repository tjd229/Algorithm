//category : greedy



#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
	int N;
	int i;
	int sum;
	scanf("%d",&N);
	for (i = 0; i < N; i++) scanf("%d", &sum), v.push_back(sum);
	sort(v.begin(), v.end());
	for (i = sum = 0; i < N; i++) sum += (N-i)*v[i];
	printf("%d",sum);
	return 0;
}
