#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

// �� �κ��� �����ϰ�, �����ϸ鼭 Inversion ������ ���� �Լ�
long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // ���� �κ��� ���� �ε���
    int j = mid + 1; // ������ �κ��� ���� �ε���
    int k = left;    // ���� �� �迭�� ä�� �ε���
    long long inv_count = 0;

    // �� �κ� �迭�� ����
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // ���� �迭�� ���ҵ� ��� Inversion�� �����.
        }
    }

    // ���� ���ҵ� ó��
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // ���յ� �迭�� ���� �迭�� ����
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// ���� ������ ���� Inversion�� ���� �Լ�
long long merge_and_count(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += merge_and_count(arr, temp, left, mid);  // ���� �κп� ���� ���
        inv_count += merge_and_count(arr, temp, mid + 1, right);  // ������ �κп� ���� ���

        inv_count += merge(arr, temp, left, mid, right);  // ���հ� ���ÿ� Inversion ���� ����
    }
    return inv_count;
}



int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);

    int T;  // �׽�Ʈ ���̽� ��
    cin >> T;

    for (int t = 1; t <= T;t++) {
        int N;  // ������ ����
        cin >> N;

        vector<int> arr(N);
        vector<int> temp(N);  // ���� ���Ŀ� ����� �ӽ� �迭

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        // ���� ������ �̿��� Inversion ���� ���
        long long inv_count = merge_and_count(arr, temp, 0, N - 1);

        cout << "#" << t << " " << inv_count << "\n";
    }

    return 0;
}