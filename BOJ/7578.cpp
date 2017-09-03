//category : ft



#include <stdio.h>
#include <vector>
using namespace std;
#define BI (1<<19)
long long ft[BI + 1];
int ix[1000001];
void update(int ix,int diff){
	while (ix <= BI){
		ft[ix] += diff;
		ix += (ix&-ix);
	}
}
long long sum(int ix){
	long long s = 0;
	while (ix > 0){
		s += ft[ix];
		ix -= (ix&-ix);
	}
	return s;
}
int main(){
	int N;
	int i;
	int buff;
	vector<int> v;
	scanf("%d",&N);
	for (i = 0; i < N; i++) scanf("%d", &buff), v.push_back(buff);
	for (i = 1; i <= N; i++) scanf("%d", &buff), ix[buff]=i;
	long long ans = 0;
	for (i = 0; i < N; i++){
		ans += (ft[BI] - sum(ix[v[i]]));
		update(ix[v[i]], 1);
	}
	printf("%lld", ans);

	return 0;
}
