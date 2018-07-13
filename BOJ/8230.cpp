//math

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int k;
vector<int> squarks[300];
int mass[150 * (300 - 1)];
int main(){
	int i, j, l;
	int n;
	scanf("%d", &n);  //len of squarks[]
	int nm = (n*(n - 1)) >> 1;
	for (i = 0; i < nm; i++) scanf("%d", mass + i);
	sort(mass, mass + nm);

	for (i = 2; i < n; i++){  //s[0]+s[1], s[0]+s[2], (...) , s[1]+s[2] -> len( (...) ) <= n (s[0]+s[:n])

		if (i > 2 && mass[i] == mass[i - 1]) continue;
		unordered_map<int, int> mymass;
		squarks[k].clear();
		squarks[k].push_back(0);
		squarks[k].push_back(0);
		squarks[k].push_back(0);

		squarks[k][0] = mass[0] + mass[1] - mass[i];
		if (squarks[k][0] < 0) break;
		if (squarks[k][0] & 1) continue;
		squarks[k][0] >>= 1;
		squarks[k][1] = mass[0] - squarks[k][0];
		squarks[k][2] = mass[1] - squarks[k][0];
		mymass[mass[0]]++;
		mymass[mass[1]]++;
		mymass[mass[i]]++;
		for (j = 0; j < nm; j++){
			if (mymass[mass[j]] != 0) mymass[mass[j]]--;
			else{
				//printf("new num!\n");
				if (squarks[k].size() == n){
					squarks[k].push_back(-1);
					break;
				}
				int new_s = mass[j] - squarks[k][0];

				if (new_s <= squarks[k].back()) break;
				for (l = 1; l < squarks[k].size(); l++){
					int m = new_s + squarks[k][l];
					mymass[m]++;
				}
				squarks[k].push_back(new_s);
			}
		}
		k += (squarks[k].size() == n);
	}
	printf("%d", k);
	for (i = 0; i < k; i++){
		printf("\n");
		for (auto p : squarks[i]) printf("%d ", p);
	}


	return 0;
}
