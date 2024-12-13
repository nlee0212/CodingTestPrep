#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 1; t < T + 1; t++) {

		int N, P;
		cin >> N >> P;

		int Q = N / P;
		int R = N % P;

		long long ans;

		if (R == 0) {
			ans = pow(Q, P);
		}
		else {
			ans = pow(Q, P - R) * pow(Q + 1, R);
		}

		cout << "#" << t << " " << ans << endl;
	}

	return 0;

}