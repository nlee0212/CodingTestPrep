#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstdio>
#define ll long long

using namespace std;

string reverse(string s, int start, int end) {
	int len = end - start + 1;
	for (int i = 0; i < len / 2; i++) {
		char r_start = (s[start + i] == '(') ? ')' : '(';
		char r_end = (s[end - i] == '(') ? ')' : '(';
		s[start + i] = r_end;
		s[end - i] = r_start;
	}

	if (len % 2 > 0) {
		s[start + len / 2] = (s[start + len / 2] == '(') ? ')' : '(';
	}

	return s;
}

int find_last_half(vector<int> acc_sum, int find_num) {
	int idx = -1;
	for (int i = acc_sum.size() - 1; i >= 0; i--) {
		if (acc_sum[i] == find_num) {
			idx = i;
			break;
		}
	}
	return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

	for (int t = 1; t < T + 1; t++) {
		cout << "#" << t << " ";

		int L;
		cin >> L;
		string s;
		cin >> s;
		//cout << s << endl;

		if (L % 2 > 0) {
			cout << "-1" << endl;
			continue;
		}

		
		vector<pair<int, int>> result;

		while (true) {
			int acc_sum = 0;
			int min_value = 0;
			int min_idx = -1;
			vector<int> acc_sum_arr;

			for (int i = 0; i < L; i++) {
				char c = s[i];
				if (c == '(') acc_sum++;
				else acc_sum--;

				if (acc_sum < min_value) {
					min_value = acc_sum;
					min_idx = i;
				}

				acc_sum_arr.push_back(acc_sum);
			}

			if (min_idx > -1) {
				s = reverse(s, 0, min_idx);
				result.push_back({ 0, min_idx });
			}

			else {
				if (acc_sum_arr.back() == 0) break;
			}

			acc_sum_arr.clear();
			acc_sum = 0;

			for (char c : s) {
				if (c == '(') acc_sum++;
				else acc_sum--;

				acc_sum_arr.push_back(acc_sum);
			}

			if (acc_sum_arr.back() != 0) {
				int start = find_last_half(acc_sum_arr, acc_sum_arr.back() / 2);
				s = reverse(s, start + 1, L - 1);
				result.push_back({ start + 1, L - 1 });
			}
		}

		cout << result.size() << endl;
		for (auto r : result) {
			cout << r.first << " " << r.second << endl;
		}
	}
	return 0;
}