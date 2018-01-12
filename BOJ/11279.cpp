//category : implementation
#include <stdio.h>
int q[100001];
int sz;
void swap(int &a, int &b){ a ^= b ^= a ^= b; }
void push(int x){
	int ix = ++sz;
	q[ix] = x;
	while (ix > 1&&q[ix]>q[ix>>1]){
		swap(q[ix] , q[ix >> 1]);
		ix >>= 1;
	}
}
int pop(){
	int res = q[1];
	int curr,nxt;
	q[1] = q[sz--];
	curr = 1;
	while (curr <= sz){
		nxt = curr + curr;
		if (nxt > sz) break;
		if (nxt + 1 <= sz&&q[nxt] < q[nxt + 1]) nxt++;
		if (q[nxt] <= q[curr]) break;
		swap(q[nxt], q[curr]);
		curr = nxt;
	}
	return res;
}
int main(){
	int N;
	int x;
	for (scanf("%d", &N); N--;){
		scanf("%d",&x);
		if (x){
			push(x);
		}
		else{
			printf("%d\n",sz? pop():0);
		}
	}
	return 0;
}
