#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int V, E, A, B;
		cin >> V >> E >> A >> B;

		struct Node {
			int parent=0;
			int left=-1;
			int right = -1;
		};

		vector<Node> graph(V + 1);
		vector<int> depth(V + 1);
		vector<int> child_cnt(V + 1,0);

		for (int i = 0; i < E; ++i) {
			int u, v;
			cin >> u >> v;
			graph[v].parent = u;

			if (graph[u].left == -1) graph[u].left = v;
			else graph[u].right = v;
		}

		// A의 조상 노드들을 탐색하며 깊이를 계산
		int a = A;
		while (a != 0) {
			depth[a] = 1;
			a = graph[a].parent;
		}
		// B의 조상 노드들을 탐색하며 A의 조상 노드와 겹치는지 확인
		int b = B;
		int common = 0;
		while (b != 0) {
			if (depth[b] == 1) {
				common = b;
				break;
			}
			b = graph[b].parent;
		}
		// 공통 조상 노드의 자손 노드 개수 계산
		int cnt = 0;
		int node = common;
		vector<int> stack;
		stack.push_back(node);
		while (!stack.empty()) {
			node = stack.back();
			stack.pop_back();
			cnt++;
			if (graph[node].left != -1) stack.push_back(graph[node].left);
			if (graph[node].right != -1) stack.push_back(graph[node].right);
		}


		cout << "#" << test_case << " " << common << " " << cnt << "\n";
	}

	return 0;
}