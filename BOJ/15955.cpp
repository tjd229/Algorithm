//djs

#include <stdio.h>
#include <algorithm>
using namespace std;
struct Pt{
	int X, Y;
	int ix;
	int nxt;
	int dist;
}ptX[250001],ptY[250001];
struct Qry{
	int A, B, X;
	int ix;
}qry[250000];
bool ans[250001];
int p[250001];
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main(){
	int i;
	int N, Q;
	for (scanf("%d%d", &N, &Q), i = 1; i <= N; i++){
		scanf("%d%d",&ptX[i].X,&ptX[i].Y);
		p[i] = i;
		ptX[i].ix = i;
		ptY[i] = ptX[i];
	}
	for (i = 0; i < Q; i++) scanf("%d%d%d", &qry[i].A, &qry[i].B, &qry[i].X),qry[i].ix=i;
	sort(qry, qry + Q, [](const Qry q1, const Qry q2){
		return q1.X < q2.X;
	});
	sort(ptX + 1, ptX + 1 + N, [](const Pt p1, const Pt p2){
		return p1.X < p2.X;
	});
	sort(ptY + 1, ptY + 1 + N, [](const Pt p1, const Pt p2){
		return p1.Y < p2.Y;
	});
	for (i = 1; i < N; i++){
		ptX[i].nxt = ptX[i + 1].ix;
		ptX[i].dist = ptX[i + 1].X - ptX[i].X;
		ptY[i].nxt = ptY[i + 1].ix;
		ptY[i].dist = ptY[i + 1].Y - ptY[i].Y;
	}
	ptX[N].dist = ptY[N].dist = 2e9 + 1;
	sort(ptX + 1, ptX + 1 + N, [](const Pt p1, const Pt p2){
		return p1.dist < p2.dist;
	});
	sort(ptY + 1, ptY + 1 + N, [](const Pt p1, const Pt p2){
		return p1.dist < p2.dist;
	});
	int ix = 1;
	int iy = 1;
	for (i = 0; i < Q; i++){
		while (qry[i].X >= ptX[ix].dist){
			join(ptX[ix].ix, ptX[ix].nxt);
			ix++;
		}
		while (qry[i].X >= ptY[iy].dist){
			join(ptY[iy].ix, ptY[iy].nxt);
			iy++;
		}
		int pa = find(qry[i].A);
		int pb = find(qry[i].B);
		ans[qry[i].ix] = (pa == pb);
	}

	for (i = 0; i < Q; i++) printf("%s\n",ans[i]? "YES":"NO");
	return 0;
}
