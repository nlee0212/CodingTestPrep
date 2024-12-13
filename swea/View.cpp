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
        int N;  // 빌딩의 개수
        cin >> N;

        vector<int> heights(N);  // 각 빌딩의 높이를 저장할 배열
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }

        int count = 0;  // 조망권이 확보된 세대의 수

        // 2번째부터 N-3번째까지 검사 (양 옆 2칸은 항상 공백)
        for (int i = 2; i < N - 2; ++i) {
            bool left_clear = true, right_clear = true;

            // 왼쪽 2칸 이상 공백 여부 확인 (좌측에 있는 빌딩이 i보다 낮은지)
            if (heights[i] <= heights[i - 1] || heights[i] <= heights[i - 2]) {
                left_clear = false;
            }

            // 오른쪽 2칸 이상 공백 여부 확인 (우측에 있는 빌딩이 i보다 낮은지)
            if (heights[i] <= heights[i + 1] || heights[i] <= heights[i + 2]) {
                right_clear = false;
            }

            // 왼쪽과 오른쪽 모두 공백 2칸 이상이면 조망권 확보
            if (left_clear && right_clear) {
                int max_near = max({ heights[i - 1], heights[i - 2], heights[i + 1], heights[i + 2] });

                count+=heights[i]-max_near;
            }
        }

        // 결과 출력
        cout << "#" << test_case << " " << count << endl;
    }

    return 0;
}
