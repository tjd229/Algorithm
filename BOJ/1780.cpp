//category : d&c



#include <stdio.h>
#include <vector>
using namespace std;
int paper[27*27*3][27*27*3];
int ans[3];
int N;
int cut(int x,int y,int n){
	n /= 3;
	if (n == 0)
		return paper[y][x];
	int last = -2;
	int res;
	bool flag=true;
	int i,j;
	vector<int> history;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			res = cut(x+j*n,y+i*n,n);
			if (last != -2 && last != res)
				flag = false;
			last = res;
			if (res!=-2)
				history.push_back(res);
		}
	}
	if (flag){
		return last;
	}
	for (i = 0; i < history.size(); i++)
		ans[history[i]+1]++;
	return -2;
}
int main(){
	int i, j;
	scanf("%d",&N);
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++)
			scanf("%d",&paper[i][j]);
	}
	int res = cut(0,0,N);
	if (res != -2)
		ans[res+1]++;
	printf("%d\n%d\n%d",ans[0],ans[1],ans[2]);
	return 0;
}