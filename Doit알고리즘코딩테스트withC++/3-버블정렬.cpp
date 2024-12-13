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

	for (int i = 0; i < N - 1; i++) {
		// 만약 특정한 루프의 전체 영역에서 swap이 한 번도 발생하지 않았다면
		// 이미 정렬된 상태이므로 더 이상의 반복은 무의미하다. -> 종료
		bool change = false;

		for (int j = 0; j < N - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				change = true;
			}
		}
		if (!change) break;
	}

	for (int n : A) {
		cout << n << " ";
	}

	return 0;
}