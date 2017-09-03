//category : implementation

#include <stdio.h>
#include <vector>
using namespace std;
int cnt[100];
int clan[100];
bool visit[100];
int sign(int n){
	if (n < 0) n = -n;
	return n;
}
int main(){
	int n;
	int nn;
	int a;
	int dh[2] = { 0 };
	int h[2] = { 0 };
	int i;
	int toggle = 1;
	vector<int> hist;
	scanf("%d", &n);
	nn = n + n;
	dh[0] = dh[1] = n;
	vector<int> ans(nn);
	for (i = 0; i < nn; i++){
		scanf("%d", &a);
		hist.push_back(a);
		cnt[a]++;
		if (cnt[a]>2){
			dh[toggle-1]--;
			toggle ^= 3;
		}
	}
	for (i = 0; i < nn; i++){
		if (visit[hist[i]]) continue;
		visit[hist[i]] = true;
		if (!(cnt[hist[i]] & 1)) clan[hist[i]] = 1;
		else if (cnt[hist[i]]>1){
			clan[hist[i]] = toggle;
			toggle ^= 3;
		}		

	}

	for (i = 0; i < nn; i++){
		if (cnt[hist[i]]>1){
			ans[i] = clan[hist[i]];
			h[clan[hist[i]]-1]++;			
			clan[hist[i]] ^= 3;
		}
	}

	for (i = 0; i < nn; i++){
		if (cnt[hist[i]]==1){
			if (h[0] != n) ans[i] = 1, h[0]++;
			else ans[i] = 2, h[1]++;
		}
	}
	printf("%d\n",dh[0]*dh[1]);
	for (i = 0; i < nn; i++) printf("%d ",ans[i]);
	return 0;
}