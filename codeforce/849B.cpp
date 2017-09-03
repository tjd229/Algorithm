//category : geometry

#include <stdio.h>
#include <utility>
#define ll long long
using namespace std;
pair<ll, ll> pt[1001];
int stamp[1001];
bool line(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
	return (p2.first - p1.first)*(p3.second - p1.second) == (p2.second - p1.second)*(p3.first - p1.first);
}
int main(){
	int i,j;
	int n;
	int cnt = 0;
	pair<ll, ll> f1, s1,f2,s2;
	bool ans = false;
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		scanf("%I64d",&pt[i].second);
		pt[i].first = i;
	}
	f1 = pt[1];
	s1 = pt[2];
	cnt = 2;
	for (i = 3; i <= n; i++){
		cnt += line(f1, s1, pt[i]);
	}
	if (cnt == n){
		printf("No\n");
		return 0;
	}
	for (i = 1; i <= n; i++){
		stamp[1]=stamp[i] = i;
		cnt = 0;
		f1 = pt[1];
		s1 = pt[i];
		bool check = true;
		if (i > 1){
			for (j = 2; j <= n; j++){
				if (line(f1, s1, pt[j]))
					stamp[j] = i;
			}
		}
		for (j = 2; j <= n; j++){
			if (stamp[j] != i){
				if (cnt == 0) f2 = pt[j],cnt++;
				else if (cnt == 1){
					s2 = pt[j], cnt++;
					if (i > 1){
						if ((s2.second - f2.second)*(s1.first - f1.first) != (s1.second - f1.second)*(s2.first - f2.first))
						{
							check = false;
							break;
						}
					}
				}
				else{
					check &= line(f2, s2, pt[j]);
				}
			}
		}
		ans |= check;

	}
	printf("%s",ans? "Yes":"No");
	return 0;
}

