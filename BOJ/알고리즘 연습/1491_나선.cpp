#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int n, m;
	int a, b;
	cin >> n >> m;
	//while�� �Ͽ� ��Ģ�� ���� �����̰��Ͽ�����
	//�ð��ʰ��� ����
	//��Ģ�� ã�� �˰����� �����Ͽ���.
	if (n > m) {
		if (m % 2 == 1) {
			b = m / 2 + 1;
			a = n - m / 2;
		}
		else {
			b = m / 2 + 1;
			a = m / 2;
		}
	}
	else if (n < m) {
		if (n % 2 == 1) {
			a = n / 2 + 1;
			b = m - n / 2;
		}
		else {
			a = n / 2;
			b = 1 + n / 2;
		}
	}
	else {
		if (n % 2 == 0) {
			a = n / 2;
			b = n / 2 + 1;
		}
		else {
			a = n / 2 + 1;
			b = a;
		}
	}
	cout << a - 1 << ' ' << b - 1;

	return 0;
}