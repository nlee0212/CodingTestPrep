#include <iostream>
#include <queue>

using namespace std;

int k, arr[1024];
int g_prev = -1;

void get_mid(int s, int e) {
	queue<pair<int, int>> q;
	q.push({ s, e });

	while (!q.empty()) {
		int e = q.front().second;
		int s = q.front().first;
		q.pop();

		if (g_prev != e - s) {
			g_prev = e - s;
			cout << '\n';
		}
		if (s == e) cout << arr[s] << ' ';
		else {
			int mid = (s + e) / 2;
			cout << arr[mid] << ' ';

			q.push(make_pair(s, mid - 1));
			q.push(make_pair(mid + 1, e));
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> k;
	for (int i = 0; i < (1 << k) - 1; i++) cin >> arr[i];
	int prev = (1 << k) - 2;
	g_prev = prev;
	get_mid(0, (1 << k) - 2);
}