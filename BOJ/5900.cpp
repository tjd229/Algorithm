//category : math


#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int> > pos;
int main(){
	int i,j;
	int N, K;
	int num;
	int deno;
	int com = 1;
	int digit = 0;
	vector<int> v;
	scanf("%d%d", &N, &K);
	printf("1");
	if (K == 1){
		while (--N) printf("0");
		return 0;
	}
	num = K;
	deno = 1;
	while (N>com){
		N -= com;
		com *= num;
		com /= deno;
		num++; deno++;
		digit++;
	}
	for (i = K - 1; i > 0; i--){
		v.push_back(i);
	}
	for (i = 2; i <= N; i++){
		j = K - 2;
		v[j]++;
		while (j>=1&&v[j] == v[j - 1]){
			v[j] = K - 1 - j;
			j--;
			v[j]++;
		}
	}

	j = 0;
	for (i = digit+K-1; i>0;i--){
		if (j<v.size()&&i == v[j]){
			printf("1");
			j++;
		}
		else printf("0");
	}
	return 0;
}