//category : djs

#include <stdio.h>
int p[1000001];
int find(int a){
	if (p[a] != a) p[a]=find(p[a]);
	return p[a];
}
void join(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main(){
	int T;
	int tc = 1;
	int i;
	int n,m, a, b;
	int inst;
	for (scanf("%d", &T); tc <= T; tc++){
		scanf("%d%d",&n,&m);
		for (i = 1; i <= n; i++) p[i] = i;
		printf("#%d ",tc);
		while (m--){
			scanf("%d%d%d",&inst,&a,&b);
			if (inst) printf("%d",find(a)==find(b));
			else join(a, b);
		}
		printf("\n");
	}

	return 0;
}
