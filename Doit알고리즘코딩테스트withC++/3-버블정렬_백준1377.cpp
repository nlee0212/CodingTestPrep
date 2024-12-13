#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector <pair< int, int >> A(N, { 0, 0 });
	//vector <int> change(N, 0);

	int max_change = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin(), A.end());

	int MAX = 0;
	for (int i = 0; i < N; i++) {
		if (MAX < A[i].second - i) MAX = A[i].second - i;
	}

	cout << MAX + 1 << endl;

	return 0;
}