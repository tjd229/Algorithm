//category : d&c

#include <iostream>
#include <string>
using namespace std;

string image[64];
string compress(int lx,int ly,int rx,int ry){
	string result = "";
	if (rx - lx == 1 && ry - ly == 1){
		result += image[ly][lx];
		return result;
	}
	int cent_x = (lx + rx) / 2;
	int cent_y = (ly + ry) / 2;
	string ld, lu, rd, ru;
	lu = compress(lx, ly, cent_x, cent_y);
	ld = compress(lx, cent_y, cent_x, ry);
	ru = compress(cent_x, ly, rx, cent_y);
	rd = compress(cent_x, cent_y, rx, ry);

	if (ld == "1"&&lu == "1"&&rd == "1"&&ru == "1")
		return "1";
	if (ld == "0"&&lu == "0"&&rd == "0"&&ru == "0")
		return "0";

	return "(" + lu + ru + ld + rd + ")";

}
int main(){
	int i;
	int N;
	cin >> N;
	for (i = 0; i < N; i++){
		cin >> image[i];
	}

	cout << compress(0, 0, N, N);
	return 0;
}



