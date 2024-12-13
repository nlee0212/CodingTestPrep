#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 상수 정의
#define N 100

// 교착 상태를 셈
int countStuckState(vector<vector<int>>& table) {
    int stuckCount = 0;

    // 각 열에 대해서 독립적으로 교착 상태를 탐지
    for (int col = 0; col < N; col++) {
        stack<int> columnStack;

        for (int row = 0; row < N; row++) {
            int current = table[row][col];

            if (current == 1) {
                columnStack.push(1);  // 현재 자성체는 S극
            }

            else if (current == 2) {
                // 현재가 N극이면, 그 전의 모든 S극 자성체들은 교착 상태를 발생
                if (columnStack.empty()) continue; // 끝으로 밀려 떨어짐
				
                if (!columnStack.empty() && columnStack.top() == 1) {
                    stuckCount++;
                }
                columnStack.push(2);  // 현재 자성체는 N극
            }
        }

        
    }

    return stuckCount;
}

int main() {
    int T = 10;  // 테스트 케이스 수
	freopen("input.txt", "r", stdin);
    //cin >> T;

    for (int t = 1; t <= T; t++) {
        int size;  // 테이블 크기
        cin >> size;

        vector<vector<int>> table(N, vector<int>(N));

        // 테이블 입력 받기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> table[i][j];
            }
        }

        // 교착 상태의 개수 구하기
        int stuckStateCount = countStuckState(table);

        // 결과 출력
        cout << "#" << t << " " << stuckStateCount << endl;
    }

    return 0;
}
