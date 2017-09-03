//category : dp

#include <stdio.h>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
pii flower[1500 * 1500];
pii max_r[1500][4], max_c[1500][4];
int N,NN;
int R, C;
int cnt[1500 * 1500];

int get_max(pii arr[4],int low,int high){
	for (int i = 3; i >= 0; i--){
		if (arr[i].second<low || arr[i].second>high)
			return arr[i].first;
	}
	return 0;
}
int max(int a, int b){ return a < b ? b : a; }
int main(){
	int i,j;
	int petal; 
	int ans = 1;
	
	scanf("%d", &N);
	scanf("%d%d", &R,&C);
	NN = N*N;
	int RC = (R-1)*N + C-1;
	for (i = 0; i < NN; i++){
		scanf("%d",&petal);
		flower[i] = make_pair(petal,i);
	}

	petal = flower[RC].first;	
	//init
	cnt[RC] = 1;
	max_r[R - 1][3] = make_pair(1, C - 1);
	max_c[C - 1][3] = make_pair(1, R - 1);

	sort(flower, flower + NN);

	for (i = 0; i < NN;){
		if (flower[i].first <= petal){
			i++;
			continue;
		}
		for (j = i;j<NN&&flower[i].first==flower[j].first; j++){
			R = flower[j].second / N;
			C = flower[j].second % N;

			if (C > 0)  cnt[flower[j].second]=max(cnt[flower[j].second], get_max(max_c[C - 1], R - 1, R + 1));
			if (C <N-1) cnt[flower[j].second]=max(cnt[flower[j].second], get_max(max_c[C + 1], R - 1, R + 1));
			if (R > 0)  cnt[flower[j].second]=max(cnt[flower[j].second], get_max(max_r[R - 1], C - 1, C + 1));
			if (R < N-1)cnt[flower[j].second]= max(cnt[flower[j].second], get_max(max_r[R + 1], C - 1, C + 1));
			if (cnt[flower[j].second]>0) cnt[flower[j].second] += 1;
			ans = max(ans, cnt[flower[j].second]);
		}
		for (j = i; j < NN&&flower[i].first == flower[j].first; j++){
			R = flower[j].second / N;
			C = flower[j].second % N;

			if (max_r[R][0].first<cnt[flower[j].second])
				max_r[R][0] = make_pair(cnt[flower[j].second], C);
			if (max_c[C][0].first<cnt[flower[j].second])
				max_c[C][0] = make_pair(cnt[flower[j].second], R);
			sort(max_r[R], max_r[R] + 4);
			sort(max_c[C], max_c[C] + 4);
		}
		i = j;
	}

	printf("%d",ans);
	return 0;
}

//reference : https://github.com/mukel/ProgrammingContests/blob/master/OldStuff/Croacia/2009/Contest%201/skakavac.cpp