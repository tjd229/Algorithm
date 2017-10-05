//category : string, KMP


#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int pi[(int)1e6];
int main(){
	int i, j = 0;
	int k;
	string S, T;
	stack<int > st;
	vector<int> pos;
	cin >> S >> T;
	for (i = 1; i < T.size(); i++){
		while (j > 0 && T[i] != T[j]) j = pi[j - 1];
		if (T[i] == T[j]) pi[i] = ++j;
	}
	//i for S, j for T
	for (i = j = 0; i < S.size();){
		if (S[i] == T[j]){
			st.push(j + 1);
			i++, j++;
		}
		else{
			if (j != 0){
				j = pi[j - 1];
			}
			else{
				i++;
				st.push(-1);
			}
		}
		if (j == T.size()){
			pos.push_back(i - 1);
			while (j > 0){
				st.pop();
				j--;
			}
			if (!st.empty() && st.top() >= 0){
				j = st.top();
			}
		}
	}
	j = pos.size() - 1;
	k = 0;
	for (i = S.size() - 1; i >= 0; i--){
		if (j >= 0 && pos[j] == i) k += T.size(), j--;
		if (k > 0){
			S[i] = ' ';
			k--;
		}

	}
	for (i = 0; i < S.size(); i++){
		if (S[i] != ' ') cout << S[i];
	}
	return 0;
}