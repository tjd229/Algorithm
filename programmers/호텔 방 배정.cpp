//implementation
//https://programmers.co.kr/learn/courses/30/lessons/64063
#include <string>
#include <vector>
#include <set>
#define ll long long
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	set<ll> pool, book;
	for (auto x : room_number) {
		if (pool.find(x) == pool.end())
			pool.insert(x);
	}
	for (auto x : room_number) {
		auto it = pool.lower_bound(x);
		ll y = *it;
		answer.push_back(y);
		pool.erase(y);
		book.insert(y);
		if (book.find(y + 1) == book.end())
			pool.insert(y + 1);

	}
	
	return answer;
}