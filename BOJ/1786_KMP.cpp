//category : string, KMP

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int pi[1000000];

int main(){

	string T, P;
	vector<int> v;
	int i, j=0;
	getline(cin, T);
	getline(cin, P);

	for (i = 1; i < P.size(); i++){	
        while(j>0&&P[j]!=P[i]) j=pi[j-1];
        if(P[j]==P[i]) pi[i]=++j;
	}
	for (i = j = 0; i < T.size();){
		if (T[i] == P[j]) i++, j++;
		else{
			if (j != 0)
				j = pi[j - 1];
			else i++;
		}
		if (j == P.size()) v.push_back(i - j + 1), j = pi[j - 1];
	}
	printf("%d\n", v.size());
	for (i = 0; i < v.size(); i++) printf("%d ", v[i]);
	return 0;
}
