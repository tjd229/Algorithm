//category : djs
#include <stdio.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
int a[200000];
int p[200000];
int l[200000];
int r[200000];
int sz[200000];
bool removed[200000];
int n;
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void join(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	if (l[a] > l[b]) l[a] = l[b];
	if (r[a] < r[b]) r[a] = r[b];
	sz[a] += sz[b];
}
int main(){
	int i;
	int cnt = 0;
	int curr;
	int left, right;
	priority_queue<pii> pq;
	scanf("%d",&n);
	for (i = 0; i < n; i++){
		p[i] = i;
		scanf("%d",a+i);
		l[i] = i - 1;
		r[i] = i + 1;
		sz[i] = 1;
	}
	for (i = 1; i < n; i++){
		if (a[i] == a[i - 1]) join(i-1,i);
	}
	for (i = 0; i < n; i++){
		if (i==p[i])
			pq.push({sz[i],-i});
	}
	while (!pq.empty()){
		pii t = pq.top();
		pq.pop();
		curr = find(-t.second);
		if (removed[curr]) continue;
		removed[curr] = true;
		cnt++;
		left = l[curr];
		right = r[curr];
		if (left < 0 || right >= n) continue;
		left = find(left);
		right = find(right);
		if (a[left] == a[right]){
			if (removed[find(left)] || removed[find(right)]) continue;
			join(left,right);
			pq.push({sz[find(left)],-find(left)});
		}
		else{
			r[left] = right;
			l[right] = left;
		}
	}
	printf("%d",cnt);
	return 0;
}
