//category : greedy

#include <stdio.h>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
pii candi[100000];
int main(){
	int i;
	int N;
	int T;
	for (scanf("%d", &T); T--;){
		int cnt = 0;
		int point = 1e6 + 1;
		for (scanf("%d", &N), i = 0; i < N; i++) scanf("%d%d", &candi[i].first, &candi[i].second);
		sort(candi, candi + N);
		for (i = 0; i < N && point!=1; i++){
			if (point > candi[i].second){
				cnt++;
				point = candi[i].second;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
