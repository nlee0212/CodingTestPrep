#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	int V;
	cin >> V;

	vector<vector<pair<int, int>>> adj(V);

	for (int i = 0; i < V; i++) {
		int u;
		cin >> u;
		while (true) {
			int v;
			cin >> v;
			if (v == -1) break;
			int w;
			cin >> w;
			adj[u - 1].push_back({ v - 1,w });
		}
	}

	vector<ll> dist(V, 0);
	vector<bool> visited(V, false);
	queue<int> q;

	ll answer = 0;

	q.push(0);
	visited[0] = true;
	int max_node = -1;

	for (int i = 0; i < 2; i++) {
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i].first;
				int w = adj[u][i].second;
				if (visited[v]) continue;
				visited[v] = true;
				dist[v] = dist[u] + w;
				if (dist[v] > answer) {
					answer = dist[v];
					max_node = v;
				}
				q.push(v);
			}
		}

		dist.assign(V, 0);
		visited.assign(V, false);
		q.push(max_node);
		visited[max_node] = true;
	}
	
	cout << answer << '\n';


	return 0;
}