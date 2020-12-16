//implementation

#include <iostream>
#include <string>
#include <vector>
#define pii pair<int,int>
using namespace std;
int sm, sc, si;
int input[4097];
int nxt[4096];
string inst;
void sim() {
	int pt = 0;
	int t = 0;
	int cnt = 0;
	vector<pii > s;
	int mem[100000] = { 0 };
	for (t = 0; t < sc; t++) {
		if (inst[t] == '[') s.push_back({t,0});
		else if (inst[t] == ']') {
			nxt[s.back().first] = t;
			s.pop_back();
		}
	}
	for (t = 0; t < sc; t++) {
		if (inst[t] == '-') {
			mem[pt]--;
			if (mem[pt] < 0) mem[pt] = 255;
		}
		else if (inst[t] == '+') {
			mem[pt]++;
			if (mem[pt] > 255) mem[pt] = 0;
		}
		else if (inst[t] == '<') {
			if (pt == 0) pt = sm - 1;
			else --pt;
			//if (--pt < 0) pt = sm - 1;
		}
		else if (inst[t] == '>') {
			if (pt == sm - 1) pt = 0;
			else ++pt;
			//if (++pt >= sm) pt=0;
		}
		else if (inst[t] == ',') {
			mem[pt] = si ? input[si--] : input[0];
		}
		else if (inst[t] == '[') {
			if (mem[pt])
				s.push_back({t,cnt});
			else {
				t = nxt[t];
				cnt++;
			}
		}
		else if (inst[t] == ']') {
			if (mem[pt]) {
				cnt++;
				if (cnt - s.back().second >= 50000000) {
					cout << "Loops " << s.back().first << " " << t << "\n";
					return;
				}
				t = s.back().first;
				//
			}
			else {
				s.pop_back();
			}
		}

		cnt++;
		
	}
	cout << "Terminates\n";
}
int main() {
	int i;
	int t;
	cin >> t;
	while (t--) {
		cin >> sm >> sc >> si;
		string s;
		cin >> inst >> s;
		for (i = 0; i < s.size(); i++) input[si - i] = s[i];
		input[0] = 255;

		sim();
	}

	return 0;
}
