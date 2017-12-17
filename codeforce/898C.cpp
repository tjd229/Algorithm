//category : string
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<string,vector<string> > m;
//isSuffix
bool check(string &s1,string &s2){
	int i = s1.size();
	int j = s2.size();
	i--; j--;
	while (i >= 0 && j >= 0 && s1[i] == s2[j]){
		i--;
		j--;
	}
	return i < 0 || j < 0;
}
int main(){
	int i,j,k;
	string name;
	string num;
	int n;
	int cnt;
	cin >> n;
	for (i = 0; i < n; i++){
		cin >> name >> cnt;
		if (m.find(name) == m.end()){
			vector<string> v;
			m.insert({name,v});
		}
		for (j = 0; j < cnt; j++){
			cin >> num;
			bool suf = false;
			auto pt = m[name];
			for (k = 0; k < pt.size(); k++){
				if (check(pt[k], num)){
					if (pt[k].size() < num.size())
						m[name][k] = num;
					suf = true;
					break;
				}
			}
			if (!suf) m[name].push_back(num);
		}
	}
	cout << m.size();
	for (auto it = m.begin(); it != m.end(); it++){
		cout << "\n" << it->first << " " << it->second.size();
		for (i = 0; i < it->second.size(); i++)
			cout <<" "<< it->second[i];
	}

	return 0;
}
