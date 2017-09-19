//category : implementation

#include <stdio.h>
#include <stack>
using namespace std;
int h[100000];
long long max(long long a, long long b){return  a < b ? b : a; }
int main(){
	int i;
	int n;
	int wi, hi;
	long long ans;
	while (scanf("%d", &n)){
		if (n == 0) break;
		stack<int> st;
		ans = 0;
		for (i = 0; i < n; i++){
			scanf("%d", h + i);
			
			while (!st.empty() && h[st.top()]>h[i]){
				hi = h[st.top()];
				st.pop();
				wi = i;
				if (!st.empty()) wi -= st.top() + 1;
				ans = max(ans, (long long)wi*hi);
			}
			st.push(i);
		}
		while (!st.empty()){
			hi = h[st.top()];
			st.pop();
			wi = i;
			if (!st.empty()) wi -= st.top() + 1;
			ans = max(ans, (long long)wi*hi);
		}
		printf("%lld\n",ans);
	}
	return 0;
}