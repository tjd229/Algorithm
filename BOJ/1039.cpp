//category : implementation

#include <stdio.h>
#include <vector>
using namespace std;
int tenpow[7] = {
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000
};
int digit;
int visit[1000001];
int swap(int n,int a,int b){
	int na = (n / tenpow[a]) % 10;
	int nb = (n / tenpow[b]) % 10;
	if (digit-1 == b&&na == 0) return -1;
	n += (nb - na)*tenpow[a];
	n += (na - nb)*tenpow[b];
	return n;

}
int main(){
	vector<int> v;
	int N, K;
	int i=0;
	int j, k;
	int end=0;
	int depth = 0;
	int max = -1;
	int next;
	scanf("%d%d",&N,&K);
	i = N;
	do{
		i /= 10;
		digit++;
	} while (i != 0);
	

	v.push_back(N);
	while (end != v.size()){
		end = v.size();
		depth++;
		for (; i < end; i++){
			for (j = 0; j < digit-1; j++){
				for (k = j + 1; k < digit; k++){
					next = swap(v[i], j,k);
					if (next != -1&&visit[next]!=depth){
						v.push_back(next);
						visit[next] = depth;
						if (depth == K&&max < next) max = next;
					}
				}
			}
		}
		if (depth == K&&max>-1) return printf("%d",max);
	}
	printf("-1");

	return 0;
}