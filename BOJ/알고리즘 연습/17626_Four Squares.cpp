#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	int min_;
	cin >> n;

	vector<int> v(n + 1, 0);

	v[1] = 1;

	//v�� n���� �ּ��� ���� ä�� �ִ´�(dp)
	for (int i = 2; i <= n; i++) {
		min_ = 5;
		//������ �������� ���� �ּ� ������ ���Ѵ�. 
		for (int j = 1; j * j <= i; j++) {
			int temp = i - j * j;
			min_ = min(min_, v[temp]);
		}
		v[i] = min_ + 1;
	}
	cout << v[n] << '\n';

	return 0;
}