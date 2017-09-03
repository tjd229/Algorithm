//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[50];
int p[50];
int leaf;
void dfs(int ix){
	if (edge[ix].size() == 0){
		leaf++;
		return;
	}
	for (int i = 0; i < edge[ix].size(); i++) dfs(edge[ix][i]);
}
int main(){
	int N;
	int root;
	int r;
	int i;
	scanf("%d",&N);
	for (i = 0; i < N; i++){
		scanf("%d", p + i);
		if (p[i] == -1) root = i;
	}
	scanf("%d",&r);
	if (root == r) printf("0");
	else{
		for (i = 0; i < N; i++){
			if (i != r&&i != root){
				edge[p[i]].push_back(i);
			}
		}		
		dfs(root);
		printf("%d", leaf);
	}


	return 0;
}