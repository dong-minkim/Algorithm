#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int M, N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int arr[101][101] = { 0, };
int visited[101][101] = { 0, };

void bfs() {
	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	visited[0][0] = 0; // ó�� ������ 0���� �������Ѵ�.

	while (!q.empty()) {
		int x = q.front().second;//M
		int y = q.front().first; //N
		q.pop();
		

		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];
			if (0 <= X && X < M && 0 <= Y && Y < N) {
				if (arr[Y][X] == 1) { //���� ����������
					if (visited[Y][X] > visited[y][x] + 1) {
						visited[Y][X] = visited[y][x] + 1;
						q.push(make_pair(Y, X));
					}
				}
				else {                //��� �϶�
					if (visited[Y][X] > visited[y][x]) {
						visited[Y][X] = visited[y][x];
						q.push(make_pair(Y, X));
					}
				}
			}
		}
	}
}
int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j] - '0';
			visited[i][j] = 10000000;
		}
	}
	bfs();
	cout << visited[N-1][M-1];
	return 0;
}