//category : line sweeping

#include <stdio.h>
#include <queue>

#include <algorithm>
using namespace std;

struct Student{
	int ix;
	int b;
	int c;
	bool operator<(const Student st){
		return b < st.b;
	}
};
struct Bug{
	int ix;
	int a;
	int assign;
	bool operator<(const Bug b){
		return a < b.a;
	}
};
Student st[100000];
Bug bug[100000];
int main(){
	int i, j,k;
	int n, m, s;
	queue<int> ans;
	scanf("%d%d%d",&n,&m,&s);
	for (i = 0; i < m; i++){
		scanf("%d", &bug[i].a);
		bug[i].ix = i;
	}
	for (i = 0; i < n; i++){
		scanf("%d", &st[i].b);
		st[i].ix = i+1;
	}
	for (i = 0; i < n; i++) scanf("%d", &st[i].c);
	sort(st, st + n);
	sort(bug, bug + m);

	int start = 1;
	int end = m;
	int mid;
	long long total;
	while (start<=end){
		mid = (start + end) / 2;
		priority_queue<pair<int, int> > pq;
		queue<int> q;
		i = m - 1;
		j = n - 1;
		total = 0;
		while (i >= 0){
			while (j>=0&&st[j].b>=bug[i].a){
				pq.push(make_pair(-st[j].c, st[j].ix));
				j--;
			}
			i -= mid;
			if (pq.empty()){
				total = s + 1;
				break;
			}
			total += -pq.top().first;
			q.push(pq.top().second);
			pq.pop();
		}
		if (q.empty() || total > s) start = mid + 1;
		else{
			ans = q;			
			end = mid - 1;
			k = mid;
		}

	}
	if (ans.empty()){
		printf("NO");
		return 0;
	}
	printf("YES\n");	
	mid = k;
	i = m - 1;
	while (!ans.empty()){
		for (j = 0; j < mid&&i >= 0; j++) bug[i--].assign = ans.front();
		ans.pop();
	}
	sort(bug, bug + m, [](Bug &b1, Bug &b2){return b1.ix < b2.ix; }
	);
	for (i = 0; i < m; i++){
		printf("%d ",bug[i].assign);
	}
	return 0;
}