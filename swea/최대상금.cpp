#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string number;
int change;
int maxValue = 0;

void getMaxValue(int idx, int cnt) {
	if (cnt == change) {
		maxValue = max(maxValue, stoi(number));
		return;
	}

	for (int i = idx; i < number.length() - 1; i++) {
		if (to_string(maxValue)[0] > number[0]) {
			break;
		}
		for (int j = i + 1; j < number.length(); j++) {
			if ((number[i] <= number[j]) || (i == number.length() - 2 && j == number.length() - 1)) {
				swap(number[i], number[j]);
				getMaxValue(i, cnt + 1);
				swap(number[i], number[j]);
			}
		}
	}
}

int main() {
	int T;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> number >> change;

		maxValue = 0;
		getMaxValue(0, 0);

		cout << "#" << t << ' ' << maxValue << '\n';
	}
}