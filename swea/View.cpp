#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int T;
    freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int N;  // ������ ����
        cin >> N;

        vector<int> heights(N);  // �� ������ ���̸� ������ �迭
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }

        int count = 0;  // �������� Ȯ���� ������ ��

        // 2��°���� N-3��°���� �˻� (�� �� 2ĭ�� �׻� ����)
        for (int i = 2; i < N - 2; ++i) {
            bool left_clear = true, right_clear = true;

            // ���� 2ĭ �̻� ���� ���� Ȯ�� (������ �ִ� ������ i���� ������)
            if (heights[i] <= heights[i - 1] || heights[i] <= heights[i - 2]) {
                left_clear = false;
            }

            // ������ 2ĭ �̻� ���� ���� Ȯ�� (������ �ִ� ������ i���� ������)
            if (heights[i] <= heights[i + 1] || heights[i] <= heights[i + 2]) {
                right_clear = false;
            }

            // ���ʰ� ������ ��� ���� 2ĭ �̻��̸� ������ Ȯ��
            if (left_clear && right_clear) {
                int max_near = max({ heights[i - 1], heights[i - 2], heights[i + 1], heights[i + 2] });

                count+=heights[i]-max_near;
            }
        }

        // ��� ���
        cout << "#" << test_case << " " << count << endl;
    }

    return 0;
}
