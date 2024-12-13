#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;

	int N = str.size();

	for (int i = 0; i < N - 1; i++) {
		char max_idx = i;
		for (int j = i + 1; j < N ; j++) {
			if (str[max_idx] < str[j]) {
				max_idx = j;
			}
		}
		if (i != max_idx) swap(str[i], str[max_idx]);
	}

	cout << str << endl;

	return 0;
}