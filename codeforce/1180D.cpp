//greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int n, m;
void print(int xy) {
	int x = xy / m;
	int y = xy % m;
	printf("%d %d\n",x+1,y+1);
}
int main() {
	cin >> n >> m;
	int nm = n * m;
	int l = 0, r = nm-1;
	while (l <= r) {
		print(l++);
		if (l<=r) print(r--);
	}
	return 0;
}