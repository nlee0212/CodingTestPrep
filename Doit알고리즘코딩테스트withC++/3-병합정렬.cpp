#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& A, int S, int E) {
	int M = (S + E) / 2;
	int i = S;
	int j = M + 1;
	int k = S;
	vector<int> temp(E + 1);
	while (i <= M && j <= E) {
		if (A[i] < A[j]) {
			temp[k++] = A[i++];
		}
		else {
			temp[k++] = A[j++];
		}
	}
	while (i <= M) {
		temp[k++] = A[i++];
	}
	while (j <= E) {
		temp[k++] = A[j++];
	}
	for (int i = S; i <= E; i++) {
		A[i] = temp[i];
	}
}

void mergeSort(vector<int>& A, int S, int E) {
	if (S == E) return;
	int M = (S + E) / 2;
	mergeSort(A, S, M);
	mergeSort(A, M + 1, E);
	merge(A, S, E);
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
	mergeSort(A, 0, N - 1);
	cout << A[K - 1] << '\n';
	return 0;
}