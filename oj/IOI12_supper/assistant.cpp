//category : greedy

#include "assistant.h"
struct Heap{
	int sz = 1;
	int p[150001];
	int ix[150001];
	void swap(int &a, int &b){ a ^= b ^= a ^= b; }
	void push(int _p, int _ix){
		p[sz] = _p;
		ix[sz] = _ix;
		int curr = sz++;
		while (curr != 1 && p[curr] < p[curr >> 1]){
			swap(p[curr], p[curr >> 1]);
			swap(ix[curr], ix[curr >> 1]);
			curr >>= 1;
		}		
	}
	void pop(){
		p[1] = p[--sz];
		ix[1] = ix[sz];
		int curr = 1;
		int nxt = 2;
		while (nxt < sz){
			if (nxt + 1 < sz&&p[nxt] > p[nxt + 1]) nxt++;
			if (p[curr]>p[nxt]){
				swap(p[nxt], p[curr]);
				swap(ix[nxt], ix[curr]);
				curr = nxt;
				nxt += nxt;
			}
			else break;
		}
	}
}pq;
void Assist(unsigned char *A, int N, int K, int R) {
 
	int i;
	int a_ix = 0;
	bool inq[100000] = { 0 };
	for (i = 0; i < K; i++){
		pq.push(A[a_ix++],i);
		inq[i] = 1;
	}
	for (i = 0; i < N; i++){
		int req = GetRequest();
		while (!inq[pq.ix[1]]) pq.pop();
		if (!inq[req]){
			PutBack(pq.ix[1]);
			inq[pq.ix[1]] = 0;
			pq.pop();
		}
		pq.push(A[a_ix++],req);
		inq[req] = 1;
	}
 
 
 
}
