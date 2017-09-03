//category : greedy

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int main(){
	int N, M, K;
	int i,j,l;
	scanf("%d%d%d", &N, &M, &K);
	if (N<M + K - 1 || N>M*K) printf("-1");
	else{
		for (i = N; i > 0;){
			vector<int> v;
			l = i - (M-1);
			if (l > K) l = K;
			for (j = 0;j<l;j++){
				v.push_back(i);
				i--;
			}
			M--;
			sort(v.begin(), v.end());
			for (j = 0; j < l; j++) a.push_back(v[j]);
		}
		for (i = N - 1; i >= 0;i--){
			printf("%d ",a[i]);
		}
	}
	return 0;
}