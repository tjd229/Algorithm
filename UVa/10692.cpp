//Huge mode
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1633
//category : math
#include <stdio.h>
#include <vector>
using namespace std;


int a[10];
int pow(int n,int e,int m){
	int res = 1;
	bool flag = true;
	while (e != 0){
		if (e & 1) res *= n;
		if (res >= m) res %= m, flag = false;
		e >>= 1;
		n *= n;
		if (n >= m) n %= m, flag = false;
	}
	if (flag) res = -res;
	return res;
}
int huge_pow(int s,int e,int m){
	if (e - s == 1){
		if (a[s] >= m) return a[s] % m;
		return -a[s];
	}
	if (e - s == 2){
		return pow(a[s], a[s + 1], m);
	}
	int pool[10000];
	int single[10000];
	int i;
	int b = -1;		//mod start index
	//pool[0] = pow(a[s], a[s + 1], m);
	pool[0] = a[s];
	if (pool[0] >= m){
		pool[0] %= m;
		b = 0;
	}	
	for (i = 1; i < 10000; i++){
		pool[i] = pow(pool[i-1],a[s+1],m);
		if (pool[i] < 0) pool[i] = -pool[i];
		else if (b < 0) b = i;
		//if (a[s]>=m)
		//printf("p:%d\n",pool[i]);
		//if (pool[i] >= m) pool[i] %= m;
		if (pool[0] == pool[i]) break;
		
	}
	//return 0;
	int d = 0;
	if (i == 10000){
		int j, k;
		for (j = 1; j < 10000 && i == 10000; j++){
			for (k = 0; k < j&&i==10000; k++){
				if (pool[k] == pool[j]){
					i = j - k;
					d = k;
					for (int l = k-1; l >= 0; l--){
						single[l] = pool[l];
						pool[l] = pool[l + i];
						//printf("%d<-%d\n",l,l+i);
					}
				}
			}
		}
	}

	int res = huge_pow(s + 2, e, i);
	int sign = 1;
	if (res < 0){
		res = -res;
		if (res < b) sign = -1;
		if (res<d)
			return single[res]*sign;
	}
	//if (res < b) sign = -1;
	//printf("res:%d\n",pool[res]);
	return pool[res]*sign;
}
int main(){
	int T = 1;
	int N, M;
	int i;
	while (scanf("%d%d", &M, &N) == 2){
		for (i = 0; i < N; i++){
			scanf("%d",a+i);
		}
		//printf("%d\n",pow(M,N,1000000));
		i = huge_pow(0, N, M);
		if (i < 0) i = -i;
		printf("Case #%d: %d\n",T++,i);
	}


}