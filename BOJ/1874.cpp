//implementation

#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
int a[100000];
int main(){
	int i;
	int n;
	int cnt = 1;
	vector<char> v;
	stack<int> st;
	scanf("%d",&n);
	for (i = 0; i < n; i++){
		scanf("%d",a+i);
	}
	for (i = 0; i < n; i++){
		while (st.empty()||st.top()<a[i]){
			st.push(cnt++);
			v.push_back('+');
		}
		if (st.top() == a[i]){
			st.pop();
			v.push_back('-');
		}
		else{
			v.clear();
			break;
		}
	}
	if (v.empty())printf("NO");
	else{	
		for (i = 0; i < v.size(); i++)
		printf("%c\n",v[i]);
	    }
	return 0;
}
