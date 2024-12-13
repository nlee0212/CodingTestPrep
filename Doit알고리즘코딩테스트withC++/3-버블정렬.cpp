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
		// ���� Ư���� ������ ��ü �������� swap�� �� ���� �߻����� �ʾҴٸ�
		// �̹� ���ĵ� �����̹Ƿ� �� �̻��� �ݺ��� ���ǹ��ϴ�. -> ����
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