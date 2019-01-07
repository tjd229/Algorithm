//graph


 #include <stdio.h>
int d[1001], rd[1001];
int main() {
	int i;
	int n, s;
	bool flag = false;
	for (scanf("%d%d", &n, &s), i = 1; i <= n; ++i) 
		scanf("%d",d+i);
	
	for (i = 1; i <= n; ++i) scanf("%d",rd+i);
	flag = d[s]&&d[1];
	if (d[1] == 0) printf("NO");
	else if (!flag && rd[s] == 0) printf("NO");
	else {
		for (i = s; i <= n; ++i) {
			if (d[i] && rd[i]) flag = true;
		}
		printf("%s",flag? "YES":"NO");
	}
	
	return 0;
}
