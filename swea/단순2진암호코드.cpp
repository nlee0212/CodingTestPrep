#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <numeric>

using namespace std;

// 숫자에 해당하는 7비트 비트열 정의
string codes[10] = {
    "0001101", "0011001", "0010011", "0111101", "0100011",
    "0110001", "0101111", "0111011", "0110111", "0001011"
};

// 7비트 암호를 숫자로 변환하는 함수
int decode(const string& code) {
    for (int i = 0; i < 10; ++i) {
        if (codes[i] == code) {
            return i;
        }
    }
    return -1;  // 일치하지 않는 경우
}

int main() {
    int T; // 테스트 케이스의 수
    freopen("input3.txt", "r", stdin);
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int N, M;
        cin >> N >> M;

        vector<string> grid(N);
        for (int i = 0; i < N; ++i) {
            cin >> grid[i];
        }

        // 암호 코드 탐지
        vector<int> code(8);
        bool error = false;

        // 7비트씩 끊어서 암호코드를 추출
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



        // 코드가 8자리 이상일 때만 검증

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