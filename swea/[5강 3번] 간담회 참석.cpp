#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;
vector<vector<pair<int, int>>> graph;
vector<vector<pair<int, int>>> reverse_graph;

vector<ll> dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cout << "#" << t << " ";

		int N, M, X;
		cin >> N >> M >> X;
		int max_dist = 0;
		graph.clear();
		reverse_graph.clear();

		for (int i = 0; i <= N; i++) graph.push_back({});
		for (int i = 0; i <= N; i++) reverse_graph.push_back({});

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back({ b, c });
			reverse_graph[b].push_back({ a, c });
		}

		ll cur_dist = 0;

		dist = vector<ll>(N + 1, 1e18);
		dist[X] = 0;
		priority_queue<pair<ll, int>> pq;
		pq.push({ 0, X });
		while (!pq.empty()) {
			ll cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (dist[cur] < cost) continue;
			for (pair<int, int> next : graph[cur]) {
				int nextNode = next.first;
				int nextCost = next.second;
				if (dist[nextNode] > dist[cur] + nextCost) {
					dist[nextNode] = dist[cur] + nextCost;
					pq.push({ -dist[nextNode], nextNode });
				}
			}
		}
		vector<ll> x_dist = dist;

		dist = vector<ll>(N + 1, 1e18);
		dist[X] = 0;
		pq.push({ 0, X });
		while (!pq.empty()) {
			ll cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (dist[cur] < cost) continue;
			for (pair<int, int> next : reverse_graph[cur]) {
				int nextNode = next.first;
				int nextCost = next.second;
				if (dist[nextNode] > dist[cur] + nextCost) {
					dist[nextNode] = dist[cur] + nextCost;
					pq.push({ -dist[nextNode], nextNode });
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			if (max_dist < x_dist[i] + dist[i]) max_dist = x_dist[i] + dist[i];
		}

		cout << max_dist << "\n";
	}

	return 0;
}