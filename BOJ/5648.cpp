#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	//�������� �ϱ� ���� ���ڿ��� �޴´�.
	string s;
	int n;
	cin >> n;
	vector<long long> num;
	for (int i = 0; i < n; i++) {
		cin >> s;

		//����
		reverse(s.begin(), s.end());

		//stoll : string -> long long
		num.push_back(stoll(s));
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < n; i++) {
		cout << num[i] << '\n';
	}

	return 0;
}