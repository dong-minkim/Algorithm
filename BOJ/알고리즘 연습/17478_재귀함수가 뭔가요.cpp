#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

void func(int m, int n) {
	if (n == 0) {
		for (int i = m - n; i > 0; i--) cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = m - n; i > 0; i--) cout << "____";
		cout << "��� �亯�Ͽ���.\n";
		return;
	}
	for (int i = m - n; i > 0; i--) cout << "____";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for (int i = m - n; i > 0; i--) cout << "____";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for (int i = m - n; i > 0; i--) cout << "____";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	for (int i = m - n + 1; i > 0; i--) cout << "____";
	cout << "\"����Լ��� ������?\"\n";
	func(m, n - 1);
	for (int i = m - n; i > 0; i--) cout << "____";
	cout << "��� �亯�Ͽ���.\n";
}

int main()
{
	int n;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	cout << "\"����Լ��� ������?\"\n";
	func(n, n);
	return 0;
}