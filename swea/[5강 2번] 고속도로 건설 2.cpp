#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;

priority_queue<pair<int, pair<int,int>>> pq;
unordered_map<int, int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cout << "#" << t << " ";

		int N, M;
		ll answer = 0;
		cin >> N >> M;

		for (int i = 1; i <= N; i++) parent[i] = i;

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (a < b) pq.push({ -c,{a,b} });
			else pq.push({ -c,{b,a} });
		}

		while (!pq.empty()) {
			int cost = -pq.top().first;
			pair<int,int> path = pq.top().second;
			pq.pop();
			int p1 = find(path.first);
			int p2 = find(path.second);
			if (p1 == p2) continue;
			if (p1 < p2) merge(p1, p2);
			else merge(p2, p1);
			answer += cost;
		}

		cout << answer << "\n";
		parent.clear();
	}

	return 0;
}