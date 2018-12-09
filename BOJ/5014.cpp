//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
int F, S, G, U, D;
int move(int x,int p,int m){
	int M = 0;
	int d;
	for (int i = 0;i<=1000000; i++,M+=m){
		d = (x + M) / p;
		if (p*d == x + M) return d + i;
	}
	return -1;
}


int main(){
	
	scanf("%d%d%d%d%d",&F,&S,&G,&U,&D);
	if (S == G) return !printf("0");
	if (S<G&&U<1) return !printf("use the stairs");
	if (S>G&&D<1) return !printf("use the stairs");
	int ans;
	if (G - S > 0) ans = move(G - S, U, D);
	if (G - S < 0) ans = move(S-G, D, U);
	if (ans<0) printf("use the stairs");
	else printf("%d",ans);


	return 0;
}
