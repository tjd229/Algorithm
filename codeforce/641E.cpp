//category : ft


#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> tm;
map<int, int> ft[1 << 17];
int limit = 1 << 17;
struct Query{
	int a, t, x;
};
Query q[100000];
int moment[100000];
void update(int ix,int key,int diff){	
	while (ix < limit){
		if (ft[ix].find(key) == ft[ix].end())
			ft[ix].insert(make_pair(key,0));
		ft[ix][key] += diff;
		ix += (ix&-ix);
	}
}
int sum(int ix,int key){
	int s = 0;
	while (ix != 0){
		if (ft[ix].find(key) != ft[ix].end())
			s += ft[ix][key];
		ix -= (ix&-ix);
	}
	return s;
}
int main(){
	int i;
	int n;

	scanf("%d",&n);
	for (i = 0; i < n; i++){
		scanf("%d%d%d", &q[i].a, &q[i].t, &q[i].x);
		moment[i] = q[i].t;
	}
	sort(moment, moment + n);
	for (i = 0; i < n; i++){
		if (tm.find(moment[i]) == tm.end()) tm.insert(make_pair(moment[i],i+1));
	}
	for (i = 0; i < n; i++){
		
		switch (q[i].a){
		case 1:			
			update(tm[q[i].t],q[i].x,1);
			break;
		case 2:
			update(tm[q[i].t], q[i].x, -1);
			break;
		case 3:			
			printf("%d\n", sum(tm[q[i].t], q[i].x));
			
		}
		
	}
	
	return 0;
}
