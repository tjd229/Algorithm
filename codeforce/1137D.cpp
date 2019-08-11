//graph, math

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int move(vector<int> v) {
	cout << "next";
	for (auto x : v) cout<<" " << x;
	cout << endl;
	int k; cin >> k;
	for (int i = 0; i < k; ++i) {
		string s; cin >> s;
	}
	return k;
}
int main() {
	int g = -1;
	vector<int> all = {0,1,2,3,4,5,6,7,8,9};
	while (g != 2) {
		move({ 0 });
		g = move({ 0,1 });
	}
	while (g != 1) {
		g = move(all);
	}
	cout << "done" << endl;
	return 0;
}