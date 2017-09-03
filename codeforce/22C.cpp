//category : graph, greedy

#include <stdio.h>

int sigma(int n){
	int d = n / 2;
	int res = d*(n + 1);
	if (n & 1) res += (n + 1) / 2;
	return res;
}
bool is_cong(int a,int b,int c){
	return a == c||b == c;
}
int main(){
	int i,j;
	int n, m, v;
	int isle = 1;
	int left;
	int cnt;
	//isle 1 or 2, center v, left n or n-1 
	scanf("%d%d%d",&n,&m,&v);
	if (m < n - 1){
	  printf("-1");  
	  return 0;
	} 
	if (m>sigma(n - 2) + 1){
	  printf("-1");  
	  return 0;
	} 
	if (isle == v) isle = 2;
	left = v == n ? n - 1 : n;
	for (i = isle + 1; i < n; i++){
		if (i == v || i +1 == v) continue;
		printf("%d %d\n",i,i+1);
	}
	if (v > 2 && v < left) printf("%d %d\n",v-1,v+1);
	printf("%d %d\n", v, left);
	printf("%d %d\n", v, isle);
	cnt = n - 1;
	if (cnt == m) return 0;
	for (i = 1; i <= n; i++){
		if (i == isle) continue;
		for (j = i + 1; j <= n; j++){
			if (j == isle) continue;
			if (is_cong(i, j, v)&&is_cong(i,j,left)) continue;
			if (is_cong(i, j, v - 1) && is_cong(i, j, v + 1)) continue;
			if (j == i + 1 && !is_cong(i, j, v)) continue;
			printf("%d %d\n",i,j);
			if ((++cnt) == m) return 0;
		}
	}

	return 0;
}
