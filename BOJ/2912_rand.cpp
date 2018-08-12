//math

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
vector<int> pos[10001];
int clr[300001];
int main(){
	int i;
	int N, C;
	int M, A, B;
	
	for (scanf("%d%d", &N, &C), i = 1; i <= N; i++){
		scanf("%d",clr+i);
		pos[clr[i]].push_back(i);
	}
	for (scanf("%d", &M); M--;){
		scanf("%d%d",&A,&B);
		int X = -1;
		int coin = 100;
		int len = B - A + 1;
		int lop = 0;
		while (X==-1 && coin--){
			int loc = rand() % len + A;
			int cnt = upper_bound(pos[clr[loc]].begin(), pos[clr[loc]].end(), B)
				- lower_bound(pos[clr[loc]].begin(), pos[clr[loc]].end(), A);
			
			if (cnt + cnt > len){
				X = clr[loc];
			}
		}
		if (X == -1) printf("no\n");
		else printf("yes %d\n",X);
	}



	return 0;
}
