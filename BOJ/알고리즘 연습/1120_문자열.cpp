#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;


int main()
{
	string a;
	string b;
	int min = 100;
	int cnt;
	cin >> a >> b;
	//���ڿ� b�� ������ �ΰ� a�� iũ�� ��ŭ �ű�� ��
	for (int i = 0; i <= b.size() - a.size(); i++) {
		cnt = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[j + i]) cnt++;
		}

		if (min >= cnt) min = cnt;
	}
	cout << min << '\n';

	return 0;
}