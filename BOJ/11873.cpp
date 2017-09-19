//category : implementation

#include <stdio.h>
#include <stack>
using namespace std;
int max(int a, int b){ return a < b ? b : a; }
int main(){
	int i, j;
	int N, M;
	int val;
	int rect;
	int w,h;
	while (scanf("%d%d", &N, &M)){
		if (N == 0 && M == 0) break;
		int mat[1000] = { 0 };
		rect = 0;
		for (i = 0; i < N; i++){
			stack<int> st;
			for (j = 0; j < M; j++){
				scanf("%d",&val);
				if (val == 0){
					mat[j] = 0;					
				}
				else mat[j]++;
				while (!st.empty() && mat[st.top()]>mat[j]){
					h = mat[st.top()];
					w = j;
					st.pop();
					if (!st.empty())
						w -=st.top()+1;
					rect = max(rect, h*w);				
					
				}
				st.push(j);				
			}
			while (!st.empty()){
				
				h = mat[st.top()];
				w = j;
				st.pop();
				if (!st.empty())
					w -= st.top() + 1;
				rect = max(rect, h*w);
			}
		}
		printf("%d\n",rect);
	}
	return 0;
}