//math, d&c
#include "minerals.h"
#include <vector>
using namespace std;
int last = 0;
void dvc(vector<int> X,vector<int> Y,int dir) {
	if (X.size() == 1) {
		Answer(X[0],Y[0]);
		return;
	}
	int m = 1+(X.size()*0.38);
	vector<int> X1,X2, Y1,Y2;
	if (dir) {
		while (X2.size() <m) {
			X2.push_back(X.back());
			last = Query(X.back());
			X.pop_back();
		}
		X1 = X;
	}
	else {
		while (X1.size() < m) {
			X1.push_back(X.back());
			last = Query(X.back());
			X.pop_back();
		}
		while (X.size()) {
			X2.push_back(X.back());
			X.pop_back();
		}
	}
	int i=0;
	for (i = 0; i < Y.size(); ++i) {
		if (X1.size() == Y1.size()) {
			while (X2.size() != Y2.size())
				Y2.push_back(Y[i++]);
			break;
		}
		if (X2.size() == Y2.size()) {
			while (X1.size() != Y1.size())
				Y1.push_back(Y[i++]);
			break;
		}
		int in = Query(Y[i]);
		if (last == in) Y1.push_back(Y[i]);
		else Y2.push_back(Y[i]);
		last = in;
	}


	dvc(X1, Y1, 1); dvc(X2, Y2, 0);
}
void Solve(int N) {
	int NN = N + N;
	vector<int> X,Y;
	
	for (int i = 1; i <= NN; ++i) {
		int in = Query(i);
		if (in == last) 
			Y.push_back(i);
		
		else X.push_back(i);
		last = in;
	}
	dvc(X, Y, 1);
	
	
}
