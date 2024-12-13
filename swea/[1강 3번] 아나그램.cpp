#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 100000;

//extern int FindAnagram(int Len1, char* S1, int Len2, char* S2);

char S1[MAXN + 5];
char S2[MAXN + 5];

#include <vector>

int FindAnagram(int Len1, char* S1, int Len2, char* S2) {
	int answer = 0;

	vector<int> dict(26, 0);

	for (int i = 0; i < Len1;i++) {
		dict[S1[i] - 'a']++;
	}

	vector<int> temp(26,0);

	for (int j = 0; j < Len1; j++) {
		temp[S2[j] - 'a']++;
	}

	for (int i = 0; i < Len2-Len1+1; i++) {

		for (int j = 0; j < 26; j++) {
			if (dict[j] != temp[j]) {
				break;
			}
			if (j == 25) {
				answer++;
			}
		}

		temp[S2[i] - 'a']--;
		if (i+Len1<Len2) temp[S2[i + Len1]-'a']++;
	}

	return answer;
}

int main(void) {
	setbuf(stdout, NULL);

	freopen("input.txt", "r", stdin);

	int TestCase; for (scanf("%d", &TestCase); TestCase--;) {

		scanf("%s", S1);
		scanf("%s", S2);

		//L1 = Length of S1, L2 = Length of S2
		int L1 = 0, L2 = 0;
		for (; S1[L1]; L1++);
		for (; S2[L2]; L2++);

		int answer = FindAnagram(L1, S1, L2, S2);

		static int tc = 0;
		printf("#%d %d\n", ++tc, answer);
	}
	return 0;
}