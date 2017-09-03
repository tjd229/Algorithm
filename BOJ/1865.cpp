//category : graph, SPFA


#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAXVAL (2e9)
struct Node{
	int d;
	int c;
	bool in;
	vector<pair<int, int> >edges;
	void init(){
		c = 0;
		d = MAXVAL;
		edges.clear();
		in = false;
	}
};
Node pt[501];
int main(){
	int T;
	int N, M, W;
	int S, E, H;
	int i;
		
	
	pair<int, int> p;
	for (scanf("%d", &T); T--;){
		scanf("%d%d%d",&N,&M,&W);
		for (i = 1; i <= N; i++) pt[i].init();
		for (i = 0; i < M; i++){
			scanf("%d%d%d",&S,&E,&H);
			pt[S].edges.push_back(make_pair(E, H));
			pt[E].edges.push_back(make_pair(S, H));
			
		}
		for (i = 0; i < W; i++){
			scanf("%d%d%d", &S, &E, &H);
			pt[S].edges.push_back(make_pair(E, -H));			
		}
		queue<int> q;
		q.push(1);
		pt[1].d = 0;
		pt[1].c++;
		pt[1].in = true;
		H = 0;
		while (!q.empty()&&H==0){
			S = q.front();
			q.pop();
			pt[S].in = false;
			for (i = 0; i < pt[S].edges.size(); i++){
				p = pt[S].edges[i];
				E = p.first;
				if (pt[S].d != MAXVAL&&pt[E].d>pt[S].d + p.second){
					pt[E].d = pt[S].d + p.second;
					
					if (!pt[E].in){
						pt[E].c++;
						q.push(E);

						pt[E].in = true;
					}
					if (pt[E].c >= N){
						H = 1;
						break;
					}
				}
			}

		}
		printf("%s\n",H==1? "YES":"NO");
	}


	return 0;
}

