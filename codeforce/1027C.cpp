//greedy

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int i;
	int T;
	int n,a;
	
	for (scanf("%d", &T); T--;){
		vector<int> v,v2,v4;
		int ans1, ans2;
		int a;
		double mn = -1;
		for (scanf("%d", &n), i = 0; i < n; i++){
			scanf("%d",&a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		v.push_back(1e5+5);
		int last = -1;
		int cnt = 0;
		for (i = 0; i < v.size(); i++){
			if (last != v[i]){
				if (cnt >= 2) v2.push_back(last);
				if (cnt >= 4) v4.push_back(last);
				cnt = 1;
			}
			else cnt++;
			last = v[i];
		}
		for (auto num : v4){
			long long P = num*4;
			long long P2 = P*P;
			long long S = num*num;
			double pds = P2 / (double)S;
			if (mn<0 || mn>pds){
				mn = pds;
				ans1 = ans2 = num;
			}
		}
		last = -1;
		v2.push_back(1e5+5);
		for (i = 0; i < v2.size()-1; i++){
			if (last != -1){
				long long P = last*2+2*v2[i];
				long long P2 = P*P;
				long long S = v2[i]*last;
				double pds = P2 / (double)S;
				if (mn<0 || mn>pds){
					mn = pds;
					ans1 = last;
					ans2 = v2[i];
				}
			}
			last = v2[i];
		}
		printf("%d %d %d %d\n",ans1,ans1,ans2,ans2);
	}

	return 0;
}
