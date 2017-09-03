//category : graph, SCC


#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXV 10001
vector<int> edges[10001];
vector<int> back[10001];
vector<pair<int, int> > books;
int c[10001];
bool dfs(int ix,int &num,int stamp){
	if (c[ix] * stamp > 0) return false;
	c[ix] = num*stamp;
	for (int i = 0; i < edges[ix].size(); i++)
		dfs(edges[ix][i], num, stamp);
	c[ix] = num++;
	c[ix] *= stamp;
	books.push_back(make_pair(-c[ix], ix));
	return true;
}
int main(){
	int V, E;
	int A, B;
	int i,j;
	scanf("%d%d",&V,&E);
	for (i = 0; i < E; i++){
		scanf("%d%d",&A,&B);
		edges[A].push_back(B);
		back[B].push_back(A);
	}
	A = 1;
	for (i = 1; i <= V; i++) dfs(i, A, 1);
	sort(books.begin(), books.end());
	for (i = 1; i <= V; i++) edges[i]=back[i];
	for (i = 0; i < books.size(); i++){
		back[0].push_back(books[i].second);
	}
	A = 1;
	B = 0;
	books.clear();
	for (i = 0; i < back[0].size(); i++){
		
		if (dfs(back[0][i], A, -1)){
			B++;
			back[B].clear();
			for (j = 0; j <books.size(); j++){
				back[B].push_back(books[j].second);
			}
			books.clear();
		}
	}
	printf("%d\n",B);
	for (i = 1; i <= B; i++){
		A = MAXV;
		for (j = 0; j < back[i].size(); j++) if (A>back[i][j]) A = back[i][j];		
		for (j = 0; j < back[i].size(); j++) books.push_back(make_pair(A, back[i][j]));
		books.push_back(make_pair(A, MAXV));
	}
	sort(books.begin(), books.end());
	for (i = 0; i < books.size(); i++){
		if (books[i].second == MAXV) printf("-1\n");
		else printf("%d ",books[i].second);
	}


	return 0;
}