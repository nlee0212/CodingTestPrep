#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T=10;
	freopen("input.txt", "r", stdin);

	struct Node {
		char data;
		int left=-1;
		int right=-1;
	};
	
	for (int t = 1; t < T + 1; t++) {
		cout << "#" << t << " ";

		int N;
		cin >> N;

		vector<Node> tree(N + 1);

		for (int n = 0; n < N; n++) {
			int idx;
			char data;
			int left, right;
			cin >> idx >> data;
			tree[idx].data = data;
			if (cin.peek() != '\n') {
				cin >> left;
				tree[idx].left = left;
			}
			if (cin.peek() != '\n') {
				cin >> right;
				tree[idx].right = right;
			}
		}

		vector<int> stack;
		vector<bool> visited(N+1,false);
		stack.push_back(1);

		while (!stack.empty()) {
			int cur = stack.back();
			if (tree[cur].left != -1 && !visited[tree[cur].left]) stack.push_back(tree[cur].left);
			else {
				stack.pop_back();
				cout << tree[cur].data;
				visited[cur] = true;
				if (tree[cur].right != -1 && !visited[tree[cur].right]) stack.push_back(tree[cur].right);
			}

		}
		cout << endl;
	}

	return 0;

}