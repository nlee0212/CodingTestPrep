#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& A, int S, int E) {
	if (S + 1 == E) {
		if (A[S] > A[E]) swap(A[S], A[E]);
		return E;
	}

	int M = (S + E) / 2;
	swap(A[S], A[M]);

	int pivot = A[S];
	int i = S + 1;
	int j = E;

	while (i <= j) {
		while (pivot < A[j] && j > S) j--;
		while (pivot > A[i] && i < E) i++;
		if (i < j) swap(A[i++], A[j--]);
	}

	A[S] = A[j];
	A[j] = pivot;
	return j;
}

void quickSort(vector<int>&A, int S, int E, int K) {
	int pivot = partition(A, S, E); // pivot의 위치

	if (pivot == K) {
		return;
	}
	else if (pivot > K) { // pivot의 왼쪽만 보면 됨
		quickSort(A, S, pivot - 1, K);
	}
	else {
		quickSort(A, pivot + 1, E, K);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// 퀵 정렬
	// pivot을 기준으로 왼쪽에는 pivot보다 작은 값, 오른쪽에는 pivot보다 큰 값이 오도록 하는 정렬 방법
	// pivot을 기준으로 왼쪽과 오른쪽을 나누는 작업을 분할이라고 한다.
	sort(A.begin(), A.end());
	cout << A[K - 1];

	return 0;
}