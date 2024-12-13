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

	int T=10;

	for (int t = 1; t < T + 1; t++) {
		int V, E;
		cin >> V >> E;

		vector<vector<int>> graph(V + 1, vector<int>()); // size: (V+1) x 0, 추후 push_back을 통해 각 노드의 자식 노드들을 저장
		vector<int> degree(V + 1, 0);

		cout << "#" << t << " ";

		for (int i = 0; i < E; ++i) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			degree[v]++;
		}

		vector<int> queue;
		for (int i = 1; i <= V; ++i) {
			if (degree[i] == 0) {
				queue.push_back(i);
			}
		}

		while (!queue.empty()) {
			int u = queue.back();
			queue.pop_back();
			cout << u << " ";
			for (int v : graph[u]) {
				degree[v]--;
				if (degree[v] == 0) {
					queue.push_back(v);
				}
			}
		}

		cout << endl;
	}

	return 0;
}