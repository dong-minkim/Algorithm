#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
	}

	//next)permutation : ���� ������ �����ϸ� 1�� ��ȯ�Ѵ�.
	do {
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}