#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int n, m;
int map[1001][1001]; // 0: �����ִ� ��   1: �������� ��
bool visited[1001][1001][2] = { false, }; //false : �湮���� �ʾҴ�.
int dist[1001][1001][2] = { 0, };

bool inside(int y, int x) {
	if (0 <= x && x <= m-1 && 0 <= y && y <= n-1) return true;
	else return false;
}

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs() {

	queue<pair<pair<int, int>, int>> q;

	q.push({{ 0, 0 }, 0});
	visited[0][0][0] = true; //�湮
	dist[0][0][0] = 1;
	
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if ((y == n - 1) && ( x == m - 1)) {
			return dist[y][x][block];
		}

		for (int i = 0; i < 4; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];

			if (inside(Y,X)) {

				//���� �湮���� �ʰ�, �� �� �ִ� ���� ��
				if (map[Y][X] == 0 && visited[Y][X][block] == false) {
					dist[Y][X][block] = dist[y][x][block] + 1;
					visited[Y][X][block] = true;
					q.push({ { Y,X },block });
				}

				//�� �� ���� ���̰�, ���� ���� �� ���� ��
				if ((map[Y][X] == 1) && (block == 0)) {
					dist[Y][X][block + 1] = dist[y][x][block] + 1;
					visited[Y][X][block + 1] = true; //���� �� �湮
					q.push({ { Y,X },block + 1 });
				}
				
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < m; j++) {
			map[i][j] = num[j] - '0';
		}
	}

	cout<<bfs();
	
	return 0;
}