//category : merge st, plain sweeping 

#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int LEAF = 1 << 12;
ll st[LEAF+LEAF],l_val[LEAF+LEAF],r_val[LEAF+LEAF],lr_val[LEAF+LEAF];
struct Mine{
	int x;
	int y;
	int w;
	bool operator <(Mine m) const{
		return y < m.y;
	}
};
vector<Mine> v;
ll max(ll a, ll b){
	return a < b ? b : a;
}
int get_compressed(int val, vector<int> &v){
	return lower_bound(v.begin(), v.end(), val) - v.begin() + 1;
}
void update(int ix,int val){
	while (ix!=0){
		if (ix >= LEAF){
			st[ix] += val;
			l_val[ix] += val;
			r_val[ix] += val;
			lr_val[ix] += val;
		}
		else{
			l_val[ix] = max(l_val[ix + ix], lr_val[ix + ix] + l_val[ix + ix + 1]);
			r_val[ix] = max(r_val[ix + ix+1], lr_val[ix + ix+1] + r_val[ix + ix]);
			lr_val[ix] = lr_val[ix + ix] + lr_val[ix + ix + 1];
			st[ix] = max(st[ix + ix], st[ix + ix + 1]);
			st[ix] = max(st[ix], r_val[ix + ix] + l_val[ix + ix + 1]);
			st[ix] = max(st[ix], max(l_val[ix],r_val[ix]));
		}
		ix >>= 1;
	}
}


int main(){
	int i,j,k;
	int N;	
	ll ans = 0;
	vector<int> comp_x, comp_y;;
	scanf("%d",&N);

	for (i = 0; i < N; i++){
		Mine m;
		scanf("%d%d%d", &m.x, &m.y, &m.w);
		comp_x.push_back(m.x);
		comp_y.push_back(m.y);
		v.push_back(m);
	}
	sort(v.begin(), v.end());
	sort(comp_x.begin(), comp_x.end());
	sort(comp_y.begin(), comp_y.end());
	comp_x.erase(unique(comp_x.begin(), comp_x.end()), comp_x.end());
	comp_y.erase(unique(comp_y.begin(), comp_y.end()), comp_y.end());

	for (j = i = 0; i < N; i++){
		while(v[i].y != comp_y[j]) j++;
		v[i].y = j + 1;
	}
	for (i = 0; i < N; i++) v[i].x = get_compressed(v[i].x,comp_x);

	for (i = 1; i <= comp_y.size(); i++){
		memset(st, 0, sizeof(st));
		memset(l_val, 0, sizeof(l_val));
		memset(r_val, 0, sizeof(r_val));
		memset(lr_val, 0, sizeof(lr_val));
		k = 0;
		while (v[k].y < i) k++;
		
		for (j = i; j <= comp_y.size(); j++){
			while (k < N&&v[k].y == j){
				//update
				update(LEAF+v[k].x-1,v[k].w);
				k++;				
			}

			if (ans < st[1]) ans = st[1];


		}
		
	}
	printf("%lld",ans);

	

	return 0;
}
//idea reference : https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220605936611&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F