//implementation
//https://programmers.co.kr/learn/courses/30/lessons/68644?language=cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	for (int i = 0; i < numbers.size(); ++i) {
		for (int j = 1+i; j < numbers.size(); ++j) {
			answer.push_back(numbers[i]+numbers[j]);
		}
	}
	sort(answer.begin(), answer.end());
	answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
	return answer;
}