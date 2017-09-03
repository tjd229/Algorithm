//category : KMP, string


#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string s;
int pi[5000][5000];
int main(){
	cin >> s;
	int i, j, k;
	int max = 0;
	for (i = s.size() - 1; i >= 0; i--){
		k = 0;
		for (j = i+1; j < s.size(); j++){
			while (k>0 && s[j] != s[i+k]) k = pi[i][k - 1];
			if (s[j] == s[i+k]){
				pi[i][j-i] = ++k;
				if (max < pi[i][j-i]) max = pi[i][j-i];
			}
		}
	}
	printf("%d",max);

	return 0;
}