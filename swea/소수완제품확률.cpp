/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

// �Ҽ� ���θ� �̸� ��� (0���� 18����)
bool is_prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

// ���װ�� ���
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
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input2.txt", "r", stdin);
	cin >> T;

	vector<bool> prime(19, false);
	for (int i = 0; i <= 18; ++i) {
		prime[i] = is_prime(i);
	}
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int skillOfMasterA, skillOfMasterB;
		cin >> skillOfMasterA >> skillOfMasterB;

		// �� ������ 5�� �� ����ǰ ���� Ȯ�� (����� -> Ȯ���� ��ȯ)
		double pA = skillOfMasterA / 100.0;
		double pB = skillOfMasterB / 100.0;

		// 0~18���� ����ǰ�� ���� Ȯ�� ���
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

			// �ּ� �� ���̶� �Ҽ��� Ȯ�� = 1 - �� �� �Ҽ��� �ƴ� Ȯ��
		}
		// ��� ���
		cout << "#" << test_case << " " << fixed << setprecision(6) << 1- probA_witho_prime* probB_witho_prime << endl;
	}

	return 0;
		


}