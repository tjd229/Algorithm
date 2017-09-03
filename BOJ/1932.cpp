//category : dp

#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

int tri[500][500];
int d[500][500];
int N;
int sumTri(int n,int ix){
	if (ix<0 || ix>n) return 0;
	if (n >= N) return 0;
	if (d[n][ix]!=-1) return d[n][ix];
	int left = sumTri(n + 1, ix )+tri[n][ix];
	int right = sumTri(n + 1, ix + 1) + tri[n][ix];
	d[n][ix]= left < right? right : left;
	return d[n][ix];
}
int main(){

	memset(d, -1, sizeof(d));
	
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		for (j = 0; j <= i; j++) scanf("%d",&tri[i][j]);
	}

	printf("%d",sumTri(0,0));
	return 0;
}

