#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int index = 1;
	int N;
	cin >> N;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	while (index < N) {
		int n = A[index];
		for (int i = index - 1; i >= 0; i--) {
			if (A[i] > n) {
				A[i + 1] = A[i];
				A[i] = n;
			}
			else {
				break;
			}
		}
		index++;
	}

	for (int n : A) {
		cout << n << " ";
	}

	return 0;
}