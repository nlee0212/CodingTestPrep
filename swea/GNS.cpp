#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  // C++의 cin, cout의 속도를 빠르게 함
    cin.tie(NULL);  // cin과 cout의 묶음을 풀어서 빠르게 함
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);  // 표준 입력을 파일로 변경

    int T;  // 테스트 케이스의 개수
    cin >> T;
    cin.ignore();  // 줄바꿈 문자 처리

    // 단어와 숫자의 매핑
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

    // 각 테스트 케이스 처리
    for (int t = 1; t <= T; t++) {
        
        char hash;
        int caseNumber, length;
        cin >> hash >> caseNumber >> length;

        // 두 번째 줄: 테스트 케이스의 단어들

        vector<int> words;

        string word;
        for (int i=0;i<length;i++) {
			cin >> word;
            words.push_back(wordToNumber[word]);
        }

        // 단어들을 숫자에 맞게 정렬
		sort(words.begin(), words.end());

        // 결과 출력
        cout << "#" << caseNumber << endl;
        for (const int w : words) {
            cout << NumberToword[w] << " ";
        }
        cout << endl;
    }

    return 0;
}
