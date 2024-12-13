#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// 퀵 정렬
	// pivot을 기준으로 왼쪽에는 pivot보다 작은 값, 오른쪽에는 pivot보다 큰 값이 오도록 하는 정렬 방법
	// pivot을 기준으로 왼쪽과 오른쪽을 나누는 작업을 분할이라고 한다.

	int pivot = A[0];

	vector<int> left, right;
	for (int i = 1; i < N; i++) {
		if (A[i] < pivot) left.push_back(A[i]);
		else right.push_back(A[i]);
	}

	return 0;
}