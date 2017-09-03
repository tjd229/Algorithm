//category : graph, tp sort

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> edge[100001];
vector<int> ans;
int ind[100001];
int num[100001];
bool src[100001];
int high;
int cnt;
vector<int> tp_sort(int ix){
	vector<int> v;
	queue<int> q;
	q.push(ix);
	int curr;
	int i;
	while (!q.empty()){
		curr=q.front();
		q.pop();
		num[curr] = cnt++;
		v.push_back(curr);
		for (i = 0; i < edge[curr].size(); i++){
			ind[edge[curr][i]]--;
			if (ind[edge[curr][i]] == 0){
				q.push(edge[curr][i]);
			}
		}
	}
	return v;
}
void setup(vector<int> &v){
	int i,j;
	for (i = 0; i < v.size(); i++){
		if (high == num[v[i]] && !src[v[i]])
			ans.push_back(v[i]);
		for (j = 0; j < edge[v[i]].size(); j++){
			if (high < num[edge[v[i]][j]])
				high = num[edge[v[i]][j]];
		}
	}
}
int main(){
	int i;
	int N;
	int A, B;
	scanf("%d",&N);
	for (i = 0; i < N - 1; i++){
		scanf("%d%d",&A,&B);
		edge[A].push_back(B);
		ind[B]++;
	}
	for (i = 1; i <= N; i++){
		if (ind[i] == 0){
			edge[0].push_back(i);
			ind[i]++;
			src[i] = true;
		}
		if (edge[i].size() == 0){
			edge[i].push_back(N + 1);
			ind[N + 1]++;
		}
	}
	src[0] = src[N + 1] = true;
	vector<int> v = tp_sort(0);
	setup(v);
	sort(ans.begin(), ans.end());
	for (i = 0; i < ans.size(); i++)
		printf("%d\n",ans[i]);
	return 0;
}