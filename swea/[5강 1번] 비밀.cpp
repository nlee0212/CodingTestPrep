#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

typedef long long ll;
vector<unordered_set<int>> graph;
int maxDepth = 0;
int N, K;
vector<bool> visited;

void djikstra(int start) {
	vector<pair<int, vector<int>>> depth(graph.size());
	vector<bool> visited(graph.size(), false);
	for (int i = 1; i < depth.size(); i++) depth[i] = { -1, {} };
	depth[start] = { 0, {start} };

	vector<int> q;
	q.push_back(start);
	visited[start] = true;
	while (!q.empty()) {
		int cur = q.back();
		q.pop_back();
		vector<int> cur_path = depth[cur].second;
		int cur_depth = depth[cur].first;

		for (int next : graph[cur]) {
			if (cur_depth + 1 >= depth[next].first && find(cur_path.begin(),cur_path.end(),next) == cur_path.end()) {
				depth[next] = { cur_depth + 1, cur_path };
				depth[next].second.push_back(next);
				q.push_back(next);
				if (maxDepth < cur_depth + 1) maxDepth = cur_depth + 1;
			}
		}
	}
	
}

void dfs(int cur, int depth) {
	if (maxDepth < depth) maxDepth = depth;
	visited[cur] = true;
	for (int next : graph[cur]) {
		if (!visited[next]) {
			dfs(next, depth + 1);
		}
	}
	visited[cur] = false;
}

int main() {
	int T;
	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cout << "#" << tc << " ";

		cin >> N >> K;

		graph = vector<unordered_set<int>>(N + 1);
		visited = vector<bool>(N + 1, false);

		for (int i = 0; i < K; i++) {
			int M;
			cin >> M;
			int a, b;
			cin >> a;

			if (M == 1) {
				continue;
			}

			for (int j = 1; j < M; j++) {
				cin >> b;
				graph[a].insert(b);
				a = b;
			}
		}

		for (int i = 1; i <= N; i++) {
			cout << graph[i].size() << " ";
			if (maxDepth < N) dfs(i,1);
		}

		cout << maxDepth << endl;
		maxDepth = 0;
	}

	return 0;
}