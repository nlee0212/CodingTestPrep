#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e5 + 3;
const int MAX = 2e5 + 1;
int L;
char input[MAX];
vector<int> table[MOD];

inline int __mod(ll n) {
	if (n >= 0) return n % MOD;
	return ((-n / MOD + 1) * MOD + n) % MOD;
}

bool check(int mid) {
	int H = 0;
	int power = 1;
	for (int i = 0; i <= L - mid; i++) {
		if (i == 0) {
			for (int j = 0; j < mid; j++) {
				H = __mod(H + 1LL * input[mid - 1 - j] * power);
				if (j < mid - 1) power = __mod(power * 2);
			}
		}
		else {
			H = __mod(2 * (H - 1LL * input[i - 1] * power) + input[i + mid - 1]);
		}
		if (!table[H].empty()) {
			int tsize = table[H].size();
			for (int j = 0; j < tsize; j++) {
				int pos = table[H][j];
				for (int k = 0; k < mid; k++) {
					if (input[pos + k] != input[i + k]) goto SKIP;
				}
				if (0) {
				SKIP: continue;
				}
				return true;
			}
		}
		table[H].push_back(i);
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> L >> input;
		int left = 0, right = L;

		while (left < right) {
			int mid = (left + right + 1) / 2;
			for (int i = 0; i < MOD; i++) table[i].clear();
			if (check(mid)) {
				left = mid;
			}
			else {
				right = mid - 1;
			}
		}
		cout << "#" << tc << " " << left << "\n";
	}
	return 0;
}