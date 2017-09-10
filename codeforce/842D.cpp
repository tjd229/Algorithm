//category : trie, math
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m;
int digit;
int a[300001];
int x[300001];
bool check[300001];
int num_node;
struct Node{
	int nxt[2];
	int family;
}bit[1<<20];
void set_digit(int n){
	do{
		digit++;	
		n >>= 1;
	} while (n != 0);
}
void make_trie(int val,int ix,int d){
	d--;
	if (d<0){
		bit[ix].family = 1;
		return;
	}	
	int nxt = ((1 << d)&val)>0;
	if (bit[ix].nxt[nxt] == 0){
		bit[ix].nxt[nxt] = ++num_node;
	}
	bit[ix].family -= bit[bit[ix].nxt[nxt]].family;
	make_trie(val, bit[ix].nxt[nxt],d);
	bit[ix].family += bit[bit[ix].nxt[nxt]].family;
}
int query(int val,int ix,int d){
	d--;
	if (d < 0) return 0;
	int e = 1 << d;
	int nxt = (e&val)>0;
	if (bit[bit[ix].nxt[nxt]].family == e) nxt ^= 1;
	else e = 0;
	if (bit[ix].nxt[nxt] == 0) return e;
	return query(val, bit[ix].nxt[nxt], d)+e;
}
int main(){
	int i;
	int max_val = 0;
	int last = -1;
	scanf("%d%d",&n,&m);
	for (i = 1; i <= n; i++){
		scanf("%d", a + i);
		check[a[i]] = true;
		if (max_val < a[i]) max_val = a[i];
	}
	for (i = 1; i <= m; i++){
		scanf("%d", x + i);
		if (max_val < x[i]) max_val = x[i];
	}
	sort(a + 1, a + 1 + n);
	set_digit(max_val);

	for (i = 1; i <= n; i++){
		if (last == a[i]) continue;
		make_trie(a[i],0,digit);
		last = a[i];
	}
	for (i = 1; i <= m; i++){
		x[i] ^= x[i - 1];
		if (!check[x[i]]) printf("0\n");
		else printf("%d\n",query(x[i],0,digit));
	}
	return 0;
}
//reference : http://codeforces.com/contest/842/submission/29879716