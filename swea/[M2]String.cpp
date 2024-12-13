#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	ios::sync_with_stdio(false);  // C++의 cin, cout의 속도를 빠르게 함
	cin.tie(NULL);  // cin과 cout의 묶음을 풀어서 빠르게 함
    cout.tie(NULL);

    int T = 10;  // 테스트 케이스의 개수

	freopen("input.txt", "r", stdin);  // 표준 입력을 파일로 변경

    // 각 테스트 케이스를 처리
    for (int t = 1; t <= T; ++t) {
		cin >> t;  // 테스트 케이스 번호
        string target, sentence;
        cin >> target;   // 찾을 문자열
        cin.ignore();     // 이전 입력에서 남은 개행문자를 제거
        getline(cin, sentence);  // 검색할 문장

        int count = 0;  // 찾은 횟수
        size_t pos = 0; // 문자열을 탐색할 위치

		while (pos < sentence.length()-target.length()) {
			pos = sentence.find(target, pos);  // 문자열에서 target을 찾음
			if (pos == string::npos) break;  // 찾지 못하면 종료
			++count;  // 찾았으면 count 증가
			pos += target.length();  // 다음 탐색 위치를 target의 길이만큼 이동
		}

        // 결과 출력
        cout << "#" << t << " " << count << endl;
    }

    return 0;
}
