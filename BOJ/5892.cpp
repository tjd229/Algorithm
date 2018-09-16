//dp

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> from, to;
int d[1000][1000];
int min(int a, int b){ return a < b ? a : b; }
int main(){
	int i, j;
	int N, Y, X, Z;
	int A, B;
	for (scanf("%d%d%d%d", &N, &X, &Y, &Z), i = 1; i <= N; i++){
		for (scanf("%d%d", &A, &B); A--;) from.push_back(i); 
		while (B--) to.push_back(i);
	}
	if (to.empty()) printf("%d",from.size()*Y);
	else if (from.empty()) printf("%d",to.size()*X);
	else{
		for (i = 0; i < from.size(); i++){
			for (j = 0; j < to.size(); j++){
				if (i + j == 0) continue;
				d[i][j] = 2e9;
				if (i > 0)
					d[i][j] = min(d[i][j], d[i - 1][j] + Y);//remove
				if (j > 0)
					d[i][j] = min(d[i][j], d[i][j - 1] + X);
				int dist = from[i] - to[j];
				if (dist < 0) dist = -dist;
				if (i > 0 && j > 0)
					d[i][j] = min(d[i][j], d[i - 1][j - 1] + Z*dist);
			}
		}
		printf("%d\n", d[from.size() - 1][to.size() - 1]);
	}

	return 0;
}
