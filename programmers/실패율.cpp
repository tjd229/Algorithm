//https://www.welcomekakao.com/learn/courses/30/lessons/42889
//math
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int deno[502];
int nume[502];
double f[502];
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	
	for (auto r : stages) ++deno[r],++nume[r];
	for (int i = N; i; --i) deno[i] += deno[i + 1], answer.push_back(i);
	for (int i = 1; i <= N; ++i) {
		f[i] = deno[i] == 0 ? 0 : (double)nume[i] / deno[i];
	}
	sort(answer.begin(), answer.end(),[](int s1,int s2) {
		if (f[s1] == f[s2]) return s1 < s2;
		return f[s1] > f[s2];
	});

	return answer;
}