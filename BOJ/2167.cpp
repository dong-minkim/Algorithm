#include<iostream>

using namespace std;

int dp[301][301] = { 0, };
int main()
{
	int n, m, k;
	int i, j, x, y;
	int num;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> num;
			//dp[i][j] = (1,1) ���� (i,j)������ ��
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + num - dp[i - 1][j - 1];
		}
	}
	cin >> k;
	while (k--) {
		cin >> i >> j >> x >> y;
		
		//(x,y)�� - { (i-1,y)�� + (x,j-1)�� } + (i-1,j-1)��
		int result = dp[x][y] - dp[i-1][y] - dp[x][j-1] + dp[i-1][j-1];

		cout << result << '\n';
	}

	return 0;
}