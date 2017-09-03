//category : graph



#include <stdio.h>
#include <vector>
using namespace std;
bool map[100001];
int ans=-1;
int depth;
int N, K;
bool move(int x){
	if (x < 0 || x>100000) return false;
	if (x == K){
		ans = depth;
		return false;
	}
	if (map[x]) return false;
	map[x] = true;
	return true;
}
int main(){
	int i=0;
	scanf("%d%d",&N,&K);
	if (N == K) return printf("0");
	vector<int> v;
	v.push_back(N);
	int end = 0;
	map[N] = true;
	while (end != v.size()){
		end = v.size();
		depth++;
		for (; i < end; i++){
			if (move(v[i] + 1)) v.push_back(v[i] + 1);
			if (move(v[i] - 1)) v.push_back(v[i] - 1);
			if (move(v[i]<<1)) v.push_back(v[i]<< 1);
		}
		if (ans > 0) break;

	}
	printf("%d",ans);
	return 0;
}