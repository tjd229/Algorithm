//category : implementation



#include <stdio.h>
#include <queue>
using namespace std;
int main(){
	int N;
	int x;
	int sign;
	priority_queue<pair<int, int> > q;
	scanf("%d",&N);
	while (N--){
		scanf("%d",&x);
		if (x == 0){
			if (q.empty()) printf("0\n");
			else{
				x = q.top().first*q.top().second;
				printf("%d\n",x);
				q.pop();
			}
		}
		else{
			sign = 1;
			if (x > 0) x = -x,sign=-1;
			q.push(make_pair(x, sign));
		}

	}
	return 0;
}