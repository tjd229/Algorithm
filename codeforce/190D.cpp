//category : line sweeping

#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int, int> dic;
int code[400000];
int cnt[400000];
void compress(int n){
	vector<int> v;
	int i;
	int last = -1;
	int t = 0;
	for (i = 0; i < n; i++) v.push_back(code[i]);
	sort(v.begin(), v.end());
	for (i = 0; i < n; i++){
		if (last != v[i]){
			dic.insert(make_pair(v[i], t++));
			last = v[i];
		}
	}
}
int main(){
	int n, k;
	int i,j;
	long long ans = 0;
	int least = 0;
	
	scanf("%d%d",&n,&k);
	for (i = 0; i < n; i++) scanf("%d", code+i);
	compress(n);
	for (i = j = 0; i < n; i++){
		if (j >= n&&least==0) break;
		if (i > 0){
			cnt[dic[code[i-1]]]--;
			if (cnt[dic[code[i - 1]]] == k - 1) least--;
		}
		while (j<n&&least==0){
			cnt[dic[code[j]]]++;
			if (cnt[dic[code[j]]] == k) least++;
			j++;
		}
		if (least>0){
			ans += n - (j - 1);
		}
	}
	printf("%I64d",ans);
	return 0;
}