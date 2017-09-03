//category : game

#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
//vector<pair<int, int> > lose_pos;
int lose_pos[1000000];
vector<int> perm = { 1, 2, 1, 2, 2 };
void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}
int main(){
	int N, M;
	int T;
	int X, Y;
	int d=1;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d",&N,&M);
	//N<M
	if (N > M) swap(N, M);
	
	memset(lose_pos, -1, sizeof(lose_pos));
	lose_pos[0] = 0;
	X = 0;
	Y = 0;
	while (true){
		d = 1;
		while(X+d<M&&lose_pos[X + d] != -1) d++;
		if (X + d >= M) break;
		X += d;
		Y += d + 1;
		lose_pos[X] = Y;
		if (Y<M)
			lose_pos[Y] = X;
	}
	
	scanf("%d",&T);

	while (T--){
		scanf("%d%d",&X,&Y);
		if (X > Y) swap(X, Y);

		printf("%s\n", lose_pos[X] == Y ? "Farmer John" : "Bessie");
	}

	return 0;
}