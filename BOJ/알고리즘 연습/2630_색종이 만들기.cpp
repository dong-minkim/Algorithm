#include<iostream>

using namespace std;

int arr[129][129];
int b_cnt = 0;
int w_cnt = 0;

void count(int x, int y, int length) {
	int cnt = 0;
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			if (arr[i][j]) {
				cnt++;
			}
		}
	}
	//ĭ�� ���� 0 �϶�
	if (!cnt) w_cnt++;
	//ĭ�� ���� 1 �϶�
	else if (cnt == length * length) b_cnt++;
	//4������� ������ ���� ��ͷ� ������.
	else {
		count(x, y + length / 2, length / 2);
		count(x + length / 2, y, length / 2);
		count(x, y, length / 2);
		count(x + length / 2, y + length / 2, length / 2);
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	count(0, 0, N);

	cout << w_cnt << '\n';
	cout << b_cnt;

	return 0;
}