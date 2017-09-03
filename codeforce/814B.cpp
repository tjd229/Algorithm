//category : implementation

#include <stdio.h>
#include <vector>
using namespace std;
int a[1001];
int b[1001];
int p[1001];
bool cnt[1001];
int first_num(){
	int i = 1;
	while (cnt[i]) i++;
	cnt[i] = true;
	return i;
}
int main(){
	int i, j,k;
	int n;
	vector<int> err;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", a + i);
	for (i = 1; i <= n; i++){
		scanf("%d", b + i);
		if (a[i] == b[i]) cnt[a[i]] = true, p[i] = a[i];
		else err.push_back(i);
	}
	if (err.size() == 1) p[err[0]] = first_num();
	else{
		k = 0;
		for (i = 0; i < err.size(); i++){
			
			j = err[i];
			if (cnt[a[j]] | cnt[b[j]]) k = i;
			
		}
		for (i = 0; i < 2; i++){
			j = err[k];
			if (cnt[a[j]]){
				p[j] = b[j];
				cnt[b[j]] = true;
			}
			else{
				p[j] = a[j];
				cnt[a[j]] = true;
			}
			k ^= 1;
		}
	}

	for (i = 1; i <= n; i++)
		printf("%d ", p[i]);
	return 0;
}