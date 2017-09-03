//category : graph, dp, knapsack

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool pre[1001], post[1001];
int student[1001];
int party[1001];
int ix;
vector<pair<int, int> > list;
vector<pair<int, int> > ans;
vector<int> source;
void dfs(int n,int stack){
	if (pre[n] || post[n]){
		if (stack > 0){
			if (party[n] != -1) list[party[n]].second += stack;
			else dfs(student[n], stack);
		}
		return;
	}
	pre[n] = true;
	stack++;
	if (pre[student[n]]&&!post[student[n]]){
		int curr = n;
		int cnt = 0;
		do{
			party[curr] = ix;
			cnt++;
			curr = student[curr];
		} while (curr != n);
		ix++;
		list.push_back(make_pair(cnt,stack-cnt));

	}
	else{
		dfs(student[n], stack);
	}
	post[n] = true;
}

int optimize(pair<int,int> p,int weight){
	return p.first + p.second < weight ? p.first + p.second : weight;
}
int main(){
	int n,k;
	int w;
	int last = 0;
	int i,j;
	scanf("%d%d",&n,&k);
	for (i = 1; i <= n; i++){
		scanf("%d", &student[i]);
		if (student[i] == 0) source.push_back(i);
		party[i] = -1;
		
	}
	//ans init
	for (i = 0; i < source.size(); i++) dfs(source[i], 0);
	for (i = 1; i <= n; i++) dfs(i, 0);
	for (i = 0; i <= k; i++) ans.push_back(make_pair(0,0));
	vector<pair<int, int> > curr(n+1);

	for (i = 0; i < list.size(); i++){
		last = -1;
		w = list[i].first;
		for (j = 0; j <= k; j++){
			
			if (j - w >= 0){
				if (last != ans[j - w].first&&ans[j - w].first + list[i].first>ans[j].first){
					curr[j].first = ans[j - w].first + list[i].first;
					curr[j].second = ans[j - w].second + list[i].second;
					last != ans[j - w].first;
				}
				else
					curr[j] = curr[j - 1] < ans[j] ? ans[j] : curr[j - 1];

			}
			else{
				curr[j] = ans[j];
			}
		}
		ans = curr;
	}

	printf("%d",optimize(ans[k],k));
	return 0;
}