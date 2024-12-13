/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

// 소수 여부를 미리 계산 (0부터 18까지)
bool is_prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

// 이항계수 계산
long long binomial_coefficient(int n, int k) {
	if (k > n) return 0;
	long long result = 1;
	for (int i = 1; i <= k; ++i) {
		result *= (n - (k - i));
		result /= i;
	}
	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input2.txt", "r", stdin);
	cin >> T;

	vector<bool> prime(19, false);
	for (int i = 0; i <= 18; ++i) {
		prime[i] = is_prime(i);
	}
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int skillOfMasterA, skillOfMasterB;
		cin >> skillOfMasterA >> skillOfMasterB;

		// 각 장인의 5분 간 완제품 만들 확률 (백분율 -> 확률로 변환)
		double pA = skillOfMasterA / 100.0;
		double pB = skillOfMasterB / 100.0;

		// 0~18개의 완제품에 대한 확률 계산
		double probA_witho_prime = 0.0;
		double probB_witho_prime = 0.0;

		for (int k = 0; k <= 18; ++k) {
			if (!prime[k]) {
				long long comb = binomial_coefficient(18, k);
				double probA_k = comb * pow(pA, k) * pow(1 - pA, 18 - k);
				double probB_k = comb * pow(pB, k) * pow(1 - pB, 18 - k);

				probA_witho_prime += probA_k;
				probB_witho_prime += probB_k;

			}

			// 최소 한 명이라도 소수일 확률 = 1 - 둘 다 소수가 아닐 확률
		}
		// 결과 출력
		cout << "#" << test_case << " " << fixed << setprecision(6) << 1- probA_witho_prime* probB_witho_prime << endl;
	}

	return 0;
		


}