#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

bool isPrime(int num) {
	if (num == 1) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> odds = { 1,3,5,7,9 };

	queue<int> q;
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(7);

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (num >= pow(10,N-1) && num < pow(10,N)) {
			cout << num << '\n';
			continue;
		}

		for (int i = 0; i < 5; i++) {
			int next = num * 10 + odds[i];
			if (isPrime(next)) {
				q.push(next);
			}
		}
	}

	return 0;
}