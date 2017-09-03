//category : dp

#include <stdio.h>

int c[501];
int p[501][501];
int d[501][501];
int visit[501][501];
int min(int a, int b){ return a < b ? a : b; }
int palindrome(int i, int j){
	if (visit[i][j]) return p[i][j];
	visit[i][j] = 1;
	if (i == j) p[i][j] = 1;
	else if (i + 1 == j) p[i][j] = (c[i] == c[j]);
	else p[i][j] = palindrome(i + 1, j - 1)&(c[i] == c[j]);
	return p[i][j];
}
int destory(int s, int e){
	if (d[s][e] != 0) return d[s][e];
	if (palindrome(s, e) == 1){
		d[s][e] = 1;
		return d[s][e];
	}
	d[s][e] = e - s + 1;
	if (c[s] == c[e]) d[s][e] = destory(s + 1, e - 1);
	for (int i = s; i < e; i++){
		if (c[s] != c[i]) continue;
		d[s][e] = min(d[s][e], destory(s, i) + destory(i + 1, e));

	}
	return d[s][e];
}
int main(){
	int i;
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", c + i);
	//palindrome(1, n);
	printf("%d\n", destory(1, n));

	return 0;
}

