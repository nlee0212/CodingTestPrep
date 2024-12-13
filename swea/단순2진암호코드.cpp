#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <numeric>

using namespace std;

// ���ڿ� �ش��ϴ� 7��Ʈ ��Ʈ�� ����
string codes[10] = {
    "0001101", "0011001", "0010011", "0111101", "0100011",
    "0110001", "0101111", "0111011", "0110111", "0001011"
};

// 7��Ʈ ��ȣ�� ���ڷ� ��ȯ�ϴ� �Լ�
int decode(const string& code) {
    for (int i = 0; i < 10; ++i) {
        if (codes[i] == code) {
            return i;
        }
    }
    return -1;  // ��ġ���� �ʴ� ���
}

int main() {
    int T; // �׽�Ʈ ���̽��� ��
    freopen("input3.txt", "r", stdin);
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int N, M;
        cin >> N >> M;

        vector<string> grid(N);
        for (int i = 0; i < N; ++i) {
            cin >> grid[i];
        }

        // ��ȣ �ڵ� Ž��
        vector<int> code(8);
        bool error = false;

        // 7��Ʈ�� ��� ��ȣ�ڵ带 ����
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= M - 7; ++j) {
                if (grid[i][j] == '0' && j+55<M && grid[i][j + 55] == '1') {
                    string segment = grid[i].substr(j, 7);
                    int digit = decode(segment);
                    if (digit != -1) {
                        error = false;
                        code[0] = digit;
                        for (int k = 1;k < 8;k++) {
                            digit = decode(grid[i].substr(j + 7 * k, 7));
                            code[k] = digit;
                            if (digit == -1) {
                                error = true;
                                break;
                            }

                        }

                        if (error) continue;
                        else break;

                    }
                    else {

                        continue;
                    }
                }
            }
        }



        // �ڵ尡 8�ڸ� �̻��� ���� ����

        int odd_sum = 0, even_sum = 0;
        for (int i = 0; i < 8; ++i) {
            if (i % 2 == 0) {
                odd_sum += code[i];
            }
            else {
                even_sum += code[i];
            }
        }



        int total = (odd_sum * 3) + even_sum;
        if (total % 10 == 0) {
            int sum = accumulate(code.begin(), code.end(), 0);
            cout << "#" << test_case << " " << sum << endl;
        }
        else {
            cout << "#" << test_case << " 0" << endl;
        }

    }
    return 0;
}