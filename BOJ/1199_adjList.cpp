//category : graph

#include <stdio.h>
int graph[1001][1001];
int degree[1001];
int N;
int globalCnt;
struct LinkedList{
	LinkedList *next;
	int ix;
	LinkedList(int _ix) :ix(_ix){ next = NULL; }
	void createNext(int _ix){
		next = new LinkedList(_ix);
	}
};
LinkedList* DFS(int curr,LinkedList* to){
	LinkedList *me = new LinkedList(curr);

	if (curr == to->ix){
		me->next = to->next;
		return me;
	}
	
	for (; degree[curr] <= N;){
		if (graph[curr][degree[curr]] != 0){
			graph[curr][degree[curr]]--;
			if(degree[curr]!=curr) graph[degree[curr]][curr]--;
			globalCnt--;
			me->next = DFS(degree[curr],to);	
			return me;
		}
		else degree[curr]++;
	}
	return me;
}
int main(){

	int i, j;
	int ix;
	scanf("%d",&N);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%d",&graph[i][j]);
			degree[i] += graph[i][j];
			globalCnt += graph[i][j];
			if (i == j) globalCnt += graph[i][j];
			if (i == j) degree[i] += graph[i][j];
		}
	}
	for (i = 1; i <= N; i++){
		if (degree[i] & 1){
            printf("-1");  
            return 0;
        } 
		else degree[i] = 1;
		
	}

	globalCnt >>= 1;
	LinkedList *root,*curr;
	root = new LinkedList(1);
	curr = root;
	while (curr!= NULL){
		ix = curr->ix;
		for (; degree[ix] <= N;){
			if (graph[ix][degree[ix]] != 0){
				graph[ix][degree[ix]]--;
				if (degree[ix] != ix) graph[degree[ix]][ix]--;
				LinkedList *head = DFS(degree[ix],curr);
				curr->next = head;
				globalCnt--;
			}
			if (graph[ix][degree[ix]] == 0) degree[ix]++;

		}
		curr = curr->next;
		
	}

	if (globalCnt != 0){
            printf("-1");  
            return 0;
        } 
	curr = root;
	while (curr != NULL){
		printf("%d ",curr->ix);
		curr = curr->next;
	}	

	return 0;
}
