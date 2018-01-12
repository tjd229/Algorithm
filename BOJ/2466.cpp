//category : dp, bs
//reference : http://www.usaco.org/current/data/sol_bookshelf_gold.html

#include <stdio.h>
#include <set>
#include <queue>
#define pii pair<int,int>
using namespace std;
int t[100001];
int h[100001];
int s[100001];
int d[100001];
pii dq[300001];
int match[100001];
int front, back;
int main(){
	int i;
	int N;
	int l, r,m;
	int from;
	l = r = 0;
	for (scanf("%d", &N), i = 1; i <= N; i++){
		scanf("%d%d", t + i, h + i);
		r += t[i];
		s[i] = r;
		if (l < t[i]) l = t[i];
	}
	r = 1e9;
	while (l <= r){
		m = (l + r) >> 1;
		from = 1;
		front = back = 0;
		dq[back++] = {0,1e9};
		multiset<int> st;
		
		for (i = 1; i <= N; i++){
			while (back-front>1&&dq[back-1].second<=h[i]){
				st.erase(st.find(match[dq[back-2].first]));
				back--;
			}
			match[dq[back - 1].first] = d[dq[back - 1].first] + h[i];
			st.insert(match[dq[back-1].first]);
			dq[back++] = {i,h[i]};
			while (s[i] - s[from - 1] > m){
				st.erase(st.find(match[from-1]));
				if (dq[front].first == from - 1) front++;
				if (dq[front].first != from){
					dq[--front] = { from, 1e9 };
					match[from] = d[from] + dq[front + 1].second;
					st.insert(match[from]);
				}
				else dq[front].second = 1e9;
				from++;
			}
			d[i] = *st.begin();


		}		
		if (d[N] > m) l = m + 1;
		else r = m - 1;
		
	}
	printf("%d",r+1);

	return 0;
}
