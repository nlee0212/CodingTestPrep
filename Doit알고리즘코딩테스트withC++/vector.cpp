#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

int main() {
	A.push_back(1);
	A.push_back(4);
	A.push_back(9);
	A.push_back(13);
	A.push_back(27);
	A.push_back(17);
	A.insert(A.begin(), 7);
	A.insert(A.begin() + 2, 10);

	A[4] = -5;

	A.pop_back();
	A.erase(A.begin() + 3);
	//A.clear();

	cout << A.size() << endl;
	cout << A.front() << endl;
	cout << A.back() << endl;
	cout << A[3] << endl;
	cout << A.at(5) << endl;

	return 0;
}