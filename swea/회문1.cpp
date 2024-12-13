#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ȸ�� �˻� �Լ�: �־��� ���ڿ��� ȸ���̸� true, �ƴϸ� false
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
    ios::sync_with_stdio(false);  // C++�� cin, cout�� �ӵ��� ������ ��
    cin.tie(NULL);  // cin�� cout�� ������ Ǯ� ������ ��
    cout.tie(NULL);

    int T=10;  // �׽�Ʈ ���̽� ����
    freopen("input.txt", "r", stdin);  // ǥ�� �Է��� ���Ϸ� ����

    for (int t = 1; t <= T; t++) {
        int L;  // ã�� ȸ���� ����
        cin >> L;

        vector<string> grid(8);  // 8x8 ũ���� ������
        for (int i = 0; i < 8; i++) {
            cin >> grid[i];
        }

        int palindromeCount = 0;

        // ���� ���� ȸ�� �˻�
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= 8 - L; j++) {
                string horizontal = grid[i].substr(j, L);
                if (isPalindrome(horizontal)) {
                    palindromeCount++;
                }
            }
        }

        // ���� ���� ȸ�� �˻�
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

        // ��� ���
        cout << "#" << t << " " << palindromeCount << endl;
    }

    return 0;
}
