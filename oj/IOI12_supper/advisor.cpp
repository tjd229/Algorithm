//category : greedy

#include "advisor.h"
int sz=1;
struct NUse{
	int ix;
	int nxt;
	bool operator<(NUse &nu) const{
		return nxt < nu.nxt;
	}
}q[150001];
void swap(int &a, int &b){ a ^= b ^= a ^= b; }
void push(NUse nu){
	q[sz] = nu;
	int curr = sz++;
	while (curr != 1){
		if (q[curr>>1] < q[curr]){
			swap(q[curr].ix, q[curr >> 1].ix);
			swap(q[curr].nxt, q[curr >> 1].nxt);
		}
		else break;
		curr >>= 1;
	}
}
void pop(){
	q[1] = q[--sz];
	int curr = 1;
	int nxt = 2;
	while (nxt < sz){		
		if (nxt + 1 < sz && q[nxt] < q[1+nxt])
			nxt++;
		if (q[curr] < q[nxt]){
			swap(q[curr].ix, q[nxt].ix);
			swap(q[curr].nxt, q[nxt].nxt);
			curr = nxt;
			nxt += nxt;
		}
		else break;
	}
}
void ComputeAdvice(int *C, int N, int K, int M) {
	int nxt[100000] = { 0 };
	bool inq[100000] = { 0 };
	int right[100000];
	int left[100000];
	int a[150001] = { 0 };
	int i;
	
	for (i = 0; i < N; i++) right[i] = 100001;
	for (i = N - 1; i >= 0; --i){
		nxt[i] = right[C[i]];
		right[C[i]] = i;
	}	
	for (i = 0; i < K; i++) push({ i, right[i] }), inq[i] = 1, left[i]=i;
 
	for (i = 0; i < N; i++){
		while (!inq[q[1].ix]) pop();
		if (!inq[C[i]]){
			a[ left[q[1].ix] ] = 1;
			inq[q[1].ix] = 0;
			pop();
		}
		push({ C[i], nxt[i] });
		inq[C[i]] = 1;
		left[C[i]] = K+i;
	}
	for (i = 0; i < N + K; i++) WriteAdvice(a[i]^1);
 
	/*WriteAdvice(0);
	WriteAdvice(1);
	WriteAdvice(2);*/
 
}
