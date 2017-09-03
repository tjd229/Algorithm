//category : dp

#include <iostream>
#include <string>
using namespace std;
string map[11];
int N, M;
int max_s;
int d[11][2048];
int visit[11][2048];
int max(int a, int b){ return a > b ? a : b; }
int assign(int n,int s,int stamp){
	if (visit[n][s] == stamp) return d[n][s];
	
	d[n][s] = 0;
	visit[n][s] = stamp;
	int i;
	int cnt = 0;
	for (i = 0; i < M; i++){
		if (s&(1 << i)){
			if (map[n][i] == 'x') return 0;
			if (i > 0 && s&(1 << (i - 1))) return 0;
			if (i < M-1 && s&(1 << (i + 1))) return 0;
			cnt++;
		}
	}
	
	if (n != 1){
		for (i = 0; i < max_s; i++){
			if (!((i << 1)&s) && !((i >> 1)&s))
				d[n][s] = max(d[n][s], assign(n - 1, i, stamp));
		}
	}
	d[n][s] += cnt;
	return d[n][s];
}

int main(){
	int i;
	int C;
	int ans = 0;
	cin >> C;
	while (C--){
		cin >> N >> M;
		for (i = 1; i <= N; i++){
			cin >> map[i];
			
		}
		max_s = 1 << M;
		ans = 0;
		for (i = 0; i < max_s; i++)
			ans = max(ans, assign(N, i, C + 1));
		cout << ans << "\n";
	}
	
	
	return 0;
}
