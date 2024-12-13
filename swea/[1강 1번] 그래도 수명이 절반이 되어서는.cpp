#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

// maxWear ���Ϸ� ����� ��ġ�� �� �ִ��� Ȯ���ϴ� �Լ�
bool canDistribute(const vector<int>& W, const vector<int>& S, int maxWear, int N, int K) {
    int pivot = -1;
    for (int k = 0; k < K; k++) {
        for (int s = 0; s < S[k]; s++) {
            pivot++;
            if (pivot == N) return false;
            if (W[pivot] > maxWear) {
                k--;
                break;
            }
        }
    }
    return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for(int t=1;t<T+1;t++) {
        int N, K;
        cin >> N >> K;

        vector<int> W(N);
        for (int i = 0; i < N; i++) {
            cin >> W[i];
        }

        vector<int> S(K);
        for (int i = 0; i < K; i++) {
            cin >> S[i];
        }

        // ���� Ž���� ���� ����
        int left = 1, right = 200000, result = right;

        // ���� Ž���� ���� �ּ��� �ִ� ���� ������ ã��
        while (left < right) {
            int mid = (left + right) / 2;

            if (canDistribute(W, S, mid, N, K)) {
                result = mid;  // �����ϸ� result ����
                right = mid;  // �� ���� ������ Ž��
            }
            else {
                left = mid + 1;  // �Ұ����ϸ� �� ū ������ Ž��
            }
        }

        cout << "#" << t << " " << result << endl;
    }

    return 0;
}
