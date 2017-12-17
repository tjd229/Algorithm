//category : implementation
#include <stdio.h>
int a[24];
int n;
const int G[60] = {
	31, 28, 31, 30, 31,
	30, 31, 31, 30, 31,
	30, 31,
	31, 28, 31, 30, 31,
	30, 31, 31, 30, 31,
	30, 31,
	31, 29, 31, 30, 31,
	30, 31, 31, 30, 31,
	30, 31,
	31, 28, 31, 30, 31,
	30, 31, 31, 30, 31,
	30, 31,
	31, 28, 31, 30, 31,
	30, 31, 31, 30, 31,
	30, 31
};
bool check(int ix){
	for (int i = 0; i < n; i++){
		if (ix + i >= 60) return false;
		if (a[i] != G[ix+i]) return false;
	}
	return true;
}
int main(){
	int i,j;
	int ans = 0;
	
	for (scanf("%d", &n), i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	for (i = 0; i < 60; i++){
		if (a[0] == G[i]){
			if (check(i)){
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}
