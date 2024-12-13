#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
set<int> s;
vector<int> v[100001];
int conn[100001], visit[100001];
bool avail;
int root;

void dfs(int val) {
	for (int i = 0; i < v[val].size(); i++) {
		int next = v[val][i];
		if (visit[next] > 0 || next == root) {
			avail = false;
			break;
		}
		visit[next] = 1;
		dfs(next);
	}
}

void test() {
	for (auto it = s.begin(); it != s.end(); it++) {
		int val = conn[*it];
		if (val == 0) {		//root�� ���
			if (root == -1) root = *it;
			else {					//root�� 2�� �̻��� ���
				avail = false;
				break;
			}
		}
		else if (val > 1) {		//�ڽ��̸�, 2���� �̻��� �θ� �� ���
			avail = false;
			break;
		}
	}
	if (root == -1) avail = false;		//root�� ���� ���
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 0, st, e;
	while (1) {
		t++;
		cin >> st >> e;
		if (st == -1 && e == -1) break;
		else if (st == 0 && e == 0) {
			cout << "Case " << t << " is a tree.\n";
			continue;
		}
		//�ʱ�ȭ
		for (auto it = s.begin(); it != s.end(); it++) {
			v[*it].clear();
			conn[*it] = 0;
			visit[*it] = 0;
		}
		s.clear();
		avail = true;
		root = -1;

		s.insert(e);
		s.insert(st);
		v[st].push_back(e);
		conn[e]++;
		while (1) {
			cin >> st >> e;
			if (st == 0 && e == 0) break;
			s.insert(st);
			s.insert(e);
			v[st].push_back(e);
			conn[e]++;
		}
		test();
		if (avail) {
			dfs(root);
			for (auto it = s.begin(); it != s.end(); it++) {
				if (*it == root) continue;
				if (visit[*it] > 1) {
					avail = false;
					break;
				}
			}
		}
		if (avail)
			cout << "Case " << t << " is a tree.\n";
		else
			cout << "Case " << t << " is not a tree.\n";
	}
	return 0;
}