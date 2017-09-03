//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
int T;
int A, B;
int ans;
int depth;
int map[10000];
pair<int,int> order[10000];
char inst_list[4] = { 'D', 'S', 'L', 'R' };
bool inst(int x){
	if (x < 0 || x>9999) return false;
	if (x == B){
		ans = depth;
		return true;
	}
	if (map[x] == T + 1) return false;
	map[x] = T + 1;
	return true;
}
int right(int n){
	int d = n % 10;
	n /= 10;
	return d * 1000 + n;
}
int left(int n){
	int a = n / 1000;
	return (n % 1000) * 10 + a;
}
int main(){
	int i;
	int end;
	int num;
	for (scanf("%d", &T); T--;){
		scanf("%d%d",&A,&B);
		vector<int> v;
		v.push_back(A);
		map[A] = T + 1;
		order[A] = make_pair(-1,-1);
		end = 0;
		i = 0;
		ans = -1;
		depth = 0;
		while (end != v.size()){
			end = v.size();
			depth++;
			
			for (; i < end; i++){
				num = (v[i] - 1);
				if (num < 0) num = 9999;
				if (inst(num)){
					v.push_back(num);
					order[num] = make_pair(v[i], 1);
				}
				num = (v[i] << 1) % 10000;
				if (inst(num)){
					v.push_back(num);
					order[num] = make_pair(v[i], 0);
				}
				num = left(v[i]);
				if (inst(num)){
					v.push_back(num);
					order[num] = make_pair(v[i], 2);
				}
				num = right(v[i]);
				if (inst(num)){
					v.push_back(num);
					order[num] = make_pair(v[i], 3);
				}
			}
			if (ans > 0) break;
		}
		i = B;
		v.clear();
		while (i != A){
			v.push_back(order[i].second);
			i = order[i].first;
		}
		for (i = v.size() - 1; i >= 0; i--) printf("%c",inst_list[v[i]]);
		printf("\n");
	}

	return 0;
}