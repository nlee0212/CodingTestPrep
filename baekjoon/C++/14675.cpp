#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int N, Q;
vector<int> Tree[MAX];

int main() {
	FASTIO
	
	cin >> N;
	for (int i = 0; i < (N - 1); i++) {
		int A, B;
		cin >> A >> B;
		Tree[A].push_back(B);
		Tree[B].push_back(A);
	}
	cin >> Q;
	
	while (Q--) {
		int T, K;
		cin >> T >> K;
		if (T == 1) { // K�� ������ �������ΰ�?
			if (Tree[K].size() >= 2) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
		else if (T == 2) { // K��° ������ �������ΰ�?
			cout << "yes\n";
		}
	};

	return 0;
}