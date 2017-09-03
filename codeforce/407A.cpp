//category : ccw, geometry

#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
#define MAX(a,b) a<b? b:a
#define vec_pair vector<pair<int,int> >
int a, b;
int sq[1000001];
int dx[6] = {-1,1,1,-1,-1,1};
int dy[6] = {1,1,-1,-1,1,1};
vec_pair a_pair;
vec_pair b_pair;
int ccw3(vec_pair v){
	int res1 = (v[1].first - v[0].first)*(v[2].second - v[0].second);
	int res2 = (v[2].first - v[0].first)*(v[1].second - v[0].second);
	if (res1 == res2) return 0;
	else return 1;
}
bool is_paralle(vec_pair v){
	int i, j;
	for (i = 0; i < v.size(); i++){
		for (j = 0; j < v.size(); j++){
			if (i == j) continue;
			if (v[i].first == v[j].first || v[i].second == v[j].second)
				return true;
		}
	}
	if (v.size() == 3 && ccw3(v) == 0) return true;
	return false;
}
vec_pair leg(vec_pair now){
	int i,j,k,l;
	int x, y;
	for (i = now.size() - 1; i >= 0; i--){
		x = now[i].first;
		y = now[i].second;
		for (j = 0; j < a_pair.size(); j++){
			for (k = 1; k <= 4; k++){
				now.push_back(make_pair(x + dx[k] * a_pair[j].first, y + dy[k] * a_pair[j].second));
				for (l = 0; l < b_pair.size(); l++){
					if (dx[k] * a_pair[j].first*dx[k + 1] * b_pair[l].first
						+ dy[k] * a_pair[j].second*dy[k + 1] * b_pair[l].second == 0){

						now.push_back(make_pair(x + dx[k + 1] * b_pair[l].first, y + dy[k + 1] * b_pair[l].second));
						if (is_paralle(now)) now.pop_back();
						else return now;
					}
					if (dx[k] * a_pair[j].first*dx[k - 1] * b_pair[l].first
						+dy[k] * a_pair[j].second*dy[k - 1] * b_pair[l].second == 0){
						now.push_back(make_pair(x + dx[k - 1] * b_pair[l].first, y + dy[k - 1] * b_pair[l].second));
						if (is_paralle(now)) now.pop_back();
						else return now;
					}
				}
				now.pop_back();
			}
		}
	}
	return now;
}

int main(){
	int i, j;
	scanf("%d%d",&a,&b);
	j = MAX(a, b);
	j *= j;
	for (i = 1; i*i <= j; i++)
		sq[i*i] = i;
	for (i = 1, j = a*a; i < j; i++){
		if (sq[i] != 0 && sq[j - i] != 0) a_pair.push_back(make_pair(sq[i],sq[j-i]));
	}
	
	for (i = 1, j = b*b; i < j; i++){
		if (sq[i] != 0 && sq[j - i] != 0) b_pair.push_back(make_pair(sq[i], sq[j - i]));
	}
	
	vec_pair ans;
	ans.push_back(make_pair(0, 0));
	ans = leg(ans);

	if (ans.size() != 3){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for (i = 0; i < ans.size(); i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;

}