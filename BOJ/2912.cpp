//category : merge st

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define Node pair<int,int>
const int LEAF = 1 << 19;
Node st[LEAF + LEAF];
vector<int> pos[10001];
Node merge_node(Node n1,Node n2){
	Node n=make_pair(0,0);
	if (n1.first == n2.first || n1.second == 0 || n2.second==0){
		n.first = n1.first | n2.first;
		n.second = n1.second + n2.second;
	}
	else{
		n.second = n1.second - n2.second;
		n.first = n1.first;
		if (n.second < 0){
			n.second = -n.second;
			n.first = n2.first;
		}
		if (n.second == 0) n.first = 0;
	}
	return n;
}
Node query(int ix, int s, int e, int from, int to){
	if (e<from || s>to) return make_pair(0, 0);
	if (from <= s&&e <= to) return st[ix];
	return merge_node(query(ix + ix, s, (s + e) >> 1, from, to), query(ix + ix+1, 1+((s + e) >> 1),e, from, to));
}
void update(int ix,int clr){
	Node n = make_pair(clr, 1);
	while (ix!=0){
		st[ix] = merge_node(st[ix], n);
		ix >>= 1;
	}
}
int main(){
	int i;
	int N, C;
	int M;
	int A, B;
	int clr;
	int cnt;
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	Node n;
	scanf("%d%d",&N,&C);
	for (i = 1; i <= N; i++){
		scanf("%d",&clr);
		update(LEAF + i - 1, clr);
		pos[clr].push_back(i);
	}
	scanf("%d",&M);
	while (M--){
		scanf("%d%d",&A,&B);
		n = query(1,0,LEAF-1,A-1,B-1);
		clr = n.first;
		cnt = upper_bound(pos[clr].begin(), pos[clr].end(), B) - lower_bound(pos[clr].begin(), pos[clr].end(), A);
		if (cnt+cnt > (B-A)+1)  printf("yes %d\n", clr);
		else printf("no\n");
	}

	return 0;
}