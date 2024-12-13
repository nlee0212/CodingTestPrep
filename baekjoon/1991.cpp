#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int N;
pair<int, int> tree[27];

void preorder(int cur) {
	cout << (char)(cur + 'A');
	if (tree[cur].first != -1) preorder(tree[cur].first);
	if (tree[cur].second != -1) preorder(tree[cur].second);
}

void inorder(int cur) {
	if (tree[cur].first != -1) inorder(tree[cur].first);
	cout << (char)(cur + 'A');
	if (tree[cur].second != -1) inorder(tree[cur].second);
}

void postorder(int cur) {
	if (tree[cur].first != -1) postorder(tree[cur].first);
	if (tree[cur].second != -1) postorder(tree[cur].second);
	cout << (char)(cur + 'A');
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'] = { b == '.' ? -1 : b - 'A', c == '.' ? -1 : c - 'A' };
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	return 0;
}