#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	ios::sync_with_stdio(false);  // C++�� cin, cout�� �ӵ��� ������ ��
	cin.tie(NULL);  // cin�� cout�� ������ Ǯ� ������ ��
    cout.tie(NULL);

    int T = 10;  // �׽�Ʈ ���̽��� ����

	freopen("input.txt", "r", stdin);  // ǥ�� �Է��� ���Ϸ� ����

    // �� �׽�Ʈ ���̽��� ó��
    for (int t = 1; t <= T; ++t) {
		cin >> t;  // �׽�Ʈ ���̽� ��ȣ
        string target, sentence;
        cin >> target;   // ã�� ���ڿ�
        cin.ignore();     // ���� �Է¿��� ���� ���๮�ڸ� ����
        getline(cin, sentence);  // �˻��� ����

        int count = 0;  // ã�� Ƚ��
        size_t pos = 0; // ���ڿ��� Ž���� ��ġ

		while (pos < sentence.length()-target.length()) {
			pos = sentence.find(target, pos);  // ���ڿ����� target�� ã��
			if (pos == string::npos) break;  // ã�� ���ϸ� ����
			++count;  // ã������ count ����
			pos += target.length();  // ���� Ž�� ��ġ�� target�� ���̸�ŭ �̵�
		}

        // ��� ���
        cout << "#" << t << " " << count << endl;
    }

    return 0;
}
