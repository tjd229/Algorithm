//category : graph, tp sort

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> edge[5000];
vector<int> back[5000];
pair<int, int> node_info[5000];
int A, B, E, P;
int visit[5000];
int dfs(int ix,int stamp,vector<int> edge[5000]){
	if (visit[ix] == stamp) return 0;
	visit[ix] = stamp;
	int num = 1;
	for (int i = 0; i < edge[ix].size(); i++) num += dfs(edge[ix][i], stamp, edge);
	return num;
}
int inde(pair<int,int> p){
	return E - p.first - p.second - 1;
}
int main(){
	int x, y;
	int i;
	int a = 0, b = 0;

	int no = 0;
	scanf("%d%d%d%d",&A,&B,&E,&P);
	for (i = 0; i < P; i++){
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		back[y].push_back(x);
	}
	for (i = 0; i < E; i++){
		node_info[i].second += dfs(i, i + 1, edge)-1;
		node_info[i].first += dfs(i, -(i + 1), back)-1;
	}
	sort(node_info, node_info+E);
	for (i = 0; i < E; i++){
		if (1 + node_info[i].first + inde(node_info[i]) <= A) a++;
		if (1 + node_info[i].first + inde(node_info[i]) <= B) b++;
		if (node_info[i].first+1>B){
			no = E - i;
			break;
		}
	}
	printf("%d\n%d\n%d\n",a,b,no);
	
	

	return 0;
}