#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
int arr[9][9];

vector<pair<int, int>> v;
int check(int row, int col, int num);
void solution(int n);
int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			//������ ĭ�� ������� ��� v�� �ִ´�.
			if (arr[i][j] == 0) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	solution(0);

	return 0;
}
void solution(int n) {
	//����ִ� ĭ ��ŭ �� ������ �� ��� �� ����
	if (n == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		//����
		exit(0);
	}

	int row = v[n].first;
	int col = v[n].second;
	for (int i = 1; i <= 9; i++) {
		//check�� ���� �����ϰ� ���� �� ĭ���� �Ѿ��.
		if (check(row, col, i) == 1) {
			arr[row][col] = i;
			solution(n + 1);
		}
	}
	arr[row][col] = 0;
}
int check(int row, int col, int num) {
	//������ ��Ģ1: �ڱ⸦ ������ �� or ���� ���� ���ڰ� ������ �ȵȴ�.
	for (int i = 0; i < 9; i++) {
		if (num == arr[row][i] || num == arr[i][col]) return 0;
	}
	//������ ��Ģ2:  3x3ĭ�ȿ� ���� ���ڰ� ������ �ȵȴ�.
	int x = (row / 3) * 3;
	int y = (col / 3) * 3;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (arr[i][j] == num) return 0;
		}
	}

	//�� ��Ģ�� ���� ����ϸ� ���ڸ� ������ �� �����Ƿ� 1 ��ȯ!!
	return 1;
}