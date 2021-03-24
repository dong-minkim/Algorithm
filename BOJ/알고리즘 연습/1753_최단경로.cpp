#include<iostream>
#include<vector>
#include<queue> // �켱���� ť ����ϱ� ����

using namespace std;

int V, E;
int K;
int u, v, w;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> e[20001]; //���� ����
int d[20001] = { 0, };//�ִܰŸ�

void dijkstra(int node) {


	d[node] = 0; //�����ϴ� ���� �ִܰŸ� 0
	pq.push(make_pair(0, node));

	while (!pq.empty()) {
		int distance = -pq.top().first;
		int current = pq.top().second;//pq.top().second�� �����̴� (top���� ���� �ִܰŸ��� �̱�����)
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < e[current].size(); i++) {
			int next = e[current][i].first;
			int next_distance = distance + e[current][i].second;
			if (next_distance < d[next]) {
				d[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
	}
}

int main()
{
	cin >> V >> E;
	cin >> K;
	for (int i = 1; i <= V; i++) {
		d[i] = 1000000;
	}
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		e[u].push_back(make_pair(v, w)); //u���� v ���� ����ġ�� w
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (d[i] == 1000000) cout << "INF" << '\n';
		else {
			cout << d[i] << '\n';
		}
	}

	return 0;
}