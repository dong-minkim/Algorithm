#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int x;
	long long sum = 0;
	long long tmp;
	cin >> n;

	//1���� n-1 ������ ��
	tmp = (long long)n * ((long long)n - 1) / 2;
	
	//1���� n-1 ������ �� + �ߺ��� ����
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
	}

	//result: �ߺ��� ����
	int result = sum - tmp;

	cout << result << '\n';
	return 0;
}