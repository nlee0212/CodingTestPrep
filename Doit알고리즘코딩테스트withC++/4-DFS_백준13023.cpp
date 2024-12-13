#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N);
	vector<bool> visited(N, false);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int v = 0; v < N; v++) {
		visited[v] = true;
		for (int i = 0; i < adj[v].size(); i++) {
			int next = adj[v][i];
			if (visited[next]) continue;
			visited[next] = true;
			for (int j = 0; j < adj[next].size(); j++) {
				int next2 = adj[next][j];
				if (visited[next2]) continue;
				visited[next2] = true;
				for (int k = 0; k < adj[next2].size(); k++) {
					int next3 = adj[next2][k];
					if (visited[next3]) continue;
					visited[next3] = true;
					for (int l = 0; l < adj[next3].size(); l++) {
						int next4 = adj[next3][l];
						if (visited[next4]) continue;
						cout << 1 << '\n';
						return 0;
					}
					visited[next3] = false;
				}
				visited[next2] = false;
			}
			visited[next] = false;
		}
		visited[v] = false;
	}

	cout << 0 << '\n';

	return 0;
}