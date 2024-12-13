#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); // C++�� iostream�� C�� stdio�� ����ȭ�� ���´�. ��? C++�� iostream�� C�� stdio���� ������ ������.
	cin.tie(NULL); // cin�� cout�� ������ Ǯ���ش�.
	cout.tie(NULL); // cin�� cout�� ������ Ǯ���ش�.

	int N;
	cin >> N;

	vector<int> A(N, 0); // N���� 0���� �ʱ�ȭ�� ���� ����

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int count = 0;

	for (int k = 0; k < N;k++) {
		int i = 0, j = N - 1;
		int K = A[k];

		while (i < j) {
			int sum = A[i] + A[j];
			if (sum == K) {
				if (i != k && j != k) { // �ڱ� �ڽ��� ����
					count++;
					break;
				}
				else if (i == k) i++;
				else j--;
			}
			else if (sum < K) i++;
			else j--;
		}
	}

	cout << count << endl;
}