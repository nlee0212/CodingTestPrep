#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cout << "#" << t << " ";

		int N, L, R;
		cin >> N >> L >> R;

		if (L == 1 && R == 1) {
			if (N == 1) cout << "1\n";
			else cout << "0\n";
			continue;
		}

		else if (N == 1) {
			cout << "0\n";
			continue;
		}

		ll dp[21][21][21] = { 0, };
		dp[1][1][1] = 1;

		for (int n = 2; n <= N; n++) {
			for (int l = 1; l <= N; l++) {
				for (int r = 1; r <= N; r++) {
					dp[n][l][r] = dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1] + dp[n - 1][l][r] * (n - 2);
				}
			}
		}

		cout << dp[N][L][R] << "\n";
	}

	return 0;
}