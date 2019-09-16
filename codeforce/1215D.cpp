//game
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
string ticket;
int lsum; int rsum;
int le, re;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; 
	cin >> n >> ticket;
	//ticket = "0000??09"; n = ticket.size();
	int half = n >> 1;
	int l = 0, r = half;
	int happy=0;
	for (; r < n; ++l, ++r) {
		if (ticket[l] == '?') ++le;
		else lsum += ticket[l] - '0';
 
		if (ticket[r] == '?') ++re;
		else rsum += ticket[r] - '0';
	}
	int mn = min(le, re);
	le -= mn; re -= mn;
	int diff = lsum - rsum;
	if (diff < 0) diff = -diff;
	int e = le + re;//one of both is 0
	
	if (e == 0) happy = (diff == 0);
	else {
		int turn = e >> 1;
		happy = ((turn * 9) == diff);
		if (lsum < rsum && le == 0) happy = 0;
		if (lsum > rsum && re == 0) happy = 0;
	}
	if (happy) cout << "Bicarp";
	else cout << "Monocarp";
	return 0;
}