//math
#include "coins.h"

std::vector<int> coin_flips(std::vector<int> b, int c) {
	for (int i = 0; i < b.size(); ++i) if (b[i]) c ^= i;
	return { c };
}

int find_coin(std::vector<int> b) {
	int c = 0;
	for (int i = 0; i < b.size(); ++i) if (b[i]) c ^= i;
	return c;
}
