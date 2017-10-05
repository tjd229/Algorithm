//category : bs, pst, merge st
//idea reference : http://koosaga.com/104

#include <stdio.h>
#include <algorithm>
#define MAX(a,b) a<b? b:a
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int LEAF = 1 << 17;
pii fence[(int)1e5+1];
int cnt;
int root[(int)1e5+1];
struct Node{
	int from_l, from_r, val,range;
	int l, r;
	void init(int n){
		from_l = from_r = val = n;
		l = r = 0;
		range = 1;
	}
}node[(int)1e5*20];


void mrg(Node &n, Node l, Node r){
	n.from_l = l.from_l;	//s~m
	if (l.range == l.from_l) n.from_l += r.from_l;	//s~m~r'
	n.from_r = r.from_r;	//m~e
	if (r.range == r.from_r) n.from_r += l.from_r;	//l'~m~e
	n.val = MAX(l.val, r.val);
	n.val = MAX(n.val, l.from_r + r.from_l);	//s~m or m~e or l'~r'
	n.range = l.range + r.range;
}
int make_tree(int pre,int s,int e,int from, int to, int val){
	if (e < from || to < s) return pre;
	int ix = ++cnt;
	if (s == e){
		node[ix].init(val);		
		return ix;
	}
	node[ix].l = make_tree(node[pre].l, s, (s + e) >> 1, from, to, val);
	node[ix].r = make_tree(node[pre].r, 1+((s + e) >> 1),e,from, to, val);
	//mrg
	mrg(node[ix], node[node[ix].l], node[node[ix].r]);
	return ix;
}
Node measure(int ix, int s,int e,int from, int to){
	if (e < from || to < s) return node[0];
	if (s >= from&&to >= e) return node[ix];
	Node l = measure(node[ix].l, s, (s + e) >> 1, from, to);
	Node r = measure(node[ix].r, 1+((s + e) >> 1),e, from, to);
	Node n;
	mrg(n, l, r);
	return n;
}
int main(){
	int i, j;
	int n;
	int m;
	int h;
	int l, r, w;
	int left,right,mid;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &h);
		fence[i] = mp(-h, i);
	}
	sort(fence+1, fence + n+1);
	root[0] = make_tree(0,0,LEAF-1,0,n-1,0); //virtual, O(nlgn)
	for (i = 0; i < n; i++){
		root[i + 1] = make_tree(root[i], 0, LEAF - 1, fence[i].second-1, fence[i].second-1, 1);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++){
		scanf("%d%d%d", &l ,&r , &w);
		left = 1;
		right = n;
		while (left <= right){
			mid = (left + right) >> 1;
			Node n = measure(root[mid],0,LEAF-1,l-1,r-1);
			if (n.val >= w) right = mid - 1;
			else left = mid + 1;
		}
		printf("%d\n",-fence[right].first);
		//printf("%d\n", right);
		
	}

	
	return 0;
}