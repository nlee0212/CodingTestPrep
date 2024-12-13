#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int main() {

	int N, M;
	cin >> N >> M;

	vector<int> bluerays(N);
	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> bluerays[i];
		sum += bluerays[i];
	}

	int left = 0, right = sum;
	int answer = sum;
	int mid = (left + right) / 2;

	while (left < right) {
		int cnt = 0;
		int cur_disk = 0;
		int cur_disk_len = 0;

		while (cnt < M && cur_disk < N) {
			if (cur_disk_len + bluerays[cur_disk] <= mid) {
				cur_disk_len += bluerays[cur_disk];
				cur_disk++;
			}
			else {
				cnt++;
				cur_disk_len = 0;
			}
		}

		if (cur_disk == N) {
			answer = min(answer, mid);
			right = mid;
		}
		else {
			left = mid + 1;
		}

		mid = (left + right) / 2;
	}

	cout << answer << '\n';

	return 0;
}