//math

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> push[20];
int main(){
	int i,j;
	int N;
	int mx = 0;
	scanf("%d",&N);
	for (i = 1; i <= N; i++){
		int b = 1;
		for (j = 0; j < 20; j++){
			if (i&b){
				push[j].push_back(i);
				if (mx < j) mx = j;
			}
			b <<= 1;
		}
	}
	int ans = mx + 1;
	for (i = 0; i <= mx; i++){
		if (push[i].size() <= 1) ans--;
	}
	printf("%d\n",ans);
	for (i = 0; i <= mx; i++){
		if (push[i].size() <= 1) continue;
		printf("%d ",push[i].size());
		for (auto d : push[i]) printf("%d ",d);
		puts("");
	}

}
