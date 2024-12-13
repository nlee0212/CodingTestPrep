#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  // C++�� cin, cout�� �ӵ��� ������ ��
    cin.tie(NULL);  // cin�� cout�� ������ Ǯ� ������ ��
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);  // ǥ�� �Է��� ���Ϸ� ����

    int T;  // �׽�Ʈ ���̽��� ����
    cin >> T;
    cin.ignore();  // �ٹٲ� ���� ó��

    // �ܾ�� ������ ����
    map<string, int> wordToNumber = {
        {"ZRO", 0}, {"ONE", 1}, {"TWO", 2}, {"THR", 3},
        {"FOR", 4}, {"FIV", 5}, {"SIX", 6}, {"SVN", 7},
        {"EGT", 8}, {"NIN", 9}
    };

    map<int, string> NumberToword = {
        {0, "ZRO"}, {1, "ONE"}, {2, "TWO"}, {3, "THR"},
        {4, "FOR"}, {5, "FIV"}, {6, "SIX"}, {7, "SVN"},
        {8, "EGT"}, {9, "NIN"}
    };

    // �� �׽�Ʈ ���̽� ó��
    for (int t = 1; t <= T; t++) {
        
        char hash;
        int caseNumber, length;
        cin >> hash >> caseNumber >> length;

        // �� ��° ��: �׽�Ʈ ���̽��� �ܾ��

        vector<int> words;

        string word;
        for (int i=0;i<length;i++) {
			cin >> word;
            words.push_back(wordToNumber[word]);
        }

        // �ܾ���� ���ڿ� �°� ����
		sort(words.begin(), words.end());

        // ��� ���
        cout << "#" << caseNumber << endl;
        for (const int w : words) {
            cout << NumberToword[w] << " ";
        }
        cout << endl;
    }

    return 0;
}
