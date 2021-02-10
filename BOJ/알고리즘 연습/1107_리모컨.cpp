#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
int arr[10] = { 0, };

//���峭 Ű�� ������ 1 ��ȯ
int check(int n) {
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++) {
		if (arr[s[i] - 48]) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		//���峭 ��ư
		arr[n] = 1;
	}

	//ä�� 100���� �����Ͽ� ����Ű�� ������ ��
	int min_ = abs(N - 100);
	for (int i = 0; i <= 1000000; i++) {
		//���峭 ��ư�� ���� ��
		if (check(i)) {
			int tmp = abs(N - i) + to_string(i).length();
			min_ = min(min_, tmp);
		}
	}
	cout << min_ << '\n';

	return 0;
}