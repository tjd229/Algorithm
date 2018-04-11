//category : math

#include <cstdio>
#include <vector>
#include "library.h"
using namespace std;
 
bool use[2000];
void Solve(int N)
{
	vector<int> M(N);
	vector<int> res;
	vector<int> bitset[10];
	int a[10] = { 0 };
	int cnt[10] = { 0 };
	int i, j;
	int A=N;
	int lgN = 0;
	while (A != 0){
		lgN++;
		A >>= 1;
	}
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
	for (i = 0; i < lgN; i++) bitset[i].resize(N, 0);
	for (i = 0; i < N; i++){
		if (use[i]) continue;
		j = 0;
		A = i+1;
		while (A != 0){
			if (A & 1) bitset[j][i] = 1,cnt[j]++;
			A >>= 1;
			j++;
		}
	}
	for (i = 0; i < lgN; i++){
		if (cnt[i])
			a[i] = Query(bitset[i]);
	}
	for (i = 1; i < N; i++){
		int bit = 0;
		int last = res.back() - 1;
		for (j = 0; j < lgN; j++){
			if (cnt[j] == 0) continue;
			bitset[j][last] = 1;
			A = Query(bitset[j]);
			if (A == a[j]) bit |= (1 << j);
			bitset[j][last] = 0;
		}
		
		res.push_back(bit);
		j = 0;
		A = bit;
		while (A != 0){
			if (A & 1){
				bitset[j][bit-1] = 0;
				if (--cnt[j])
					 a[j] = Query(bitset[j]);
			}
			A >>= 1;
			j++;
		}
	}
 
	Answer(res);
}
