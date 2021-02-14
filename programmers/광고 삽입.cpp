//https://programmers.co.kr/learn/courses/30/lessons/72414
//implementation, line sweeping
#include <string>
#include <vector>
#include <algorithm>
#include<stdio.h>
#define pii pair<int,int>
using namespace std;
long long s[360001];
int parse(string &stamp, int base) {
	int h = (stamp[base] - '0') * 10 + stamp[base + 1] - '0';
	int m = (stamp[base + 3] - '0') * 10 + stamp[base + 4] - '0';
	int s = (stamp[base + 6] - '0') * 10 + stamp[base + 7] - '0';
	return s + m * 60 + h * 3600;
}
string i2log(int t) {
	if (t < 0)
		return "00:00:00";
	string stamp = "";
	int h = t / 3600; t %= 3600;
	int m = t / 60, s = t % 60;
	stamp += h / 10 + '0'; stamp += h % 10 + '0'; stamp += ':';
	stamp += m / 10 + '0'; stamp += m % 10 + '0'; stamp += ':';
	stamp += s / 10 + '0'; stamp += s % 10 + '0';
	return stamp;
}
string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = i2log(-1);
	int end = parse(play_time, 0);
	int len = parse(adv_time, 0);
	for (auto stamp : logs) {
		int st = parse(stamp, 0), ed = parse(stamp, 9);
		++s[st]; --s[ed];
	}
	for (int i = 1; i <= end; ++i) s[i] += s[i - 1];
	for (int i = 1; i <= end; ++i) s[i] += s[i - 1];


	int ed = len-1;
	long long mx = 0;
	for (int st = 0; ed <= end; ++st, ++ed) {
		long long cnt = s[ed];
		if (st > 0) cnt -= s[st - 1];
		if (mx < cnt) {
			mx = cnt;
			answer = i2log(st);
		}
	}

	return answer;
}