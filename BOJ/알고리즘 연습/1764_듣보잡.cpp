#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int N, C;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<string> hear;
	vector<string> hearSee;
	string s;
	int cnt = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		hear.push_back(s);
	}
	//�赵 ���� ����� �����Ѵ�.
	sort(hear.begin(), hear.end());
	
	//�赵 ���� ����� �߿� ���� ���� ������� ã��
	//�赵 ���� ���� ����� push�Ѵ�.
	for (int i = 0; i < m; i++) {
		cin >> s;

		if (binary_search(hear.begin(), hear.end(), s)) {
			hearSee.push_back(s);
			cnt++;
		}
	}

	//���������� ���� ��
	sort(hearSee.begin(), hearSee.end());

	//���
	cout << cnt << '\n';
	for (int i = 0; i < hearSee.size(); i++) {
		cout << hearSee[i] << '\n';
	}
	return 0;
}