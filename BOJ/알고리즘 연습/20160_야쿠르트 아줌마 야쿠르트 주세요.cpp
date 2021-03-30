#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;

typedef long long ll;
const ll INF = 1e15;
vector<pair<long long , long long>> edge[100001];

ll V, E;
ll u, v, w;
ll prev_dist, prev_node;
priority_queue<pair<long long, long long>> pq;

vector<ll> dijkstra(ll prev, ll node) {
	vector<ll> dist(V + 1, INF);
	dist[node] = prev;

	pq.push(make_pair(-dist[node], node));

	while (!pq.empty()) {
		ll distance = -pq.top().first;
		ll current = pq.top().second;
		pq.pop();

		if (dist[current] < distance) continue;
		for (int i = 0; i < edge[current].size(); i++) {
			ll next = edge[current][i].first;
			ll nextdistance = edge[current][i].second;

			if (dist[next] > dist[current] + nextdistance) {
				dist[next] = dist[current] + nextdistance;
				pq.push({ -dist[next],next });
			}
		}
	}

	return dist;

}
int main()
{
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(v, w));
		edge[v].push_back(make_pair(u, w));
	}

	pair<ll, ll> node[10] = { {0,0}, };
	for (int i = 0; i < 10; i++) {
		cin >> node[i].first;

		if (i == 0) {
			prev_dist = 0;
			prev_node = node[i].first;
			continue;
		}

		vector<ll> dist = dijkstra(prev_dist, prev_node);
		if (dist[node[i].first] != INF) {
			prev_dist = dist[node[i].first]; 
			prev_node = node[i].first;
		}
		node[i].second = dist[node[i].first];
	}

	ll start;
	ll answer = V + 1;

	cin >> start;

	vector<ll> v = dijkstra(0, start);

	//���� �����ϴ� �ð��� �߱���Ʈ ���ܸ����� ���ų� ������ ��带 �ִ´�.
	//���� ���� ���� ��ȣ�� ����ؾ� �ϹǷ� ���ؼ� �� �������� �ִ´�.
	for (int i = 0; i < 10; i++) {
		if (node[i].second == INF)continue;
		if (node[i].second >= v[node[i].first]) {
			answer = min(answer, node[i].first);
		}
	}
	//���� ������ -1���
	if (answer == V + 1)cout << -1;
	else cout << answer;

	return 0;
}
