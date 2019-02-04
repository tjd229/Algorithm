//greedy
#include <stdio.h>
#define ll long long
const ll shift_mask= 9187201950435737471;
const ll up_mask = (1LL << 56)-1;
const ll row_mask = (1 << 7 )- 1;
ll mask1, mask2;
ll chunk[50][50];
int board[50][50];
int bit_cnt(ll n) { //__builtin_popcountll
	int cnt = 0;
	while (n) {
		++cnt;
		n -= (n&-n);
	}
	return cnt;
}
int main() {
	int i,j;
	int N, M;
	int ans = 64;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			mask1 <<= 1;
			mask2 <<= 1;
			if ((i+j) & 1) ++mask2;
			else ++mask1;
		}
	}
	for (scanf("%d%d", &N, &M), i = 0; i < N; ++i) {
		char c;
		for (j = 0; j < M; ++j) {
			scanf(" %c",&c);
			board[i][j] = (c == 'W');
		}
	}
	ll &mask = chunk[0][0];
	for (i = 0; i < 8; ++i) {
		for (j = 0; j < 8; ++j) {
			mask <<= 1;
			mask += board[i][j];
		}
	}
	for (j = 1; j + 7 < M; ++j) {
		ll &mask = chunk[0][j];
		mask = chunk[0][j - 1] & shift_mask;
		mask <<= 1;
		for (i = 0; i < 8; ++i) {
			int shift = i * 8;
			mask += ((ll)board[7-i][j + 7] << shift);
		}
	}
	for (i = 1;  i + 7 < N; ++i) {
		ll row = 0;
		for (j = 0; j < 7; ++j) {
			row <<= 1;
			row += board[i + 7][j];
		}
		for (j = 0; j + 7 < M; ++j) {
			row &= row_mask;
			row=(row << 1)+board[i+7][j+7];
			ll &mask = chunk[i][j];
			mask = (chunk[i - 1][j] & up_mask) << 8;
			mask += row;
		}
	}
	
	for (i = 0; i + 7 < N; ++i) {
		for (j = 0; j + 7 < M; ++j) {
			int cnt1 = bit_cnt(mask1^chunk[i][j]);
			int cnt2 = bit_cnt(mask2^chunk[i][j]);
			if (ans > cnt1) ans = cnt1;
			if (ans > cnt2) ans = cnt2;
		}
	}
	printf("%d",ans);
	return 0;
}
