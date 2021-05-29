#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int V, E;
int A, B, C;

vector<pair<int, int>> edge[10001];
priority_queue<pair<int, int>> pq;
bool visited[10001] = { false, };
int answer = 0;

void Prim(int start) {
	pq.push({ 0,start });
	while (!pq.empty()) {
		int now = pq.top().second; //���� ����
		int min_edge = -pq.top().first; //���� ª�� ����
		pq.pop();

		if (visited[now])continue; //�湮������ �н�

		visited[now] = true; //������ ��ũ
		answer += min_edge; //���õ� ª�� ������ �����ش�.

		for (int i = 0; i < edge[now].size(); i++) { //���� ������ ����� �ִ� ���� �ִ´�.
			if (visited[edge[now][i].first]) continue;
			pq.push({ -edge[now][i].second , edge[now][i].first});
		}
	}
}

int main()
{
	cin >> V >> E;
	
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		edge[A].push_back({ B,C });
		edge[B].push_back({ A,C });
	}

	Prim(1);
	cout << answer << '\n';
	return 0;
}