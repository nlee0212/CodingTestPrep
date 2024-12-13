#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

long long point[100005][2];
int N;
vector<int> sortList;

long long Cross(int x1, int y1, int x2, int y2) {
	return (long long)x1 * y2 - (long long)x2 * y1;
}
long long CCW(int p1, int p2, int p3) {
	int x1 = point[p2][0] - point[p1][0];
	int x2 = point[p3][0] - point[p1][0];
	int y1 = point[p2][1] - point[p1][1];
	int y2 = point[p3][1] - point[p1][1];
	return Cross(x1, y1, x2, y2);
}

long long dist(int x1, int y1, int x2, int y2) {
	long long x = (long long)x2 - x1;
	long long y = (long long)y2 - y1;
	long long d = sqrt(x * x + y * y);
	return d;
}
bool compare(int a, int b) {
	int x1 = point[a][0];
	int y1 = point[a][1];
	int x2 = point[b][0];
	int y2 = point[b][1];

	if (y1 == y2) {
		return x1 < x2;
	}
	else {
		return y1 < y2;
	}
}
bool compare2(int a, int b) {
	int x0 = point[sortList[0]][0];
	int y0 = point[sortList[0]][1];
	int x1 = point[a][0];
	int y1 = point[a][1];
	int x2 = point[b][0];
	int y2 = point[b][1];

	long long ccw = CCW(sortList[0], a, b);
	if (ccw == 0) {
		return dist(x0, y0, x1, y1) < dist(x0, y0, x2, y2);
	}
	return ccw > 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cout << "#" << tc << " ";
		sortList.clear();
		
		
		cin >> N;

		int minY = 1000000;
		int minX = 1000000;
		int minYIndex = 0;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			point[i][0] = x;
			point[i][1] = y;
			if (y <= minY && x <= minX) {
				minY = y;
				minX = x;
				minYIndex = i;
			}
		}
		sortList.push_back(minYIndex);
		for (int i = 0; i < N; i++) {
			if (i == minYIndex)
				continue;
			sortList.push_back(i);
		}
		sort(sortList.begin(), sortList.end(), compare);
		sort(sortList.begin() + 1, sortList.end(), compare2);
		for (int index = 0; index < sortList.size(); index++) {
			int prev = index - 1 < 0 ? sortList.size() - 1 : index - 1;
			int next = index + 1 > sortList.size() - 1 ? 0 : index + 1;
			long long ccw = CCW(sortList[prev], sortList[index], sortList[next]);

			if (ccw <= 0) {
				sortList.erase(sortList.begin() + index);
				index -= 2;
			}
		}
		cout << sortList.size() << endl;
	}
}