#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ��� ����
#define N 100

// ���� ���¸� ��
int countStuckState(vector<vector<int>>& table) {
    int stuckCount = 0;

    // �� ���� ���ؼ� ���������� ���� ���¸� Ž��
    for (int col = 0; col < N; col++) {
        stack<int> columnStack;

        for (int row = 0; row < N; row++) {
            int current = table[row][col];

            if (current == 1) {
                columnStack.push(1);  // ���� �ڼ�ü�� S��
            }

            else if (current == 2) {
                // ���簡 N���̸�, �� ���� ��� S�� �ڼ�ü���� ���� ���¸� �߻�
                if (columnStack.empty()) continue; // ������ �з� ������
				
                if (!columnStack.empty() && columnStack.top() == 1) {
                    stuckCount++;
                }
                columnStack.push(2);  // ���� �ڼ�ü�� N��
            }
        }

        
    }

    return stuckCount;
}

int main() {
    int T = 10;  // �׽�Ʈ ���̽� ��
	freopen("input.txt", "r", stdin);
    //cin >> T;

    for (int t = 1; t <= T; t++) {
        int size;  // ���̺� ũ��
        cin >> size;

        vector<vector<int>> table(N, vector<int>(N));

        // ���̺� �Է� �ޱ�
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> table[i][j];
            }
        }

        // ���� ������ ���� ���ϱ�
        int stuckStateCount = countStuckState(table);

        // ��� ���
        cout << "#" << t << " " << stuckStateCount << endl;
    }

    return 0;
}
