#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 회문 검사 함수: 주어진 문자열이 회문이면 true, 아니면 false
bool isPalindrome(const string& str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);  // C++의 cin, cout의 속도를 빠르게 함
    cin.tie(NULL);  // cin과 cout의 묶음을 풀어서 빠르게 함
    cout.tie(NULL);

    int T=10;  // 테스트 케이스 개수
    freopen("input.txt", "r", stdin);  // 표준 입력을 파일로 변경

    for (int t = 1; t <= T; t++) {
        int L;  // 찾을 회문의 길이
        cin >> L;

        vector<string> grid(8);  // 8x8 크기의 글자판
        for (int i = 0; i < 8; i++) {
            cin >> grid[i];
        }

        int palindromeCount = 0;

        // 가로 방향 회문 검사
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= 8 - L; j++) {
                string horizontal = grid[i].substr(j, L);
                if (isPalindrome(horizontal)) {
                    palindromeCount++;
                }
            }
        }

        // 세로 방향 회문 검사
        for (int j = 0; j < 8; j++) {
            for (int i = 0; i <= 8 - L; i++) {
                string vertical = "";
                for (int k = 0; k < L; k++) {
                    vertical += grid[i + k][j];
                }
                if (isPalindrome(vertical)) {
                    palindromeCount++;
                }
            }
        }

        // 결과 출력
        cout << "#" << t << " " << palindromeCount << endl;
    }

    return 0;
}
