#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

// 두 부분을 병합하고, 병합하면서 Inversion 개수를 세는 함수
long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // 왼쪽 부분의 시작 인덱스
    int j = mid + 1; // 오른쪽 부분의 시작 인덱스
    int k = left;    // 병합 후 배열을 채울 인덱스
    long long inv_count = 0;

    // 두 부분 배열을 병합
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // 왼쪽 배열의 원소들 모두 Inversion을 만든다.
        }
    }

    // 남은 원소들 처리
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 병합된 배열을 원본 배열에 복사
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// 병합 정렬을 통해 Inversion을 세는 함수
long long merge_and_count(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += merge_and_count(arr, temp, left, mid);  // 왼쪽 부분에 대해 재귀
        inv_count += merge_and_count(arr, temp, mid + 1, right);  // 오른쪽 부분에 대해 재귀

        inv_count += merge(arr, temp, left, mid, right);  // 병합과 동시에 Inversion 개수 세기
    }
    return inv_count;
}



int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);

    int T;  // 테스트 케이스 수
    cin >> T;

    for (int t = 1; t <= T;t++) {
        int N;  // 수열의 길이
        cin >> N;

        vector<int> arr(N);
        vector<int> temp(N);  // 병합 정렬에 사용할 임시 배열

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        // 병합 정렬을 이용해 Inversion 개수 계산
        long long inv_count = merge_and_count(arr, temp, 0, N - 1);

        cout << "#" << t << " " << inv_count << "\n";
    }

    return 0;
}