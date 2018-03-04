//category : graph, floyd, string

#include <iostream>
#include <vector>
#include <string>
using namespace std;
//int d[256][4];// init,!,&,l
//int from[256][3]; //op,lt,rt
bool in_q[256];
string d[256][4];
const int x = 1 + 2 + 4 + 8;
const int y = 1 + 2 + 16 + 32;
const int z = 1 + 4 + 16 + 64;
int min(int a, int b){
	if (a == 0) return b;
	if (b == 0) return a;
	return a < b ? a : b;
}
int main(){
	int i, j, k,l;
	vector<int> q;
	d[x][0] = "x";
	d[y][0] = "y";
	d[z][0] = "z";
	q.push_back(x);
	q.push_back(y);
	q.push_back(z);
	in_q[x] = in_q[y] = in_q[z] = true;
	int last = 0;
	int end = q.size();
	int res;
	int len;
	while(last!=end){
		for (i = 0; i < end; i++){
			int left = q[i];
			for (j = 0; j < 4; j++){
				if (d[left][j].size()==0) continue;
				for (k = 0; k < end; k++){
					int right = q[k];
					
					for (l = 0; l < 4; l++){
						if (d[right][l].size() == 0) continue;
						//if (d[right][l] < d[left][j]) continue;
						res = left | right;
						len = d[left][j].size() + d[right][l].size()+1;
						if (d[res][3].size()==0||d[res][3].size() >= len){
							string s = d[left][j];
							s += "|";
							s += d[right][l];
							
							if (d[res][3].size() == 0 || d[res][3].size() > len || d[res][3] > s){
								
								 d[res][3] = s;
								 if (!in_q[res]) q.push_back(res);
								 in_q[res] = true;

							}
						}
						res = left & right;
						len += ((l == 3) + (j == 3)) *2;
						if (d[res][2].size() == 0 || d[res][2].size() >= len){
							string s = "";
							if (j == 3) s += "(";
							s+= d[left][j];
							if (j == 3) s += ")";
							s += "&";
							if (l == 3) s += "(";
							s += d[right][l];
							if (l == 3) s += ")";
							if (d[res][2].size() == 0 || d[res][2].size() > len || d[res][2] > s){
								d[res][2] = s;
								if (!in_q[res]) q.push_back(res);
								in_q[res] = true;
							}
						}
					}
				}
				//!
				if (j ==1) continue;
				res = 255^left;
				len = 1+d[left][j].size() + (j>1)*2;
				if (d[res][1].size() == 0 || d[res][1].size() >= len){
					string s = "!";
					if (j !=0) s += "(";
					s += d[left][j];
					if (j !=0) s += ")";
					if (d[res][1].size() == 0 || d[res][1].size() > len || d[res][1] > s){
						d[res][1] = s;
						if (!in_q[res]) q.push_back(res);
						in_q[res] = true;
					}
				}

			}
			
		}
		last = end;
		end = q.size();
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	/*cout << d[z | y][1] << endl;
	cout << d[z | y][2] << endl;
	cout << d[z | y][3] << endl;
	return 0;*/
	cin >> n;
	while (n--){
		string s;
		int num = 0;
		cin >> s;
		for (i = 0; i < 8; i++){
			num <<= 1;
			num += s[i] == '1';
		}
		string *pt=NULL;
		for (i = 0; i < 4; i++){
			if (d[num][i].size() == 0) continue;
			if (pt == NULL) pt = &d[num][i];
			else if (pt->size() >= d[num][i].size()){
				if (pt->size() > d[num][i].size() || *pt>d[num][i])
					pt = &d[num][i];
			}
			//cout << d[num][i] << endl;
		}
		if (pt != NULL) cout << *pt << "\n";
	}
	return 0;
}
