#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[101][101] = { 0, };
int main()
{
	int T;
	cin >> T;
	int x, y, w, h;
	for (int i = 0; i < T; i++) {
		cin >> x >> y >> w >> h;
		for (int j = 0; j < w; j++) {
			for (int k = 0; k < h; k++) {
				//�ش��ϴ� ������ N��° �������� ǥ��
				arr[x + j][y + k] = i + 1;
			}
		}
	}
	int cnt = 1;
	int ans;
	while (cnt <= T) {
		ans = 0;
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				//cnt��° ������ ��� ����(ans)�� ������Ŵ
				if (arr[i][j] == cnt) ans++;
			}
		}
		cout << ans << '\n';
		cnt++;
	}
	return 0;
}