//category : implementation

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int sm, sc, si;
int input[4097];
int nxt[4096];
string inst;
void sim(){
	int pt = 0;
	int t = 0;
	int cnt = 0;
	vector<int> s;
	int mem[100000] = { 0 };
	bool escape[4096] = { 0 };
	for (t = 0; t < sc; t++){
		if (inst[t] == '[') s.push_back(t);
		else if (inst[t] == ']'){
			nxt[s.back()] = t;
			s.pop_back();
		}
	}
	for (t = 0; t < sc; t++){
		if (inst[t] == '-'){
			mem[pt]--;
			if (mem[pt] < 0) mem[pt] = 255;
		}
		else if (inst[t] == '+'){
			mem[pt]++;
			if (mem[pt] > 255) mem[pt] = 0;
		}
		else if (inst[t] == '<'){
			if (pt == 0) pt = sm - 1;
			else --pt;
			//if (--pt < 0) pt = sm - 1;
		}
		else if (inst[t] == '>'){
			if (pt == sm - 1) pt = 0;
			else ++pt;
			//if (++pt >= sm) pt=0;
		}
		else if (inst[t] == ','){
			mem[pt] = si ? input[si--] : input[0];
		}
		else if (inst[t] == '['){
			if (mem[pt])
				s.push_back(t);
			else{
				//int stk = 0;
				//while (stk != 0 || inst[t] != ']'){
				//	if (inst[t] == '[') stk++;
				//	if (inst[t] == ']') stk--;
				//	
				//	t++;
				//	if (stk == 0) break;
				//}
				//while (inst[t] != ']') t++;
				//cnt++;
				t = nxt[t];
				cnt++;
			}
		}
		else if (inst[t] == ']'){
			if (mem[pt]){
				t = s.back();
				cnt++;
				//
			}
			else{
				escape[s.back()] = true;
				s.pop_back();
			}
		}

		cnt++;
		if (cnt > 50000010){
			cout << "Loops ";
			while (escape[s.back()]) s.pop_back();
			t = s.back();
			cnt = 0;
			cout << t;
			while (cnt != 0 || inst[t] != ']'){
				if (inst[t] == '[') cnt++;
				if (inst[t] == ']') cnt--;
				if (cnt == 0){
					cout << " " << t << "\n";
					return;
				}
				t++;
			}
		}
	}
	cout << "Terminates\n";
}
int main(){
	int i;
	int t;
	cin >> t;
	while (t--){
		cin >> sm >> sc >> si;
		string s;
		cin >> inst >> s;
		for (i = 0; i < s.size(); i++) input[si - i] = s[i];
		input[0] = 255;
		
		sim();
	}

	return 0;
}
