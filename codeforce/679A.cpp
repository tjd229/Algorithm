//math

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int prime[25] = { 2, 3, 5, 7, 11,
13, 17, 19, 23, 29, 
31, 37, 41, 43, 47, 
53, 59, 61, 67, 71, 
73, 79, 83, 89, 97
};
int main() {
	int i;
	vector<int> candi;
	for (i = 0; i < 15; ++i) {
		string ans;
		cout << prime[i]<<endl;
		cin >> ans;
		if (ans[0] == 'y') {
			candi.push_back(prime[i]);
		}
		
	}
	if (candi.empty()) cout << "prime";
	else if (candi.size() > 1) cout << "composite";
	else {
		if (candi[0] > 10) cout << "prime";
		else {
			int sq = candi[0] * candi[0];
			string ans;
			cout << sq << endl;
			cin >> ans;
			cout << (ans[0] == 'y' ? "composite" : "prime");
		}
	}
	
	return 0;
}
