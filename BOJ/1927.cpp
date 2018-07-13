//implementation

#include <stdio.h>
int heap[100001];
int sz;
void swap(int &a, int &b){ a ^= b ^= a ^= b; }
void push(int x){
	int ix = ++sz;
	heap[ix] = x;
	while (ix > 1 && heap[ix]<heap[ix>>1]){
		swap(heap[ix], heap[ix >> 1]);
		ix >>= 1;
	}
}
int pop(){
	if (sz == 0) return 0;
	int res = heap[1];
	swap(heap[1], heap[sz]);
	int ix = 1;
	while (ix+ix < sz){
		int nxt = ix + ix;
		if (nxt + 1 < sz && heap[nxt] > heap[nxt + 1]) nxt++;
		if (heap[nxt] >= heap[ix]) break;
		swap(heap[ix], heap[nxt]);
		ix = nxt;
	}
	--sz;
	return res;
}
int main(){
	int N;
	int x;
	for (scanf("%d", &N); N--;){
		scanf("%d",&x);
		if (x) push(x);
		else printf("%d\n",pop());
	}

	return 0;
}
