//category : dp


#include <stdio.h>
char color[500002];
bool visit[500002][27];
int d[500002][27];
char last[500002][27];
int n, k;
int repaint(int ix, int prev){

	if (ix > n) return 0;
	if (visit[ix][prev]) return d[ix][prev];
	visit[ix][prev] = true;
	int to = 0;
	d[ix][prev] = 600000;

	while (to == prev||to==color[ix]-'A' )
		to++;
	if (to != k){
		d[ix][prev] = 1 + repaint(ix + 1, to);
		last[ix][prev] = 'A' + to;
	}

	if ('A'+prev!=color[ix]&&d[ix][prev] > repaint(ix + 1, color[ix] - 'A')){
		d[ix][prev] = repaint(ix + 1, color[ix] - 'A');
		last[ix][prev] = color[ix];
	}

	return d[ix][prev];
}
int main(){
	int i;
	int prev = 26;
	scanf("%d %d ", &n, &k);
	for (i = 1; i <= n; i++){
		scanf("%1c", color + i);
	}
	printf("%d\n", repaint(1, 26));
	for (i = 1; i <= n; i++){
		printf("%c", last[i][prev]);
		prev = last[i][prev] - 'A';
	}
	return 0;
}