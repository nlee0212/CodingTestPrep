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

	// �� ����
	// pivot�� �������� ���ʿ��� pivot���� ���� ��, �����ʿ��� pivot���� ū ���� ������ �ϴ� ���� ���
	// pivot�� �������� ���ʰ� �������� ������ �۾��� �����̶�� �Ѵ�.

	int pivot = A[0];

	vector<int> left, right;
	for (int i = 1; i < N; i++) {
		if (A[i] < pivot) left.push_back(A[i]);
		else right.push_back(A[i]);
	}

	return 0;
}