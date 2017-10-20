//category : math

#include <stdio.h>
#define ll long long
double e[1000001];
int prime[1000001];
int candi[1000001];
int cnt;
void filter(int N){
	ll i, j;
	
	for (i = 2; i<= N; i++){
		if (prime[i] < 0) continue;
		prime[i] = ++cnt;
		candi[cnt] = i;
		for (j = i*i; j <= N; j += i){
			prime[j] = -1;
		}
	}
	for (i = 2; i <= N; i++){
		if (prime[i] < 0) prime[i] = prime[i - 1];
	}
}
double expected(int n){
	if (n == 1) return 0.f;
	if (e[n] != 0.f) return e[n];
	int ix = prime[n];
	int choice;
	int update = 0;
	e[n] = ix;
	while (ix != 0){
		choice = candi[ix];
		if (n%choice == 0){
			e[n] += expected(n / choice) + 1;
			update++;
			e[n] -= 1;
		}
		ix--;
	}
	e[n] /= (float)update;
	return e[n];
}
int main(){
	int i;
	int tc = 1;
	int T;
	int N;
	filter(1000000);
	for (scanf("%d", &T); T--;tc++){
		scanf("%d",&N);
		printf("Case %d: %f\n",tc,expected(N));
	}

	return 0;
}