//category : pbs, ft


#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;

vector<int> member[300001];
int goal[300001];
int l[300001], r[300001], mid[300001];
const int BI = 1 << 19;
struct Meteor{
	int l, r, a;
}meteor[300001];
long long ft[BI];
void update(int ix,int val){
	while (ix < BI){
		ft[ix] += val;
		ix += (ix&-ix);
	}
}
long long sum(int ix){
	long long res = 0;
	while (ix != 0){
		res += ft[ix];
		ix -= (ix&-ix);
	}
	return res;
}
int main(){

	int i,j;
	int N, M;
	int k;
	int o;
	int ix;
	long long st;
	scanf("%d%d",&N,&M);
	for (i = 1; i <= M; i++){
		scanf("%d",&o);
		member[o].push_back(i);
	}
	
	for (i = 1; i <= N; i++){
		scanf("%d",goal+i);
	}
	scanf("%d",&k);
	for (i = 1; i <= k; i++){		
		scanf("%d%d%d", &meteor[i].l, &meteor[i].r, &meteor[i].a);
	}
	for (i = 1; i <= N; i++){
		l[i] = 1;
		r[i] = k;
	}
	bool still;
	while (true){
		memset(ft, 0, sizeof(ft));
		vector<vector<int> > pbs_q(k+1);
		still = false;
		for (i = 1; i <= N; i++){
			if (l[i] <= r[i]){
				mid[i] = (l[i] + r[i]) >> 1;
				pbs_q[mid[i]].push_back(i);
				still = true;
			}			
		}
		if (!still) break;
		for (i = 1; i <= k; i++){
			if (meteor[i].l > meteor[i].r){
				update(1, meteor[i].a);
			}
			update(meteor[i].r + 1, -meteor[i].a);
			update(meteor[i].l, meteor[i].a);

			for (j = 0; j < pbs_q[i].size(); j++){
				ix = pbs_q[i][j];
				st = 0;
				for (o = 0; o < member[ix].size(); o++){
					st += sum(member[ix][o]);
					if (st >= goal[ix]) break;
				}
				if (st >= goal[ix]) r[ix] = mid[ix] - 1;
				else l[ix] = mid[ix] + 1;
			}
		}
	}
	for (i = 1; i <= N; i++)
		r[i]==k? printf("NIE\n"):printf("%d\n",r[i]+1);



	return 0;
}


//idea reference : http://jason9319.tistory.com/284