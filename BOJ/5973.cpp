//category : geometry

#include <stdio.h>
#include <map>
using namespace std;
int X[1000], Y[1000];
int main(){
	int N;
	int i,j;
	int ans = 0;
	map<pair<int,int>,int> m;
	pair<int,int> cent;
	scanf("%d", &N);
	for (i = 0; i < N;i++){
		scanf("%d%d",X+i,Y+i);
	}
	for (i = 0; i < N; i++){
		for (j = i + 1; j < N; j++){
			cent.first = (X[i] + X[j]);
			cent.second = (Y[i] + Y[j]);
			if (m.find(cent) == m.end()) m.insert(make_pair(cent,0));
			m[cent]++;
		}
	}
	for (auto it = m.begin(); it != m.end(); it++){
		N = it->second;
		ans += (N - 1)*N;
	}
	printf("%d",ans>>1);


	return 0;
}