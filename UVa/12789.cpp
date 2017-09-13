//Space Invaders
//category : graph, djs
#include <stdio.h>
#include <deque>
using namespace std;
char shield[1002][1000];
int p[1002*1000];
//int shot[10000];
int shot;
deque<int> dq[1000];
int r, c, s;
int to1D(int x,int y){
	return x + y*c;
}
int find(int ix){
	if (p[ix] != ix) p[ix] = find(p[ix]);
	return p[ix];
}
void joint(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) p[b] = a;
	else p[a] = b;
}
int main(){
	int i, j;
	int cnt;
	int ans;
	int sign=1;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (scanf("%d%d%d", &r, &c, &s) == 3){

		
		cnt = 0;
		ans = -1;
		
		for (i = 0; i <= r+1; i++){
			for (j = 0; j < c; j++){
				p[to1D(j, i)] = to1D(j, i);
			}
		}
		for (j = 0; j < c; j++){
			dq[j].clear();
			shield[0][j] = '.';
			shield[r+1][j] = '.';
		}
		
		for (i = 1; i <= r; i++){
			for (j = 0; j < c; j++){
				scanf(" %c", &shield[i][j]);
				if (shield[i][j] == '#') dq[j].push_back(i);
			}
		}
		

		for (i = 0; i <= r + 1; i++){
			for (j = 0; j < c; j++){
				if (i < r + 1){
					if (shield[i][j] == '.'&&shield[i + 1][j] == '.')
						joint(to1D(j, i), to1D(j, i + 1));
				}
				if (j<c-1){
					if (shield[i][j] == '.'&&shield[i][j+1] == '.')
						joint(to1D(j, i), to1D(j+1, i));
				}
			}
		}
		
		if (find(0) == find(to1D(0, r + 1))) ans = 0;
		for (i = 1; i <= s; i++){
			scanf("%d", &shot);
			if (ans == -1){
				if (shot > 0){
					shot--;
					cnt = dq[shot].front();
					dq[shot].pop_front();
					shield[cnt][shot] = '.';
					sign = 1;
				}
				else{
					shot = -shot;
					shot--;
					cnt = dq[shot].back();
					dq[shot].pop_back();
					shield[cnt][shot] = '.';
					sign = -1;
				}
				if (shot > 0){
					if (shield[cnt][shot] == '.'&&shield[cnt][shot - 1] == '.')
						joint(to1D(shot, cnt), to1D(shot - 1, cnt));
				}
				if (shot < c-1){
					if (shield[cnt][shot] == '.'&&shield[cnt][shot + 1] == '.')
						joint(to1D(shot, cnt), to1D(shot + 1, cnt));
				}
				if (cnt>0){
					if (shield[cnt][shot] == '.'&&shield[cnt - 1][shot] == '.')
						joint(to1D(shot, cnt), to1D(shot, cnt - 1));
				}
				if (cnt<r+1){
					if (shield[cnt][shot] == '.'&&shield[cnt + 1][shot] == '.')
						joint(to1D(shot, cnt), to1D(shot, cnt + 1));
				}

				if (find(0) == find(to1D(0, r + 1))) ans = i;
			}
		}
		if (ans == -1) printf("X\n");
		else printf("%d\n",ans*sign);
	}
	

	return 0;
}