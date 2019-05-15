//math
#include<bits/stdc++.h>
#include "grader.h"
 
//#include <vector>
using namespace std;
int len[200];
vector < int > findSequence (int N)
{
    vector < int > ans (N, 0);
	int L = (N >> 1) + 1;	
	int cnt[2];
	int i,j;
	if (isSubsequence({ 1 })) {
		int least = 0;
		cnt[0] = cnt[1] = 0;
		vector<int> v(L, 0),inc,dec;
		if (isSubsequence(v)) least = 1;
		int common = 1 - least;
		cnt[least] = -1;
		for (v.clear(), i = 0; isSubsequence(v); ++i) {
			v.push_back(least);
			++cnt[least];
		}
		cnt[common] = N - cnt[least];
		v.clear();
		int sum = 0; //accum least 
		for (i = 0; i < cnt[common]; ++i) {//calc len
			inc.clear();
			dec = v;
			for (j = 0; j < sum; ++j) inc.push_back(least);//[0:sum-1]=least
			for (j = i; j < cnt[common]; ++j) inc.push_back(common);
			for (dec.push_back(common),j = 0; j <1+ cnt[least] - sum; ++j) dec.push_back(least);
			for (;;++len[i]) {//j
				//inc push_front
				inc[sum + len[i]] = least;
				inc.push_back(common);
				//dec pop bk
				dec.pop_back();
				if (inc.size() <= dec.size()) {
					if (!isSubsequence(inc)) break;
				}
				else if (isSubsequence(dec)) break;				
			}
			v.push_back(common);
			sum += len[i];
		}
		/*printf("c:%d,l:%d\n",common,least);
		for (i = 0; i < cnt[common]; ++i)
			printf("l:%d\n",len[i]);
		printf("r:%d-%d=%d\n",cnt[least],sum,cnt[least]-sum);
		printf("%d,%d\n",cnt[0],cnt[1]);*/
		int ix = 0;
		for (i = 0; i < cnt[common]; ++i) {
			while (len[i]--) ans[ix++] = least;
			ans[ix++] = common;
		}
		int r = cnt[least] - sum;
		while (r--) ans[ix++] = least;
	}
    return ans;
}