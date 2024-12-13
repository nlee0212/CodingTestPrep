#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

int main() {

	int T = 10;
	freopen("input.txt", "r", stdin);

	struct Node {
		string data;
		int left = -1;
		int right = -1;
	};

	unordered_set<string> operators = { "+","-","/","*" };

	for (int t = 1; t < T + 1; t++) {
		cout << "#" << t << " ";

		int N;
		cin >> N;

		vector<Node> tree(N + 1);
		for (int n = 0; n < N; n++) {
			int idx;
			string data;
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
		vector<float> calculate;
		vector<bool> visited(N + 1, false);
		stack.push_back(1);
		bool is_num = false;

		while (!stack.empty())
		{
			int cur = stack.back();
			if (tree[cur].left != -1 && !visited[tree[cur].left]) stack.push_back(tree[cur].left);
			else if (tree[cur].right != -1 && !visited[tree[cur].right]) stack.push_back(tree[cur].right);
			else {
				stack.pop_back();
				visited[cur] = true;
				if (operators.find(tree[cur].data) != operators.end()) {
					float num2 = calculate.back();
					calculate.pop_back();
					float num1 = calculate.back();
					calculate.pop_back();
					if (tree[cur].data == "+") calculate.push_back(num1 + num2);
					else if (tree[cur].data == "-") calculate.push_back(num1 - num2);
					else if (tree[cur].data == "*") calculate.push_back(num1 * num2);
					else if (tree[cur].data == "/") calculate.push_back(num1 / num2);
				}
				else calculate.push_back(stof(tree[cur].data));
			}
		}

		cout << int(calculate.back()) << endl;
	}

	return 0;
}