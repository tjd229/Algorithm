//category : implementation



#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
int tenpow[9] = {
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000
};

int find0(int n){
	int ix = 0;
	while (n != 0){
		if (n % 10 == 0) return ix;
		ix++;
		n /= 10;
	}
	return ix;
}
int swap(int n,int a,int b){
	if (b < 0 || b >= 9 || (b % 3 == 0 && a % 3 == 2) || (b % 3 == 2 && a % 3 == 0)) return n;
	int na = (n / tenpow[a]) % 10;
	int nb = (n / tenpow[b]) % 10;
	n += (nb - na)*tenpow[a];
	n += (na - nb)*tenpow[b];
	return n;

}
int main(){
	int n;
	int i;
	
	//string s="";
	//string next;
	int puzzle=0;
	int next;
	int ten = tenpow[8];
	vector<int> curr_list;
	vector<int> next_list;
	for (i = 0; i < 9; i++){
		cin >> n;
		puzzle += n*ten;
		ten /= 10;
	}
	if (puzzle == 123456780){
		cout << 0;
		return 0;
	}
	n = 0;
	int ix;
	unordered_set<int> set;
	
	set.insert(puzzle);
	curr_list.push_back(puzzle);


	while (curr_list.size()!=0){	
		n++;
		//cout << n << endl;
		for (i = 0; i < curr_list.size();i++){
			puzzle = curr_list[i];
			//cout << puzzle<<endl;
			ix = find0(puzzle);
			next = swap(puzzle, ix, ix + 1);
			if (next != puzzle){
				if (next == 123456780){
					cout << n;
					return 0;
				}
				if (set.end() == set.find(next)){
					set.insert(next);
					next_list.push_back(next);
				}
			}
			next = swap(puzzle, ix, ix - 1);
			if (next != puzzle){
				if (next == 123456780){
					cout << n;
					return 0;
				}
				if (set.end() == set.find(next)){
					set.insert(next);
					next_list.push_back(next);
				}
			}
			next = swap(puzzle, ix, ix + 3);
			if (next != puzzle){
				if (next == 123456780){
					cout << n;
					return 0;
				}
				if (set.end() == set.find(next)){
					set.insert(next);
					next_list.push_back(next);
				}
			}
			next = swap(puzzle, ix, ix - 3);
			if (next != puzzle){
				if (next == 123456780){
					cout << n;
					return 0;
				}
				if (set.end() == set.find(next)){
					set.insert(next);
					next_list.push_back(next);
				}
			}
		}
		curr_list = next_list;
		next_list.clear();
	}
	cout << -1;
	return 0;
}
