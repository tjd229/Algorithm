//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[100001];
vector<int> child[100001];
int pre[100001];
int post[100001];
int low[100001];
int cnt;
int min(int a, int b){ return a < b ? a : b; }
int make_tree(int x,int from){
	if (pre[x] != 0) return low[x];
	cnt++;
	pre[x] = low[x] = cnt;
	for (int i = 0; i < edge[x].size(); i++){
		if (pre[edge[x][i]] == 0){
			low[x] = min(low[x], make_tree(edge[x][i], x));
			child[x].push_back(edge[x][i]);
		}
		else if (edge[x][i] != from) low[x] = min(low[x], pre[edge[x][i]]);
	}

	cnt++;
	post[x] = cnt;
	return low[x];
}
bool is_descendant(int A,int B){
	return pre[B]<=pre[A] && post[B]>=post[A];
}
int find_related_child(int A,int B){
	int left = 0;
	int right = child[A].size() - 1;
	int mid;
	while (left != right){
		int mid = (left + right) / 2;
		if (pre[B] > post[child[A][mid]])
			left = mid + 1;
		else if (post[B] < pre[child[A][mid]])
			right = mid - 1;
		else left = right = mid;
		
	}
	return child[A][left];
}
bool query1(int A,int B,int G){
	return low[G] < pre[G] || is_descendant(A, G) == is_descendant(B, G);
}
bool query2(int A,int B,int C){
	bool AC = is_descendant(A,C);
	bool BC = is_descendant(B,C);
	if ( !(AC|BC) ) return true;
	else if (AC&BC){
		int ga = find_related_child(C, A);
		int gb = find_related_child(C, B);
		return (ga==gb)||(low[ga] < pre[C] && low[gb] < pre[C]);
	}
	int G = AC ? A : B;
	return low[find_related_child(C,G)] < pre[C];
}
int main(){
	int i, j;
	int N, E;
	int Q;
	int A, B, G1, G2;
	scanf("%d%d",&N,&E);
	for (i = 0; i < E; i++){
		scanf("%d%d",&A,&B);
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	for (i = 1; i <= N; i++) make_tree(i, 0);
	
	scanf("%d",&Q);
	for (i = 0; i < Q; i++){
		scanf("%d", &j);
		if (j == 1){
			scanf("%d%d%d%d",&A,&B,&G1,&G2);
			if (query1(A,B,is_descendant(G1,G2)? G1:G2))
				printf("yes\n");
			else printf("no\n");
		}
		else{
			scanf("%d%d%d", &A, &B, &G1);
			if (query2(A,B,G1))
				printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}