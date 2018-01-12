//category : dp

#include <stdio.h>
#include <set>
#define ll long long
#define pii pair<int,int>
using namespace std;
int H[100001], W[100001];
pii dq[300001];
int front, back;
ll match[100001],d[100001];
int main(){
	int i;
	int N, L;
	int from = 1;
	int wsum=0;
	multiset<ll> st;
	dq[back++] = { 0, 1e9 };
	for (scanf("%d%d", &N, &L), i = 1; i <= N; i++){
		scanf("%d%d",H+i,W+i);
		while (back - front > 1 && dq[back - 1].second <= H[i]){
			st.erase(st.find(match[dq[back - 2].first]));
			back--;
		}
		match[dq[back - 1].first] = H[i] + d[dq[back - 1].first];
		st.insert(match[dq[back-1].first]);
		dq[back++] = { i, H[i] };
		wsum += W[i];
		while (wsum>L){
			wsum -= W[from];
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
	printf("%lld",d[N]);

	return 0;
}
