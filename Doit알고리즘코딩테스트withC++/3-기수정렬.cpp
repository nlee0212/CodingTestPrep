#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void radixSort(vector<int>& A, int N, int K) {
	vector<vector<int>> bucket(10);
	int mod = 10;
	int div = 1;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			bucket[(A[j] % mod) / div].push_back(A[j]);
		}
		int idx = 0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < bucket[j].size(); k++) {
				A[idx++] = bucket[j][k];
			}
			bucket[j].clear();
		}
		mod *= 10;
		div *= 10;
	}
}