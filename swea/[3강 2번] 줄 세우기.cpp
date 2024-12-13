#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<int>> adj(50001);
vector<int> degree(50001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cout << "#" << t << " ";
		int N, M;
		cin >> N >> M;

		for (int i = 0; i <= N; i++) adj[i].clear();
		degree.assign(N + 1, 0);

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;

			adj[a].push_back(b);
			degree[b]++;
		}

		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (degree[i] == 0) q.push(i);
		}

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cout << cur << " ";

			for (int next : adj[cur]) {
				degree[next]--;
				if (degree[next] == 0) q.push(next);
			}
		}

		cout << "\n";
	}

	return 0;
}