#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int stu;
	int n;
	int height;
	int tmp, res;
	vector<int> v;
	cin >> stu >> n;

	//�л��� ������ Ű�� �Է¹���
	for (int i = 0; i < stu; i++) {
		cin >> height;
		if (i != 0) {
			res = height - tmp;
			v.push_back(res);
			tmp = height;
		}
		else tmp = height;
	}
	//�л��� Ű ���̸� ����
	sort(v.begin(), v.end());
	int sum = 0;

	//������ ���� ������ ������ �ȴ�.
	for (int i = 0; i < stu - n; i++) {
		sum += v[i];
	}

	cout << sum << '\n';

	return 0;
}