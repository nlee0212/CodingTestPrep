#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 500000;
const int MAXM = 100000;

//extern int FindString(int N, char* A, int M, char* B);

char A[MAXN + 5];
char B[MAXM + 5];

vector<int> getPi(char* B, int M) {
	int j = 0;
	vector<int> pi(M, 0);
	for (int i = 1; i < M; i++) {
		while (j > 0 && B[i] != B[j]) j = pi[j - 1];
		if (B[i] == B[j]) pi[i] = ++j;
	}
	return pi;
}

int FindString(int N, char* A, int M, char* B) {
	int answer = 0;

	vector<int> stack;
	vector<int> pi = getPi(B, M);
	int i = 0, j = 0;

	while (i < N) {
		if (A[i] == B[j]) {
			i++; j++;
			if (j == M) {
				answer++;
				j = pi[j - 1];
			}
		}
		else {
			if (j == 0) i++;
			else j = pi[j - 1];
		}
	}

	return answer;
}

int main(void) {
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);

	int TestCase; for (scanf("%d", &TestCase); TestCase--;) {

		scanf("%s", A); // A: 책의 내용
		scanf("%s", B); // B: 단어

		//N = Length of A, M = Length of B
		int N = 0, M = 0;
		for (; A[N]; N++);
		for (; B[M]; M++);

		int answer = FindString(N, A, M, B);

		static int tc = 0;
		printf("#%d %d\n", ++tc, answer);
	}
	return 0;
}

