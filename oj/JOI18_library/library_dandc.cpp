//category : bs

#include <cstdio>
#include <vector>
 
#include "library.h"
using namespace std;
bool use[2000];
vector<int> v1, v2;
int find(int left,int N){
	
	vector<int> M(N);
	int i;
	for (i = 0; i < v1.size(); i++) M[v1[i]] = 1;
	
	int a = Query(M);
	M[left] = 1;
	int b = Query(M);
	vector<int> *live, *erase;
	if (a == b) live = &v1, erase = &v2;
	else live = &v2, erase = &v1;
	if (live->size() == 1) return live->back();
 
	erase->clear();
	for (i = 0, b = live->size() / 2; i < b; i++){
		a = live->back();
		live->pop_back();
		erase->push_back(a);
	}	
	return find(left, N);
}
void Solve(int N)
{
	vector<int> M(N);
	vector<int> res;
	int i,j;
	int A;
	if (N == 1){
		res.push_back(1);
		Answer(res);
		return;
	}
	for (i = 0; i < N; i++) {
		M[i] = 1;
	}
	for (i = 0; i < N; i++){
		M[i] = 0;
		A = Query(M);
		if (A == 1){
			res.push_back(i + 1);
			use[i] = 1;
			break;
		}
		M[i] = 1;
	}
	int t = 1;
	for (i = 1; i < N; i++){
		t = 1;
		v1.clear();
		v2.clear();
		for (j = 0; j < N; j++){
			if (use[j]) continue;
			if (t) v1.push_back(j);
			else v2.push_back(j);
			t ^= 1;
		}
		if (i == N - 1){
			res.push_back(v1[0]+1);
			break;
		}
		int nxt = find(res.back()-1, N);
		
		//int nxt = 1;
		use[nxt] = 1;
		res.push_back(nxt+1);
	}
 
	Answer(res);
}
