//category : dp

#include <stdio.h>
#include <queue>
using namespace std;
#define MAXVAL 1000
int pp[16][16];
int d[1 << 16];
int c[1 << 16];
int min(int a, int b){ return a < b ? a : b; }
int main(){
	int N,P;
	int i, j;
	int ix = 0;
	int on = 0;
	int ans = MAXVAL;
	char s[16];
	queue<pair<int, int> > q;
	pair<int, int> curr;

	scanf("%d", &N);
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) scanf("%d",&pp[i][j]);
	scanf("%s",s);
	scanf("%d", &P);
	
	
	for (i = 0; i < N; i++){
		if (s[i] == 'Y') on++, ix |= (1 << i);
	}
	if (P <=on) return printf("0");
	if(on!=0) q.push(make_pair(ix, on));

	while (!q.empty()){
		curr = q.front();
		q.pop();
		if (curr.second == P) break;
		
		for (i = 0; i < N; i++){
			if ( !(curr.first&(1 << i)) ){
				ix = curr.first | (1 << i);
				if (c[ix] == 0){
					d[ix] = MAXVAL;					
				}				

				for (j = 0; j < N; j++){
					if (curr.first&(1 << j)) d[ix] = min(d[ix], d[curr.first] + pp[j][i]);
				}

				if (c[ix] == 0&&d[ix]!=MAXVAL){				
					q.push(make_pair(ix, curr.second + 1));					
				}
				c[ix] = 1;
				if(curr.second==P-1) ans = min(ans, d[ix]);
			}
				
		}

	}
	if (ans == MAXVAL) ans = -1;
	printf("%d",ans);

	return 0;
}