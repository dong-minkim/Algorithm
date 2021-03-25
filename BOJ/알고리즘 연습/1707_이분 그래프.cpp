#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int v, e;
vector<int> arr[20001];
int colored[20001] = { 0, };
int a, b;

int dfs(int v, int color) {
	colored[v] = color;

	for (int i = 0; i < arr[v].size(); i++) {
		int next = arr[v][i];

		if (!colored[next]) {
			//3-color: ���� ������ 1�̸�2 2�̸�1�� �ٸ� ������ ĥ�ϱ� ����.
			//!dfs()�� ����: ��ͷ� �� �̺б׷����� �ƴ϶�� �̰� �����.
			if (!dfs(next, 3 - color)) return false;
		}
		//������ ĥ�� ���� ���� ���� ���ٸ� �̺б׷����� �ƴϴ�.
		else if (colored[next] == colored[v]) return false;
	}
	//���� ������ �� ����ϸ� �̺б׷����̴�.
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		
		cin >> v >> e;

		//���� ����ŭ ��� ������ reset
		for (int i = 0; i <= v; i++) {
			arr[i].clear();
			colored[i] = 0;
		}
		
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		//�̺�Ž���� ������ ��尡 �ٸ� ���� (1, 2)�� ĥ�� �� ������ �ȴ�.
		for(int i=1;i<=v;i++){
			if (!colored[i]) {
				//ó�� ���� 1�� ����.
				if (dfs(i, 1) == false) {
					cout << "NO" << '\n';
					break;
				}
				else cout << "YES" << '\n';
			}
		}
	

	}
	return 0;
}