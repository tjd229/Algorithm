//graph
#include "popa.h"
#include <stack>
using namespace std;
int solve(int N, int *Left, int *Right) {
	*Left = -1, *Right = -1;
	stack<int> stk; stk.push(0);
	int root = 0;
	for (int i = 1; i < N; ++i) {
		Left[i] = Right[i] = -1;
		while (stk.size() && query(i,i,stk.top(),i)) {
			Right[stk.top()] = Left[i];
			Left[i] = stk.top();
			stk.pop();
		}
		if (stk.size()) Right[stk.top()] = i;
		else root = i;
		stk.push(i);
	}
	return root;
}