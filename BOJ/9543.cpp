//category : implementation

#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
int crate[10001];
int pos[10001];
void swap(int l,int r){
	int bnd = (r - l + 1) >> 1;
	int tmp;
	for (int i = 0; i < bnd; i++){
		tmp = crate[l + i];
		crate[l + i] = crate[l+bnd + i];
		crate[l + bnd + i] = tmp;
		pos[crate[l + i]] = l + i;
		pos[crate[l + bnd + i]] = l + bnd + i;
	}
}
int main(){
	int i;
	int n;
	int T;
	int curr,to;
	for (scanf("%d", &T); T--;){
		vector<pii > hist;
		for (scanf("%d", &n), i = 1; i <= n; i++){
			scanf("%d",crate+i);
			pos[crate[i]] = i;
		}
		for (i = 1; i <= n; i++){
			while (i != pos[i]){
				curr = pos[i];
				if ((pos[i] - i + 1) & 1){
					hist.push_back({ i+1, pos[i] });
					swap(i+1, pos[i]);
				}
				else{
					hist.push_back({ i, pos[i] });
					swap(i, pos[i]);
				}
			}
		}
		printf("%d\n", hist.size()); 
		for (i = 0; i < hist.size(); i++) printf("%d %d\n",hist[i].first,hist[i].second);
	}

	return 0;
}
