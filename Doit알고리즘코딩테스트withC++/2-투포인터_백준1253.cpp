#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); // C++의 iostream과 C의 stdio의 동기화를 끊는다. 왜? C++의 iostream이 C의 stdio보다 느리기 때문에.
	cin.tie(NULL); // cin과 cout의 묶음을 풀어준다.
	cout.tie(NULL); // cin과 cout의 묶음을 풀어준다.

	int N;
	cin >> N;

	vector<int> A(N, 0); // N개의 0으로 초기화된 벡터 생성

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
				if (i != k && j != k) { // 자기 자신은 제외
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