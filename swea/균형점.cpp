#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

double coord[10] = { 0, };
double mass[10] = { 0, };
int N;

void binary_search(double left, double right) {
	double mid;
	int count = 100;

	while (count > 0) {
		double left_force = 0;
		double right_force = 0;
		mid = (left + right) / 2.0;


		for (int i = 0; i < N; i++) {
			double dist = mid - coord[i];
			if (dist > 0) {
				left_force += mass[i] / (dist * dist);
			}
			else {
				right_force += mass[i] / (dist * dist);
			}
		}
		if (left_force > right_force) {
			left = mid;
		}
		else if (left_force < right_force) {
			right = mid;
		}

		if (abs(left_force - right_force) < 1e-13) {
			break;
		}
		count--;
	}

	printf("%.10f ", mid);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> coord[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> mass[i];
		}
		cout << "#" << test_case << " ";

		for (int i = 0; i < N - 1; i++) {
			binary_search(coord[i], coord[i+1]);
		}
		
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}